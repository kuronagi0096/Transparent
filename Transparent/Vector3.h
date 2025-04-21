#pragma once
class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3() : x(0), y(0), z(0) {}
	Vector3(float x, float y, float z);
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator*(float scalar) const;
	Vector3 operator/(float scalar) const;
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(float scalar);
	Vector3& operator/=(float scalar);
	float Length() const;
	Vector3 Normalize() const;
};

