#include "Vector3.h"
#include <cmath>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3 Vector3::operator+(const Vector3& v) const {
	return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 Vector3::operator-(const Vector3& v) const {
	return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 Vector3::operator*(float scalar) const {
	return Vector3(x * scalar, y * scalar, z * scalar);
}
Vector3 Vector3::operator/(float scalar) const {
	if (scalar != 0) {
		return Vector3(x / scalar, y / scalar, z / scalar);
	}
	return Vector3(0, 0, 0); // Avoid division by zero
}
Vector3& Vector3::operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector3& Vector3::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
Vector3& Vector3::operator/=(float scalar) {
	if (scalar != 0) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}
	return *this; // Avoid division by zero
}
float Vector3::Length() const {
	return std::sqrt(x * x + y * y + z * z);
}
Vector3 Vector3::Normalize() const {
	float len = Length();
	if (len > 0) {
		return Vector3(x / len, y / len, z / len);
	}
	return Vector3(0, 0, 0); // Avoid division by zero
}