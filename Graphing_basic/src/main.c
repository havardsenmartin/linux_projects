#include "raylib.h"
#include <math.h>
#include <stdbool.h>

#define e 0.5772156649f
// #include <stdlib.h>
// #include <string.h>

/*
Raylib 2D Drawing Functions

-------------------------
LINES
-------------------------
DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
DrawLineV(Vector2 startPos, Vector2 endPos, Color color);
DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
DrawLineStrip(Vector2 *points, int pointCount, Color color);

-------------------------
POINTS / PIXELS
-------------------------
DrawPixel(int posX, int posY, Color color);
DrawPixelV(Vector2 position, Color color);

-------------------------
CIRCLES
-------------------------
DrawCircle(int centerX, int centerY, float radius, Color color);
DrawCircleV(Vector2 center, float radius, Color color);
DrawCircleLines(int centerX, int centerY, float radius, Color color);
DrawCircleLinesV(Vector2 center, float radius, Color color);
DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle,
int segments, Color color); DrawCircleSectorLines(Vector2 center, float radius,
float startAngle, float endAngle, int segments, Color color);
DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color
color2);

-------------------------
RECTANGLES / SQUARES
-------------------------
DrawRectangle(int posX, int posY, int width, int height, Color color);
DrawRectangleV(Vector2 position, Vector2 size, Color color);
DrawRectangleRec(Rectangle rec, Color color);
DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);

DrawRectangleLines(int posX, int posY, int width, int height, Color color);
DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color);
DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);
DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, float
lineThick, Color color);

DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1,
Color color2); DrawRectangleGradientH(int posX, int posY, int width, int height,
Color color1, Color color2); DrawRectangleGradientEx(Rectangle rec, Color
topLeft, Color bottomLeft, Color topRight, Color bottomRight);

-------------------------
TRIANGLES
-------------------------
DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
DrawTriangleFan(Vector2 *points, int pointCount, Color color);
DrawTriangleStrip(Vector2 *points, int pointCount, Color color);

-------------------------
TEXT (useful for debugging)
-------------------------
DrawText(const char *text, int posX, int posY, int fontSize, Color color);
DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float
spacing, Color color); DrawTextPro(Font font, const char *text, Vector2
position, Vector2 origin, float rotation, float fontSize, float spacing, Color
color);
*/
Vector2 Vector2Subtract(const Vector2 v1, const Vector2 v2) {
  /*
   * Subtracts `v2` from v1. returns v1-v2
   */
  return (Vector2){v1.x - v2.x, v1.y - v2.y};
}

Vector2 Vector2Add(const Vector2 v1, const Vector2 v2) {
  /*
   * Adds `v2` to v1. returns v1+v2
   */
  return (Vector2){v1.x + v2.x, v1.y + v2.y};
}

Vector2 Vector2Scale(const Vector2 v1, const float scalar) {
  return (Vector2){v1.x * scalar, v1.y * scalar};
}

Vector2 get_vector_to_weight(const float angle, const float length) {
  Vector2 vector_out = {0, 0};
  vector_out.y = cos(angle);
  vector_out.x = sin(angle);
  vector_out = Vector2Scale(vector_out, length);
  // printf("angle: %f\n", angle);
  // printf("x: %f; y: %f\n", vector_out.x, vector_out.y);
  return vector_out;
}

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GRAV_ACCEL_G 9.81 // m/s/s
#define METER2PIXEL 100.0f

typedef struct {
  Vector2 (*function)(const float);
  float a;
  float b;
} Curve;

Vector2 butterfly_curve_function(const float t) {
  return (Vector2){.y = cosf(t) * (expf(cosf(t)) - 2.0f * cosf(4.0f * t) -
                                   powf(sinf(t / 12.0f), 5.0f)),
                   .x = sinf(t) * (expf(cosf(t)) - 2.0f * cosf(4.0f * t) -
                                   powf(sinf(t / 12.0f), 5.0f))};
}

Vector2 curve2_function(const float t) {
  return (Vector2){.x = cos(3 * t), .y = sin(5 * t)};
}

Vector2 transform_to_screen(Vector2 v, const Vector2 origin,
                            const float pixel_per_unit) {
  v = Vector2Scale(v, pixel_per_unit);
  v = Vector2Add(v, origin);
  v.y = WINDOW_HEIGHT - v.y;
  return v;
}

/*
 *  Amount of iterations vary.
 *  Disconnected
 */
void curve_draw(const Curve C, const Vector2 origin, const float step_size,
                const float pixel_per_unit) {
  Color color = RED;
  float tmax = C.a;
  for (float t = C.a + step_size; t <= C.b; t += step_size) {
    Vector2 first = C.function(t - step_size);
    Vector2 second = C.function(t);

    first = transform_to_screen(first, origin, pixel_per_unit);
    second = transform_to_screen(second, origin, pixel_per_unit);

    DrawLineV(first, second, color);
    if (t > tmax)
      tmax = t;
  }
  return;
}

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib test");

  Curve curve1 = {.function = butterfly_curve_function, .a = 0, .b = 10000};

  Curve curve2 = {.function = curve2_function, .a = 0, .b = 2 * PI};

  Vector2 origin = {(float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2};

  bool refresh = true;

  RenderTexture2D canvas = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

  while (!WindowShouldClose()) {
    BeginDrawing();
    if (refresh) {
      BeginTextureMode(canvas);
      ClearBackground(RAYWHITE);

      DrawText("BUTTERFLY <3", 200, 200, 20, BLACK);
      curve_draw(curve1, origin, 0.001, (float)WINDOW_HEIGHT / 8);

      EndTextureMode();

      refresh = false;
    }

    DrawTextureRec(
        canvas.texture,
        (Rectangle){0, 0, canvas.texture.width, -canvas.texture.height},
        (Vector2){0, 0}, WHITE);

    // E_"kinetic"   = 0.5 * L^2 * omega^2
    // E_"potential" = g * L * (1 - cos(theta))
    // E             = 0.5 * L^2 * omega^2 + g * L * (1 - cos(theta))
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
