#define _USE_MATH_DEFINES
#include "Vec2.h"
#include <iostream>
#include <cmath>


float Vec2::absoluteValue() const { return std::sqrt(std::pow(this->x, 2.0) + std::pow(this->y, 2.0)); }; 
float Vec2::dot(const Vec2& _vec) const { return (this->x * _vec.x) + (this->y * _vec.y); }; 
Vec2 Vec2::normalize() const { return Vec2(this->x / this->absoluteValue(), this->y / this->absoluteValue()); }; 
float Vec2::angle(const Vec2& other) const { return (std::acos(this->dot(other)/(this->absoluteValue() * other.absoluteValue())))*180/M_PI; };
float Vec2::distance(const Vec2& other) const { return Vec2(x - other.x, y - other.y).absoluteValue(); };

