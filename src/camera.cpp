#include "rietveld.h"
#include "vMaths.h"
#include "maths.h"
#include "mondrian.h"

using namespace mondrian;

Camera::Camera(Vec3 position, float pitch, float yaw, float focalLenth, float zNear) {
    this->position = position;
    this->pitch = pitch;
    this->yaw = yaw;
    this->focalLenth = focalLenth;
    this->zNear = zNear;
}

Vec3 Camera::getLookAt() const {
    return Vec3(
        -sin(yaw) * cos(pitch),
        sin(pitch),
        cos(yaw) * cos(pitch)
    );
}

Vec3 Camera::getForward() const {
    return Vec3(-sin(yaw), 0.0f, cos(yaw));
}

Vec3 Camera::getRight() const {
    return Vec3(cos(yaw), 0.0f, sin(yaw));
}


void Camera::pushTriangle(Tri3 tri, uint8_t color) const {
    putTriangle(triangleToScreen(triangleProjection(tri.translate(-position).rotateY(yaw).rotateX(pitch))), color);
}

void Camera::pushMesh(const Tri3 mesh[], size_t size, uint8_t color) const {
    Vec3 planeNormal = getLookAt();
    Vec3 planePoint = position + planeNormal * zNear;

    Tri3 clippedTri[2];

    Vec3 out[3];
    Vec3 in[3];

    for (size_t i = 0; i < size; i++)
    {
        Tri3 tri = mesh[i];

        uint8_t outLength = 0;
        uint8_t inLength = 0;

        float d0 = Vec3::dot(planePoint - tri.p0, planeNormal);
        float d1 = Vec3::dot(planePoint - tri.p1, planeNormal);
        float d2 = Vec3::dot(planePoint - tri.p2, planeNormal);

        if (d0 > 0.0f) out[outLength++] = tri.p0; else in[inLength++] = tri.p0;
        if (d1 > 0.0f) out[outLength++] = tri.p1; else in[inLength++] = tri.p1;
        if (d2 > 0.0f) out[outLength++] = tri.p2; else in[inLength++] = tri.p2;

        uint8_t clippedTriLength = 0;
        if (outLength == 0)
        {
            clippedTri[0] = tri;
            clippedTriLength = 1;
        }
        else if (outLength == 1)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[1]);

            clippedTri[0] = Tri3(c0, in[0], c1);
            clippedTri[1] = Tri3(c1, in[0], in[1]);
            clippedTriLength = 2;
        }
        else if (outLength == 2)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[1], in[0]);

            clippedTri[0] = Tri3(c0, c1, in[0]);
            clippedTriLength = 1;
        }


        for (uint8_t i = 0; i < clippedTriLength; i++)
        {
            Tri3 tri = clippedTri[i];

            pushTriangle(tri, color);
        }
        

    }
}


Vec2 Camera::vectorProjection(Vec3 v) const {
    return Vec2(v.x, v.y) / v.z * focalLenth;
}

Tri2 Camera::triangleProjection(Tri3 tri) const {
    return Tri2(vectorProjection(tri.p0), vectorProjection(tri.p1), vectorProjection(tri.p2));
}

const float screenRatio = (float)Screen::Height / (float)Screen::Width;

Vec2 Camera::vectorToScreen(Vec2 v) const {
    return Vec2((screenRatio * v.x + 1) * Screen::Width / 2, (-v.y + 1) * Screen::Height / 2);
}

Tri2 Camera::triangleToScreen(Tri2 tri) const {
    return Tri2(vectorToScreen(tri.p0), vectorToScreen(tri.p1), vectorToScreen(tri.p2));
}