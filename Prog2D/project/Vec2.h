#pragma once
#ifndef C_VEC2
#define C_VEC2

namespace{
	class Vec2
	{
	private:
		float x;
		float y;

	public:
		Vec2(float _x, float _y);
		~Vec2();
		Vec2 absoluteVector(); // Absolute value or length is distance from zero --> sqrt(x^2+y^2)
		Vec2 absoluteVector(Vec2 const& _vec); // Absolute value or length is distance from zero --> sqrt(_vec.x^2+_vec.y^2)
		Vec2 scalar(const float _scalar); // Vec2(x*_scalar, y*_scalar)
		Vec2 scalar(Vec2 const& _vec, const float _scalar); // Vec2(_vec.x*_scalar, _vec.y*_scalar)
		Vec2 dot(Vec2 const& _vec2); // Vec2(x*_vec2.x, y*_vec2.y)
		Vec2 dot(Vec2 const& _vec1, Vec2 const& _vec2); // Vec2(_vec1.x*_vec2.x, _vec1.y*_vec2.y)
		Vec2 normalize(Vec2 const& _vec1, Vec2 const& _vec2); // Vec2( x / vectorLength (aka norm), y / vectorLength (aka norm) )
		float angle(const Vec2& other) const; // arccos ( dot(other)/(vectorLength()*vectorLength(other)) )
		float distance(const Vec2& other) const; // length of diference --> absoluteVector(Vec2( x-other.x, y-other.y ))

		friend Vec2 operator+(Vec2 const& _vec1, Vec2 const& _vec2); // Vec2(_vec1.x+_vec2.x, _vec1.y+_vec2.y)
		friend Vec2 operator+(Vec2 const& _vec2); // Vec2(x+_vec2.x, y+_vec2.y)
		friend Vec2 operator-(Vec2 const& _vec1, Vec2 const& _vec2); // Vec2(_vec1.x+_vec2.x, _vec1.y+_vec2.y)
		friend Vec2 operator-(Vec2 const& _vec2); // Vec2(x+_vec2.x, y+_vec2.y)
		friend Vec2 operator*(Vec2 const& _vec1, Vec2 const& _vec2); // dot
		friend Vec2 operator*(Vec2 const& _vec, const float _scalar); // scalar
		friend Vec2 operator/(Vec2 const& _vec1, Vec2 const& _vec2); // dot
		friend Vec2 operator/(Vec2 const& _vec, const float _scalar); // scalar
	};
}

#endif
