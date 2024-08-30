#include "eadkpp.h"
#include "rietveld.h"
#include "mondrian.h"
#include "vMaths.h"
#include "maths.h"

using namespace EADK;
using namespace mondrian;
using Keyboard::Key;

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "3D Engine";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

  const Vec3 vertices[] = {
    Vec3(-1.0f, -1.0f, -1.0f),
    Vec3(-1.0f, -1.0f, 1.0f),
    Vec3(-1.0f, 1.0f, -1.0f),
    Vec3(-1.0f, 1.0f, 1.0f),
    Vec3(1.0f, -1.0f, -1.0f),
    Vec3(1.0f, -1.0f, 1.0f),
    Vec3(1.0f, 1.0f, -1.0f),
    Vec3(1.0f, 1.0f, 1.0f),
  };

  const Tri3 mesh[] = {
    Tri3(vertices[2], vertices[4], vertices[0]),
    Tri3(vertices[2], vertices[6], vertices[4]),
    Tri3(vertices[6], vertices[5], vertices[4]),
    Tri3(vertices[6], vertices[7], vertices[5]),
    Tri3(vertices[7], vertices[1], vertices[5]),
    Tri3(vertices[7], vertices[3], vertices[1]),
    Tri3(vertices[3], vertices[0], vertices[1]),
    Tri3(vertices[3], vertices[2], vertices[0]),
    Tri3(vertices[3], vertices[6], vertices[2]),
    Tri3(vertices[3], vertices[7], vertices[6]),
    Tri3(vertices[0], vertices[5], vertices[1]),
    Tri3(vertices[0], vertices[4], vertices[5]),
  };

  Keyboard::State keyState = Keyboard::scan();

  Camera camera(Vec3(0.0f, 0.0f, -4.0f), 0.0f, 0.0f, 2.0f, 0.01f);

  const float speed = 2.0f;
  const float rotationSpeed = 1.0f;

  float deltaTime = 0.0f;
  float lastTime = Timing::getMillisTime();

  while (! (keyState.keyDown(Key::Home))) {
    keyState = Keyboard::scan();

    if (keyState.keyDown(Key::OK))
    {
      if (keyState.keyDown(Key::Down)) {
        camera.pitch = max(camera.pitch - rotationSpeed * deltaTime, -HALF_PI);
      }
      if (keyState.keyDown(Key::Up)) {
        camera.pitch = min(camera.pitch + rotationSpeed * deltaTime, HALF_PI);
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

    clear();

    camera.pushMesh(mesh, sizeof(mesh) / sizeof(*mesh), 0b11100101);

    draw();

    deltaTime = (Timing::getMillisTime() - lastTime) / 1000;
    lastTime = Timing::getMillisTime();
  }

  return 0;
}