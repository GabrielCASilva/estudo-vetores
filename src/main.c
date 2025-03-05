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
  position = Vector2D_init();
}

void loop(void) {
  int x = GetMousePosition().x;
  int y = GetMousePosition().y;
  position.x = x;
  position.y = y;

  printf("magnitude: %.2f\n", position.magnitude(position));
}

void draw(void) {
  BeginDrawing();
  ClearBackground(BLACK);
  position.draw(position);
  EndDrawing();
}
