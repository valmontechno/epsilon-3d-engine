#include "rietveld.h"
#include "vMaths.h"
#include "maths.h"
#include "mondrian.h"

using namespace mondrian;

Camera::Camera(Vec3 position, float pitch, float yaw, float focalLenth) {
    this->position = position;
    this->pitch = pitch;
    this->yaw = yaw;
    this->focalLenth = focalLenth;
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
    /*Vec3 lookAt = getLookAt();

    const Vec3 p = position + (lookAt * 1.0f);
    pushTriangle(Tri3(p + Vec3(0.1f, 0.1f, 0), p + Vec3(0.1f, -0.1f, 0), p + Vec3(-0.1f, -0.1f, 0)), 0b11100000);
    pushTriangle(Tri3(p + Vec3(0.1f, 0.1f, 0), p + Vec3(-0.1f, 0.1f, 0), p + Vec3(-0.1f, -0.1f, 0)), 0b11100000);

    for (size_t i = 0; i < size; i++) {
        Tri3 tri = mesh[i];

        const Vec3 planeNormal = lookAt;
        const Vec3 planePoint = position + (planeNormal * 1.0f);

        Vec3 out[3];
        Vec3 in[3];
        uint8_t outLength = 0;
        uint8_t inLength = 0;

        float v0 = Vec3::dot(planePoint - tri.p0, planeNormal);
        float v1 = Vec3::dot(planePoint - tri.p1, planeNormal);
        float v2 = Vec3::dot(planePoint - tri.p2, planeNormal);

        pushTriangle(Tri3(tri.p0, planePoint, planePoint), 0b11100000);
        pushTriangle(Tri3(tri.p1, planePoint, planePoint), 0b11100000);
        pushTriangle(Tri3(tri.p2, planePoint, planePoint), 0b11100000);

        if (v0 > 0.0f) out[outLength++] = tri.p0; else in[inLength++] = tri.p0;
        if (v1 > 0.0f) out[outLength++] = tri.p1; else in[inLength++] = tri.p1;
        if (v2 > 0.0f) out[outLength++] = tri.p2; else in[inLength++] = tri.p2;

        if (outLength == 0)
        {
            pushTriangle(tri, color);
        }
        else if (outLength == 1)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[1]);

            pushTriangle(Tri3(c0, in[0], c1), 0b00000011);
            pushTriangle(Tri3(c1, in[0], in[1]), 0b00100111);
            // pushTriangle(tri, 0b00000011);
        }
        else if (outLength == 2)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, planePoint, out[1], in[0]);

            pushTriangle(Tri3(c0, c1, in[0]), 0b11111100);
            // pushTriangle(tri, 0b00011100);
        }
        else {
            pushTriangle(tri, 0b00100101);
        }
        
        
    }*/
    Vec3 lookAt = getLookAt();

    for (size_t i = 0; i < size; i++)
    {
        Tri3 triangle = mesh[i];

        Tri3 clippedTriangleList[2];
        int clippedTriangleLength = 0;

        //clip {
        Vec3 planeNormal = lookAt;
        Vec3 zNear = position + (planeNormal * 1.0f);

        Vec3 out[3];
        Vec3 in[3];
        int outLength = 0;
        int inLength = 0;

        //inZ {
        Vec3 planePoint = zNear;

        float vert1 = Vec3::dot(planePoint - triangle.p0, planeNormal);
        float vert2 = Vec3::dot(planePoint - triangle.p1, planeNormal);
        float vert3 = Vec3::dot(planePoint - triangle.p2, planeNormal);

        if (vert1 > 0.0f) {
            out[outLength] = triangle.p0;
            outLength++;
        } else {
            in[inLength] = triangle.p0;
            inLength++;
        }

        if (vert2 > 0.0f) {
            out[outLength] = triangle.p1;
            outLength++;
        } else {
            in[inLength] = triangle.p1;
            inLength++;
        }

        if (vert3 > 0.0f) {
            out[outLength] = triangle.p2;
            outLength++;
        } else {
            in[inLength] = triangle.p2;
            inLength++;
        }
        // } inZ

        if (outLength == 0)
        {
            clippedTriangleList[0] = triangle;
            clippedTriangleLength = 1;
        }
        else if (outLength == 3)
        {
            clippedTriangleLength = 0;
        }
        else if (outLength == 1)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, zNear, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, zNear, out[0], in[1]);

            clippedTriangleList[0] = Tri3(c0, in[0], c1);
            clippedTriangleList[1] = Tri3(c1, in[0], in[1]);
            clippedTriangleLength = 2;
        }
        else if (outLength == 2)
        {
            Vec3 c0 = Vec3::linePlaneIntersection(planeNormal, zNear, out[0], in[0]);
            Vec3 c1 = Vec3::linePlaneIntersection(planeNormal, zNear, out[1], in[0]);

            clippedTriangleList[0] = Tri3(c0, c1, in[0]);
            clippedTriangleLength = 1;

        }

        // } clip

        for (int i = 0; i < clippedTriangleLength; i++)
        {
            Tri3 tri = clippedTriangleList[i];

            pushTriangle(tri, color);
        }
        

    } // for tri in mesh
   
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