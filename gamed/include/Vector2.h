

#ifndef VECTOR2_H
#define	VECTOR2_H


#pragma once

#include <math.h>

class Vector2
{
public:
   Vector2(void);
   Vector2(float X, float Y);
   ~Vector2(void);
   float Length();
   Vector2 Normalize();
   float X, Y;
   friend Vector2 operator-(const Vector2 &c1, const Vector2 &c2);
   friend Vector2 operator+(const Vector2 &c1, const Vector2 &c2);
   friend Vector2 operator*(const Vector2 &c1, const int c2);
   friend Vector2 operator*(const Vector2 &c1, const double c2);

};
#endif	/* VECTOR2_H */

