// Gerrit Rietveld

#ifndef RIETVELD_H
#define RIETVELD_H

#include "eadkpp.h"
#include "vMaths.h"

using namespace EADK;

class Camera {
    public:
    Vec3 position;
    float pitch, yaw;
    float focalLenth;

    Camera(Vec3 position, float pitch, float yaw, float focalLenth = 1.0f);

    void pushTriangle(Tri3 tri, uint8_t color);
    void pushMesh(Tri3 mesh[], size_t size, uint8_t color);

    private:
    Vec2 vectorProjection(Vec3 v);
    Tri2 triangleProjection(Tri3 tri);

    Vec2 vectorToScreen(Vec2 v);
    Tri2 triangleToScreen(Tri2 tri);
};

#endif