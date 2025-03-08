#include "vector2d.h"
#include "raylib.h"
#include <math.h>

static void Vector2D_draw(Vector2D vec);
static float Vector2D_magnitude(Vector2D vec);
static void Vector2D_addition(Vector2D *vec_a, Vector2D vec_b);
static void Vector2D_subtraction(Vector2D *vec_a, Vector2D vec_b);
static void Vector2D_scale(Vector2D *vec, float n);
static float Vector2D_dot_product(Vector2D vec_a, Vector2D vec_b);
static Vector2D Vector2D_perpendicular(Vector2D vec_a);
void Vector2D_normalize(Vector2D *vec);
static Vector2D Vector2D_unit_vector(Vector2D vec);
Vector2D Vector2D_rotate(Vector2D vec, float angle);

Vector2D Vector2D_init(float x, float y) {
  Vector2D vec2 = {
      .x = x,
      .y = y,
      .draw = &Vector2D_draw,
      .magnitude = &Vector2D_magnitude,
      .add = &Vector2D_addition,
      .sub = &Vector2D_subtraction,
      .scale = &Vector2D_scale,
      .rotate = &Vector2D_rotate,
      .normalize = &Vector2D_normalize,
      .unit_vector = &Vector2D_unit_vector,
      .dot_product = &Vector2D_dot_product,
      .perpendicular = &Vector2D_perpendicular,
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

static Vector2D Vector2D_perpendicular(Vector2D vec_a) {
  // it's negative for the sake of screen space
  Vector2D vec = Vector2D_init(vec_a.y, -vec_a.x);
  return vec;
}

void Vector2D_normalize(Vector2D *vec) {
  float len = vec->magnitude(*vec);
  vec->x /= len;
  vec->y /= len;
}

static Vector2D Vector2D_unit_vector(Vector2D vec) {
  float len = vec.magnitude(vec);
  float x = vec.x / len;
  float y = vec.y / len;

  Vector2D unit_vector = Vector2D_init(x, y);
  return unit_vector;
}

Vector2D Vector2D_rotate(Vector2D vec, float angle) {
  float x = vec.x * cos(angle) - vec.y * sin(angle);
  float y = vec.x * sin(angle) + vec.y * cos(angle);

  Vector2D new_vec = Vector2D_init(x, y);
  return new_vec;
}
