#include "macros.h"
#include "raylib.h"
#include "stdio.h"
#include "vector2d.h"

void setup(void);
void loop(void);
void draw(void);

static Camera2D camera = {0};
static Vector2D position;
static Vector2D velocity;
static Vector2D rotate_position;
static float angle;

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
  angle = 0;
  position = Vector2D_init(60, 60);
  velocity = Vector2D_init(1.6, 1.6);

  // camera
  camera.offset = (Vector2){WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
  camera.rotation = 0.5f;
  camera.zoom = 1.0f;
}

void loop(void) {
  float mag_pos = position.magnitude(position);
  rotate_position = position.rotate(position, angle);
  /*position.add(&position, rotation);*/
  angle += 3.14f / 12;
  float mag_vel = velocity.magnitude(velocity);
  printf("magnitude position: [%.2f], velocity: [%.2f]\n", mag_pos, mag_vel);
  position.add(&position, velocity);
  velocity.scale(&velocity, .99);
}

void draw(void) {
  BeginDrawing();
  ClearBackground(BLACK);

  BeginMode2D(camera);
  rotate_position.draw(rotate_position);
  EndMode2D();

  EndDrawing();
}
