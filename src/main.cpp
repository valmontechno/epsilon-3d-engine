#include "eadkpp.h"
#include "rietveld.h"
#include "mondrian.h"
#include "vMaths.h"

using namespace EADK;
using namespace mondrian;

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "3D Engine";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

  Tri3 triangle(
    Vec3(-0.5f, -0.5f, 0.0f),
    Vec3(0.5f, -0.5f, 0.0f),
    Vec3(0.0f, 0.5f, 0.0f)
  );

  Tri3 mesh[] = {triangle};

  Keyboard::State keyState = Keyboard::scan();

  Camera camera(Vec3(0.0f, 0.0f, -1.0f), 0.0f, 0.0f, 1.0f);

  float t = 0.0f;

  while (! (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Back))) {
    keyState = Keyboard::scan();

    clear();

    camera.pushMesh(mesh, 1, 0b11100101);

    draw();

    t += 0.01f;
  }

  do {
     keyState = Keyboard::scan();
  } while (keyState.keyDown(Keyboard::Key::Home) || keyState.keyDown(Keyboard::Key::Back));

  return 0;
}