#include "macros.h"
#include "raylib.h"
#include "vector2d.h"

void setup(void);
void loop(void);
void draw(void);

static Vector2D vec2;

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
  vec2 = Vector2D_init();
}

void loop(void) {
  //
  vec2.loop(&vec2);
}

void draw(void) {
  BeginDrawing();
  ClearBackground(BLACK);
  vec2.draw(vec2);
  EndDrawing();
}
