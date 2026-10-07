#include "raylib.h"
#include <math.h>
#include <node.h>
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

/*
int comparator1(const void *a, const void *b) {
  size_t la = strlen((const char *)a);
  size_t lb = strlen((const char *)b);

  if (la > lb)
    return 1;
  if (la < lb)
    return -1;
  return 0;
}
void printer1(const void *value) { printf("%s\n", (const char *)value); }
/*

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

// subtracts
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

float Vector2Length(const Vector2 v) { return sqrt(v.x * v.x + v.y * v.y); }

Vector2 get_vector_to_weight(const float angle, const float length) {
  Vector2 vector_out = {0, 0};
  vector_out.y = cos(angle);
  vector_out.x = sin(angle);
  vector_out = Vector2Scale(vector_out, length);
  // printf("angle: %f\n", angle);
  // printf("x: %f; y: %f\n", vector_out.x, vector_out.y);
  return vector_out;
}

#define DEFAULT_PENDULUM_ANCHOR_COLOR (Color){0, 255, 0, 255}
#define DEFAULT_PENDULUM_LINE_COLOR (Color){255, 0, 0, 255}
#define DEFAULT_PENDULUM_WEIGHT_COLOR (Color){255, 255, 0, 255}

typedef struct {
  float x;  // $ r_x $
  float y;  // $ r_y $
  float xd; // $ dot(r)_x $
  float yd; // $ dot(r)_y $
} State;

// Vector2 to_screen_coords(Vector2 v) { return (Vector2){v.y, v.x}; }

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define CONSTANT_B 0.1 // k_resistance/mass
// Note that a higher value will dampen pendulum more
#define GRAV_ACCEL_G 9.81 // m/s/s
#define PENDULUM_LENGTH 2 // meters
#define METER2PIXEL 100.0f
#define PIXEL2METER 0.01f

void draw_pendulum(Vector2 pendulum_position, const State state) {
  Vector2 weight_position = {state.x, state.y};
  weight_position = Vector2Scale(weight_position, METER2PIXEL);

  pendulum_position = Vector2Scale(pendulum_position, METER2PIXEL);

  // Vector2 weight_position_screen = to_screen_coords(weight_position);
  // printf("x: %f; y: %f\n", weight_position.x, weight_position.y);
  DrawCircleV(pendulum_position, 5, DEFAULT_PENDULUM_ANCHOR_COLOR);
  DrawLineV(pendulum_position, weight_position, DEFAULT_PENDULUM_LINE_COLOR);
  DrawCircleV(weight_position, 10, DEFAULT_PENDULUM_WEIGHT_COLOR);
  return;
}

float state_get_l(Vector2 pendulum_position, Vector2 weight_position) {
  const Vector2 pend2weight =
      Vector2Subtract(weight_position, pendulum_position);
  return Vector2Length(pend2weight);
}

State state_screen2space(const State state, const Vector2 pendulum_pos) {
  return (State){state.y - pendulum_pos.y, state.x - pendulum_pos.x, state.yd,
                 state.xd};
}

State state_space2screen(const State state, const Vector2 pendulum_pos) {
  return (State){state.y + pendulum_pos.x, state.x + pendulum_pos.y, state.yd,
                 state.xd};
}

static inline float maxf(float a, float b) { return a > b ? a : b; }

State get_next_state(const State state, const Vector2 pendulum_pos,
                     const float dt) {
  /*
   * uses Euler's method (semi-implicit version for stability) to solve
   * the differential equation
   * describing the pendulum
   */

  State next_state = {1, 0, 0, 0};

  // change from screen coords to coords used in derivation
  const float rx = state.y - pendulum_pos.y;
  const float ry = state.x - pendulum_pos.x;
  const float rxd = state.yd;
  const float ryd = state.xd;

  float l = sqrt(rx * rx + ry * ry);
  const float abs_v = sqrt(rxd * rxd + ryd * ryd);

  if (l == 0) {
    printf("l==0\n");
    l = maxf(l, 1e-6f);
  }

  const float k = 40.7f;
  const float m = 10.0f;
  const float g = 9.81f;
  const float h = (50.0f) * PIXEL2METER;
  const float kappa = 0.1f;

  const float k_over_m = k / m;
  const float kappa_over_m = kappa / m;

  const float ax =
      -k_over_m * (rx - h * rx / l) - kappa_over_m * (abs_v)*rxd + g;
  const float ay = -k_over_m * (ry - h * ry / l) - kappa_over_m * (abs_v)*ryd;

  const float new_rxd = rxd + dt * ax;
  const float new_ryd = ryd + dt * ay;
  const float new_rx = rx + dt * new_rxd;
  const float new_ry = ry + dt * new_ryd;

  next_state.xd = new_ryd;
  next_state.yd = new_rxd;
  next_state.x = new_ry + pendulum_pos.x;
  next_state.y = new_rx + pendulum_pos.y;

  return next_state;
}

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib test");

  Vector2 pendulum_pos = {((float)WINDOW_WIDTH / 2) * PIXEL2METER,
                          ((float)WINDOW_HEIGHT / 4) * PIXEL2METER};
  // defining inital state
  State pendulum_state = {
      pendulum_pos.x - 200 * PIXEL2METER,
      pendulum_pos.y - 200 * PIXEL2METER,
      10,
      -1,
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_pendulum(pendulum_pos, pendulum_state);
    pendulum_state =
        get_next_state(pendulum_state, pendulum_pos, GetFrameTime());
    DrawText("Hello raylib", 200, 200, 20, BLACK);
    EndDrawing();

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      // triggered once when clicked
      Vector2 mouse_pos = GetMousePosition();
      pendulum_pos.x = mouse_pos.x * PIXEL2METER;
      pendulum_pos.y = mouse_pos.y * PIXEL2METER;
    }

    // WaitTime(0.05);

    // E_"kinetic"   = 0.5 * L^2 * omega^2
    // E_"potential" = g * L * (1 - cos(theta))
    // E             = 0.5 * L^2 * omega^2 + g * L * (1 - cos(theta))
  }

  CloseWindow();
  return 0;
}
