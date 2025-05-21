#pragma once
#include <cmath>

struct Vector2 {
    float x;
    float y;
    Vector2();
    Vector2(float x, float y);
    float Length() const;
    Vector2 Normalize() const;

    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;
    Vector2& operator+=(const Vector2& v);
    Vector2& operator-=(const Vector2& v);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);
};
