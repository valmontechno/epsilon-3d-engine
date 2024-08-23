#include "eadkpp.h"
#include "graphics.h"
#include "vMaths.h"

using namespace EADK;
using namespace graphics;

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "3D Engine";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int t = 0;

int main() {

  Keyboard::State keyState = Keyboard::scan();

  while (! (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Power) || keyState.keyDown(Keyboard::Key::Back))) {
    keyState = Keyboard::scan();

    clear();

    putTriangle(Tri2(Vec2(0, 0), Vec2(Screen::Width, Screen::Height/2), Vec2(t, Screen::Height)), 0b11100101);

    draw();

    t++;
  }

  do {
     keyState = Keyboard::scan();
  } while (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Power) || keyState.keyDown(Keyboard::Key::Back));

  return 0;
}