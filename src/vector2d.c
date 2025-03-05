#include "vector2d.h"
#include "raylib.h"
#include <math.h>

static void Vector2D_draw(Vector2D vec2);
static float Vector2D_magnitude(Vector2D vec2);
static void Vector2D_addition(Vector2D *vec2_a, Vector2D vec2_b);
static void Vector2D_subtraction(Vector2D *vec2_a, Vector2D vec2_b);

Vector2D Vector2D_init(void) {
  Vector2D vec2 = {
      .x = 0,
      .y = 0,
      .draw = &Vector2D_draw,
      .magnitude = &Vector2D_magnitude,
      .add = &Vector2D_addition,
      .sub = &Vector2D_subtraction,
  };

  return vec2;
}

static void Vector2D_draw(Vector2D vec2) {
  //
  DrawLine(0, 0, vec2.x, vec2.y, GREEN);
  DrawCircle(vec2.x, vec2.y, 5, RED);
}

// calculo do comprimento de um vetor de um ponto ao outro
// a comprimento do vetor sempre será positivo
static float Vector2D_magnitude(Vector2D vec2) {
  // teorema de pitágoras com vetores
  return sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y));
}

// resultado do "movimento" do vetor A e B
// a + b = (a1 + b1, a2 + b2)
static void Vector2D_addition(Vector2D *vec2_a, Vector2D vec2_b) {
  vec2_a->x += vec2_b.x;
  vec2_a->y += vec2_b.y;
}

// resultado do "movimento" de A + (-B)
// a - b = (a1 - b1, a2 - b2)
static void Vector2D_subtraction(Vector2D *vec2_a, Vector2D vec2_b) {
  vec2_a->x -= vec2_b.x;
  vec2_a->y -= vec2_b.y;
}
