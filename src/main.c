#include "macros.h"
#include "raylib.h"
#include "stdio.h"
#include "vector2d.h"

void setup(void);
void loop(void);
void draw(void);

static Vector2D position;
static Vector2D velocity;

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Template");
  setup();

  float dt = 0.0f;
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    dt += GetFrameTime();
    // GameLoop
    loop();

    // Drawing Textures
    draw();
  }

  CloseWindow();
  return 0;
}

void setup(void) {
  //
  position = Vector2D_init(1, 1);
  velocity = Vector2D_init(1.6, 1.6);
}

void loop(void) {
  float mag_pos = position.magnitude(position);
  float mag_vel = velocity.magnitude(velocity);
  printf("magnitude position: [%.2f], velocity: [%.2f]\n", mag_pos, mag_vel);
  position.add(&position, velocity);
  velocity.scale(&velocity, .99);
}

void draw(void) {
  BeginDrawing();
  ClearBackground(BLACK);
  position.draw(position);
  EndDrawing();
}
