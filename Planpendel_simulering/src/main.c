#include "raylib.h"
#include <math.h>
#include <node.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define DEFAULT_PENDULUM_ANCHOR_COLOR (Color){0, 255, 0, 255}
#define DEFAULT_PENDULUM_LINE_COLOR (Color){255, 0, 0, 255}
#define DEFAULT_PENDULUM_WEIGHT_COLOR (Color){255, 255, 0, 255}

void draw_pendulum(Vector2 position, const float angle, const float length) {
  Vector2 position_of_weight =
      Vector2Add(get_vector_to_weight(angle, length), position);

  DrawCircleV(position, 5, DEFAULT_PENDULUM_ANCHOR_COLOR);
  DrawLineV(position, position_of_weight, DEFAULT_PENDULUM_LINE_COLOR);
  DrawCircleV(position_of_weight, 10, DEFAULT_PENDULUM_WEIGHT_COLOR);
  return;
}

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CONSTANT_B 0.1 // k_resistance/mass
// Note that a higher value will dampen pendulum more
#define GRAV_ACCEL_G 9.81 // m/s/s
#define PENDULUM_LENGTH 2 // meters
#define METER2PIXEL 100.0f

typedef struct {
  float theta;
  float theta_dot;
} State;

State get_next_state_small_angle(const State state, const float length,
                                 const float dt) {
  /*
   * uses Euler's method to solve
   * the differential equation
   * describing the pendulum
   */
  State next_state = {0, 1};
  next_state.theta = state.theta + state.theta_dot * dt;
  // theta '' = - B theta ' - g / L theta
  float angle_ddot =
      -CONSTANT_B * state.theta_dot - (GRAV_ACCEL_G / length) * state.theta;
  next_state.theta_dot = state.theta_dot + angle_ddot * dt;
  return next_state;
}

State get_next_state_standard_euler(const State state, const float length,
                                    const float dt) {
  /*
   * uses Euler's method to solve
   * the differential equation
   * describing the pendulum
   */
  State next_state = {0, 1};
  next_state.theta = state.theta + state.theta_dot * dt;
  // theta '' = - B theta ' - g / L theta
  float angle_ddot = -CONSTANT_B * state.theta_dot -
                     (GRAV_ACCEL_G / length) * (float)sin((double)state.theta);
  next_state.theta_dot = state.theta_dot + angle_ddot * dt;
  return next_state;
}

State get_next_state(const State state, const float length, const float dt) {
  /*
   * uses Euler's method (semi-implicit version for stability) to solve
   * the differential equation
   * describing the pendulum
   */
  State next_state = {0, 1};
  // theta '' = - B theta ' - g / L theta
  float angle_ddot = -CONSTANT_B * state.theta_dot -
                     (GRAV_ACCEL_G / length) * (float)sin((double)state.theta);
  next_state.theta_dot = state.theta_dot + angle_ddot * dt;
  next_state.theta = state.theta + next_state.theta_dot * dt;
  return next_state;
}

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib test");

  Vector2 pendulum_pos = {(float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2};
  // defining inital state
  State pendulum_state = {
      170 * DEG2RAD, // angle
      5              // derivative of angle (pendulum speed)
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_pendulum(pendulum_pos, pendulum_state.theta,
                  PENDULUM_LENGTH * METER2PIXEL);
    pendulum_state =
        get_next_state(pendulum_state, PENDULUM_LENGTH, GetFrameTime());
    DrawText("Hello raylib", 200, 200, 20, BLACK);
    EndDrawing();

    // E_"kinetic"   = 0.5 * L^2 * omega^2
    // E_"potential" = g * L * (1 - cos(theta))
    // E             = 0.5 * L^2 * omega^2 + g * L * (1 - cos(theta))
    printf("System energy: %f\n",
           0.5 * pow(PENDULUM_LENGTH, 2) * pow(pendulum_state.theta_dot, 2) +
               GRAV_ACCEL_G * PENDULUM_LENGTH *
                   (1 - (float)cos(pendulum_state.theta)));
  }

  CloseWindow();
  return 0;
}
