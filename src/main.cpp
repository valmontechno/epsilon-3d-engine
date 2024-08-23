#include "eadkpp.h"
#include "graphics.h"
#include "vMaths.h"

using namespace EADK;
using namespace graphics;

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "3D Engine";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

  Tri2 triangle(
    Vec2(-0.5f, -0.5f),
    Vec2(0.5f, -0.5f),
    Vec2(0.0f, 0.5f)
  );

  Keyboard::State keyState = Keyboard::scan();

  while (! (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Back))) {
    keyState = Keyboard::scan();

    clear();

    putTriangle(triangleToScreen(triangle), 0b11100101);

    draw();
  }

  do {
     keyState = Keyboard::scan();
  } while (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Back));

  return 0;
}