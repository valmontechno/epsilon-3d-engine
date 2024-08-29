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
    float zNear;

    Camera(Vec3 position, float pitch, float yaw, float focalLenth, float zNear);

    Vec3 getForward() const;
    Vec3 getRight() const;
    Vec3 getLookAt() const;

    void pushMesh(const Tri3 mesh[], size_t size, uint8_t color) const;

    private:
    Vec2 vectorProjection(Vec3 v) const;
    Tri2 triangleProjection(Tri3 tri) const;

    Vec2 vectorToScreen(Vec2 v) const;
    Tri2 triangleToScreen(Tri2 tri) const;

    void pushTriangle(Tri3 tri, uint8_t color) const;
};

#endif