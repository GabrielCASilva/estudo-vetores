#ifndef VECTOR2D_H
#define VECTOR2D_H

struct vector2d {
  float x; //< eixo x
  float y; //< eixo y
  void (*draw)(struct vector2d self);
  float (*magnitude)(struct vector2d self);
  void (*add)(struct vector2d *self, struct vector2d other);
  void (*sub)(struct vector2d *self, struct vector2d other);
  void (*scale)(struct vector2d *self, float n);
  struct vector2d (*rotate)(struct vector2d self, float angle);
  void (*normalize)(struct vector2d *self);
  struct vector2d (*unit_vector)(struct vector2d self);
  float (*dot_product)(struct vector2d self, struct vector2d other);
  struct vector2d (*perpendicular)(struct vector2d self);
};

typedef struct vector2d Vector2D;

Vector2D Vector2D_init(float x, float y);
#endif // !VECTOR2D_H
