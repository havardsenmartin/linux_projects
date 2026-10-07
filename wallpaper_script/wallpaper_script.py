import os
import requests

QUERY = "studio ghibli"
FILENAME_QUERY = QUERY.replace(" ", "_")
NUM_WALLPAPERS = 50
SAVE_FOLDER = "wallpapers"

os.makedirs(SAVE_FOLDER, exist_ok=True)

url = "https://wallhaven.cc/api/v1/search"

params = {
    "q": QUERY,
    "purity": "100",          # SFW
    "sorting": "favorites",
    "resolutions": "2560x1440"
}

response = requests.get(url, params=params)
data = response.json()

wallpapers = data["data"][:NUM_WALLPAPERS]

for i, wallpaper in enumerate(wallpapers):
    image_url = wallpaper["path"]

    print(f"Downloading: {image_url}")

    img = requests.get(image_url).content

    filename = os.path.join(
        SAVE_FOLDER,
        f"wallpaper_{FILENAME_QUERY}_{i+1}.jpg"
    )

    with open(filename, "wb") as f:
        f.write(img)

print("Finished!")
