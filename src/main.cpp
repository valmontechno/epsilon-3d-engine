#include "eadkpp.h"
#include "rietveld.h"
#include "mondrian.h"
#include "vMaths.h"
#include "maths.h"
#include <algorithm>

using namespace EADK;
using namespace mondrian;
using Keyboard::Key;

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "3D Engine";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

  Tri3 triangle(
    Vec3(-0.5f, -0.5f, 0.0f),
    Vec3(0.5f, -0.5f, 0.0f),
    Vec3(0.0f, 0.5f, 0.0f)
  );

  const Tri3 mesh[] = {
    Tri3(
      Vec3(-1.0f, -1.0f, 0.0f),
      Vec3(-1.0f, 1.0f, 0.0f),
      Vec3(1.0f, -1.0f, 0.0f)
    ),
    Tri3(
      Vec3(-1.0f, 1.0f, 0.0f),
      Vec3(1.0f, 1.0f, 0.0f),
      Vec3(1.0f, -1.0f, 0.0f)
    )
  };

  Keyboard::State keyState = Keyboard::scan();

  Camera camera(Vec3(0.0f, 0.0f, -2.0f), 0.0f, 0.0f, 2.0f);

  const float speed = 2.0f;
  const float rotationSpeed = 1.0f;

  float deltaTime = 0.0f;
  float lastTime = Timing::getMillisTime();

  while (! (keyState.keyDown(Key::Home) || keyState.keyDown(Key::Back))) {
    keyState = Keyboard::scan();

    if (keyState.keyDown(Key::OK))
    {
      if (keyState.keyDown(Key::Down)) {
        camera.pitch = std::max(camera.pitch - rotationSpeed * deltaTime, -HALF_PI);
      }
      if (keyState.keyDown(Key::Up)) {
        camera.pitch = std::min(camera.pitch + rotationSpeed * deltaTime, HALF_PI);
      }
      if (keyState.keyDown(Key::Left)) {
        camera.yaw += rotationSpeed * deltaTime;
      }
      if (keyState.keyDown(Key::Right)) {
        camera.yaw -= rotationSpeed * deltaTime;
      }
    }
    else
    {
      if (keyState.keyDown(Key::Down)) {
        camera.position -= camera.getForward() * speed * deltaTime;
      }
      if (keyState.keyDown(Key::Up)) {
        camera.position += camera.getForward() * speed * deltaTime;
      }
      if (keyState.keyDown(Key::Left)) {
        camera.position -= camera.getRight() * speed * deltaTime;
      }
      if (keyState.keyDown(Key::Right)) {
        camera.position += camera.getRight() * speed * deltaTime;
      }
    }
    if (keyState.keyDown(Key::Minus)) {
      camera.position.y -= speed * deltaTime;
    }
    if (keyState.keyDown(Key::Plus)) {
      camera.position.y += speed * deltaTime;
    }

    clear();;

    camera.pushMesh(mesh, 2, 0b11100101);

    draw();

    deltaTime = (Timing::getMillisTime() - lastTime) / 1000;
    lastTime = Timing::getMillisTime();
  }

  do {
     keyState = Keyboard::scan();
  } while (keyState.keyDown(Key::Home) || keyState.keyDown(Key::Back));

  return 0;
}