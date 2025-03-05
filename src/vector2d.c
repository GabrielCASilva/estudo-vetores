#include "vector2d.h"
#include "raylib.h"
#include <math.h>

static void Vector2D_draw(Vector2D vec);
static float Vector2D_magnitude(Vector2D vec);
static void Vector2D_addition(Vector2D *vec_a, Vector2D vec_b);
static void Vector2D_subtraction(Vector2D *vec_a, Vector2D vec_b);
static void Vector2D_scale(Vector2D *vec, float n);
static float Vector2D_dot_product(Vector2D vec_a, Vector2D vec_b);

Vector2D Vector2D_init(float x, float y) {
  Vector2D vec2 = {
      .x = x,
      .y = y,
      .draw = &Vector2D_draw,
      .magnitude = &Vector2D_magnitude,
      .add = &Vector2D_addition,
      .sub = &Vector2D_subtraction,
      .scale = &Vector2D_scale,
  };

  return vec2;
}

static void Vector2D_draw(Vector2D vec) {
  //
  DrawLine(0, 0, vec.x, vec.y, GREEN);
  DrawCircle(vec.x, vec.y, 5, RED);
}

// calculo do comprimento de um vetor de um ponto ao outro
// a comprimento do vetor sempre será positivo
static float Vector2D_magnitude(Vector2D vec) {
  // teorema de pitágoras com vetores
  return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

// resultado do "movimento" do vetor A e B
// a + b = (a1 + b1, a2 + b2)
static void Vector2D_addition(Vector2D *vec_a, Vector2D vec_b) {
  vec_a->x += vec_b.x;
  vec_a->y += vec_b.y;
}

// resultado do "movimento" de A + (-B)
// a - b = (a1 - b1, a2 - b2)
// com isso é possivel pegar a distancia de A até B
static void Vector2D_subtraction(Vector2D *vec_a, Vector2D vec_b) {
  vec_a->x -= vec_b.x;
  vec_a->y -= vec_b.y;
}

// escala o vetor por um número
// a escala pode aumentar o tamanho do vetor, aumentar, diminuir ou refletir
static void Vector2D_scale(Vector2D *vec, float n) {
  vec->x *= n;
  vec->y *= n;
}

// a projeção de um vetor no outro
// essa projeção resulta numa escala
// essa escala diz o quão alinhada estão esses vetores
// mesmo setido -> (+)
// dois perpendiculares (90 graus) -> 0,
// sentido oposto -> (-)
static float Vector2D_dot_product(Vector2D vec_a, Vector2D vec_b) {
  return ((vec_a.x * vec_b.x) + (vec_a.y * vec_b.y));
}
