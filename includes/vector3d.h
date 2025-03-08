#ifndef VECTOR_3D_H
#define VECTOR_3D_H

struct vector3d {
  float x; //< eixo x
  float y; //< eixo y
  float z; //< eixo z
  void (*draw)(struct vector3d self);
  float (*magnitude)(struct vector3d self);
  void (*add)(struct vector3d *self, struct vector3d other);
  void (*sub)(struct vector3d *self, struct vector3d other);
  void (*scale)(struct vector3d *self, float n);
  void (*normalize)(struct vector3d *self);
  struct vector3d (*unit_vector)(struct vector3d self);
  float (*dot_product)(struct vector3d self, struct vector3d other);
  struct vector3d (*cross_product)(struct vector3d self, struct vector3d other);
};

typedef struct vector3d Vector3D;

Vector3D Vector3D_init(float x, float y, float z);

#endif // !VECTOR_3D_H
