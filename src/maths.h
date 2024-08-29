#ifndef MATHS_H
#define MATHS_H

#define PI 3.1415927f
#define HALF_PI 1.5707964f
#define TWO_PI 6.2831855f

float cos(float x);
float sin(float x);

int round(float x);
float sqrt(float x);
float abs(float x);

float max(float a, float b);
float max(float a, float b, float c);
float min(float a, float b);
float min(float a, float b, float c);

#endif