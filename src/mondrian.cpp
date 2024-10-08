#include "mondrian.h"
#include "eadkpp.h"
#include "rgb332.h"
#include "maths.h"

using EADK::Color;

uint8_t mondrian::buffer[Screen::Height][Screen::Width];

void mondrian::draw() {
  for (uint8_t i = 0; i < Screen::Height; i++) {
    Color bufferRow[Screen::Width];
    for (uint16_t j = 0; j < Screen::Width; j++)
    {
        bufferRow[j] = rgb332ToColor(buffer[i][j]);
    }
    Display::pushRect(Rect(0, i, Screen::Width, 1), bufferRow);
  }
}

void mondrian::clear() {
  for (uint8_t i = 0; i < Screen::Height; i++)
  {
    for (uint16_t j = 0; j < Screen::Width; j++)
    {
      buffer[i][j] = 0;
    }
  }
}

float eq(Vec2 p, Vec2 a, Vec2 b) {
  return (a.x - p.x) * (b.y - p.y) - (a.y - p.y) * (b.x - p.x);
}
  
void mondrian::putTriangle(Tri2 tri, uint8_t color) {
  int xMin = min(tri.p0.x, tri.p1.x, tri.p2.x);
  int xMax = max(tri.p0.x, tri.p1.x, tri.p2.x);
  int yMin = min(tri.p0.y, tri.p1.y, tri.p2.y);
  int yMax = max(tri.p0.y, tri.p1.y, tri.p2.y);

  for (int y = yMin; y < yMax; y++)
  {
    if (0 < y && y < Screen::Height)
    {
      for (int x = xMin; x < xMax; x++)
      {
        if (0 < x && x < Screen::Width) {
          Vec2 pos(x, y);
          float w0 = eq(pos, tri.p0, tri.p1);
          float w1 = eq(pos, tri.p1, tri.p2);
          float w2 = eq(pos, tri.p2, tri.p0);
          if ((w0 >= 0 && w1 >= 0 && w2 >= 0) || (-w0 >= 0 && -w1 >= 0 && -w2 >= 0))
          {
            buffer[y][x] = color;
          }
        } 
      }
    }
  }
}