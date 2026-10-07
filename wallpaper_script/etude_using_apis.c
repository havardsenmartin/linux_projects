#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct Memory {
    char *data;
    size_t size;
};

size_t write_to_memory(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;

    struct Memory *mem = (struct Memory *)userp;

    mem->data = realloc(mem->data, mem->size + total + 1);

    memcpy(&(mem->data[mem->size]), contents, total);

    mem->size += total;
    mem->data[mem->size] = 0;

    return total;
}

size_t write_file(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main() {
    CURL *curl;
    CURLcode res;

    struct Memory response;
    response.data = malloc(1);
    response.size = 0;

    char query[] = "fantasy";

    char url[512];

    sprintf(
        url,
        "https://wallhaven.cc/api/v1/search?q=%s",
        query
    );

    curl = curl_easy_init();

    if (!curl) {
        return 1;
    }

    // Download JSON response
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_memory);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        printf("Request failed\n");
        return 1;
    }

    // Very crude JSON parsing
    char *path_start = strstr(response.data, "\"path\":\"");

    if (!path_start) {
        printf("No image found\n");
        return 1;
    }

    path_start += 8;

    char image_url[512];

    int i = 0;

    while (*path_start && *path_start != '"') {
        image_url[i++] = *path_start++;
    }

    image_url[i] = '\0';

    printf("Image URL:\n%s\n", image_url);

    // Download image
    FILE *fp = fopen("wallpaper.jpg", "wb");

    curl_easy_setopt(curl, CURLOPT_URL, image_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);

    fclose(fp);

    if (res != CURLE_OK) {
        printf("Image download failed\n");
    } else {
        printf("Saved as wallpaper.jpg\n");
    }

    curl_easy_cleanup(curl);

    free(response.data);

    return 0;
}
