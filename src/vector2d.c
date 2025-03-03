#include "vector2d.h"
#include "raylib.h"
#include <math.h>
#include <stdio.h>

static void Vector2D_loop(Vector2D *vec2);
static void Vector2D_draw(Vector2D vec2);
static float Vector2D_magnitude(Vector2D vec2);

Vector2D Vector2D_init(void) {
  Vector2D vec2 = {.x = 20,
                   .y = 20,
                   .loop = &Vector2D_loop,
                   .draw = &Vector2D_draw,
                   .magnitude = &Vector2D_magnitude};

  return vec2;
}

static void Vector2D_loop(Vector2D *vec2) {
  int x = GetMousePosition().x;
  int y = GetMousePosition().y;
  vec2->x = x;
  vec2->y = y;

  printf("magnitude: %.2f\n", vec2->magnitude(*vec2));
}

static void Vector2D_draw(Vector2D vec2) {
  //
  DrawLine(0, 0, vec2.x, vec2.y, GREEN);
  DrawCircle(vec2.x, vec2.y, 5, RED);
}

// calculo do comprimento de um vetor de um ponto ao outro
static float Vector2D_magnitude(Vector2D vec2) {
  // teorema de pitágoras com vetores
  return sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));
}
