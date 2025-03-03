#ifndef VECTOR2D_H
#define VECTOR2D_H

struct vector2d {
  int x; //< eixo x
  int y; //< eixo y
  void (*loop)(struct vector2d *self);
  void (*draw)(struct vector2d self);
  float (*magnitude)(struct vector2d self);
};

typedef struct vector2d Vector2D;

Vector2D Vector2D_init(void);
#endif // !VECTOR2D_H
