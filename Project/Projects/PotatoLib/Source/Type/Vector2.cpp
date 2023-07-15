#include "Vector2.h"

#include <string>
#include <glm/gtx/vector_angle.hpp>

#include <iostream>

namespace PotatoLib
{

	Vector2::Vector2()
		:x(0.0f), y(0.0f) {
	}

	Vector2::Vector2(float x, float y) :
		x(x), y(y) {
	}

	Vector2 Vector2::GLMToVector2(const glm::vec2& v) {
		return Vector2(v.x, v.y);
	}

	const Vector2& Vector2::Normalize() {
		return (*this = Normalize(*this));
	}

	Vector2 Vector2::Normalize(const Vector2& v) {
		return GLMToVector2(glm::normalize(v.glmVec2));
	}

	float Vector2::Length()const {
		return Length(*this);
	}

	float Vector2::Length(const Vector2& v) {
		return glm::length(v.glmVec2);
	}

	float Vector2::Angle(const Vector2& v1, const Vector2& v2) {
		return glm::degrees(glm::angle(Normalize(v1).glmVec2, Normalize(v2).glmVec2));
	}

	Vector2 Vector2::Direction(float angle) {
		return Vector2(glm::cos(glm::radians(angle)), glm::sin(glm::radians(angle)));
	}

	float Vector2::Distance(const Vector2& v1, const Vector2& v2) {
		return glm::distance(v1.glmVec2, v2.glmVec2);
	}

	std::string Vector2::ToString()const {
		return std::string("(" + std::to_string(x) + "," + std::to_string(y) + ")");
	}

	Vector2 Vector2::operator + ()const {
		return *this;
	}
	Vector2 Vector2::operator - ()const {
		return (*this * -1.0f);
	}

	Vector2& Vector2::operator += (const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& Vector2::operator -= (const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& Vector2::operator *= (float s) {
		x *= s;
		y *= s;
		return *this;
	}
	Vector2& Vector2::operator /= (float s) {
		x /= s;
		y /= s;
		return *this;
	}

	const Vector2 operator + (const Vector2& v1, const Vector2& v2) {
		auto temp(v1);
		return temp += v2;
	}
	const Vector2 operator - (const Vector2& v1, const Vector2& v2) {
		auto temp(v1);
		return temp -= v2;
	}
	const Vector2 operator * (const Vector2& v, float s) {
		auto temp(v);
		return temp *= s;
	}
	const Vector2 operator * (float s, const Vector2& v) {
		return v * s;
	}
	const Vector2 operator / (const Vector2& v, float s) {
		auto temp(v);
		return temp /= s;
	}
}
