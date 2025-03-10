#include "vector3d.h"
#include "math.h"
#include "raylib.h"

static void Vector3D_draw(Vector3D vec);
static float Vector3D_magnitude(Vector3D vec);
static void Vector3D_addition(Vector3D *vec_a, Vector3D vec_b);
static void Vector3D_subtraction(Vector3D *vec_a, Vector3D vec_b);
static void Vector3D_scale(Vector3D *vec, float n);
static float Vector3D_dot_product(Vector3D vec_a, Vector3D vec_b);
static Vector3D Vector3D_cross_product(Vector3D vec_a, Vector3D vec_b);
void Vector3D_normalize(Vector3D *vec);
static Vector3D Vector3D_unit_vector(Vector3D vec);

Vector3D Vector3D_init(float x, float y, float z) {
  Vector3D vec2 = {
      .x = x,
      .y = y,
      .z = z,
      .draw = &Vector3D_draw,
      .magnitude = &Vector3D_magnitude,
      .add = &Vector3D_addition,
      .sub = &Vector3D_subtraction,
      .scale = &Vector3D_scale,
      .normalize = &Vector3D_normalize,
      .unit_vector = &Vector3D_unit_vector,
      .dot_product = &Vector3D_dot_product,
      .cross_product = &Vector3D_cross_product,
  };

  return vec2;
}

// TODO: return here in the future
static void Vector3D_draw(Vector3D vec) {
  //
  Vector3 center = {
      .x = vec.x,
      .y = vec.y,
      .z = vec.z,
  };

  DrawCircle3D(center, 50, center, 0, BLUE);
}

// calculo do comprimento de um vetor de um ponto ao outro
static float Vector3D_magnitude(Vector3D vec) {
  return sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

// resultado do "movimento" do vetor A e B
static void Vector3D_addition(Vector3D *vec_a, Vector3D vec_b) {
  vec_a->x += vec_b.x;
  vec_a->y += vec_b.y;
  vec_a->z += vec_b.z;
}

// resultado do "movimento" de A + (-B)
// a - b = (a1 - b1, a2 - b2)
// com isso é possivel pegar a distancia de A até B
static void Vector3D_subtraction(Vector3D *vec_a, Vector3D vec_b) {
  vec_a->x -= vec_b.x;
  vec_a->y -= vec_b.y;
  vec_a->z -= vec_b.z;
}

// escala o vetor por um número
// a escala pode aumentar o tamanho do vetor, aumentar, diminuir ou refletir
static void Vector3D_scale(Vector3D *vec, float n) {
  vec->x *= n;
  vec->y *= n;
  vec->z *= n;
}

// a projeção de um vetor no outro
static float Vector3D_dot_product(Vector3D vec_a, Vector3D vec_b) {
  return ((vec_a.x * vec_b.x) + (vec_a.y * vec_b.y) * (vec_a.z * vec_b.z));
}

// if we want to get the length, its A * B * sin(angle between A and B)
static Vector3D Vector3D_cross_product(Vector3D vec_a, Vector3D vec_b) {
  // As we dont have an vector 3d, z in A and B will be 0
  float x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
  float y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
  float z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;

  Vector3D vec = Vector3D_init(x, y, z);
  return vec;
}

void Vector3D_normalize(Vector3D *vec) {
  float len = vec->magnitude(*vec);
  vec->x /= len;
  vec->y /= len;
  vec->z /= len;
}

static Vector3D Vector3D_unit_vector(Vector3D vec) {
  float len = vec.magnitude(vec);
  float x = vec.x / len;
  float y = vec.y / len;
  float z = vec.z / len;

  Vector3D unit_vector = Vector3D_init(x, y, z);
  return unit_vector;
}
