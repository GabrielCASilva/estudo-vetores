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
};

typedef struct vector2d Vector2D;

Vector2D Vector2D_init(float x, float y);
#endif // !VECTOR2D_H
