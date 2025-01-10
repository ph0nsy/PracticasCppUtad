#pragma once
#ifndef C_VEC2
#define C_VEC2
class Vec2
{
private:
	float x;
	float y;

public:

	Vec2::Vec2(float _x, float _y) {
		x = _x;
		y = _y;
	};

	Vec2::~Vec2() {
		delete this;
	};

	float absoluteValue() const; // Absolute value or length is distance from zero --> sqrt(x^2+y^2)
	float dot(const Vec2& _vec) const; // Vec2(x*_vec2.x, y*_vec2.y)
	Vec2 normalize() const; // Vec2( x / vectorLength (aka norm), y / vectorLength (aka norm) )
	float angle(const Vec2& other) const; // arccos ( dot(other)/(vectorLength()*vectorLength(other)) )
	float distance(const Vec2& other) const; // length of diference --> absoluteVector(Vec2( x-other.x, y-other.y ))

	Vec2 operator+(const Vec2& _vec) { return Vec2(x + _vec.x, y + _vec.y); };
	Vec2 operator+(const float& _scalar) { return Vec2(x + _scalar, y + _scalar); };
	Vec2 operator-(const Vec2& _vec) { return Vec2(x - _vec.x, y - _vec.y); };
	Vec2 operator-(const float& _scalar) { return Vec2(x - _scalar, y - _scalar); };
	Vec2 operator*(const Vec2& _vec) { return Vec2(x * _vec.x, y * _vec.y); };
	Vec2 operator*(const float& _scalar) const { return Vec2(x * _scalar, y * _scalar); };
	Vec2 operator/(const Vec2& _vec) { return Vec2(x / _vec.x, y / _vec.y); };
	Vec2 operator/(const float& _scalar) const { return Vec2(x / _scalar, y / _scalar); };
};
#endif
