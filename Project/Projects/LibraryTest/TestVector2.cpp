#include "pch.h"

#include <Type/Vector2.h>

#define CheckVectorVFF(checkValue, _x, _y) \
	EXPECT_TRUE(checkValue.x <= _x + FLT_EPSILON && checkValue.x >= _x - FLT_EPSILON); \
	EXPECT_TRUE(checkValue.y <= _y + FLT_EPSILON && checkValue.y >= _y - FLT_EPSILON); \

#define CheckVectorVV(checkValue, testValue) \
	EXPECT_TRUE((checkValue).x <= (testValue).x + FLT_EPSILON && (checkValue).x >= (testValue).x - FLT_EPSILON); \
	EXPECT_TRUE((checkValue).y <= (testValue).y + FLT_EPSILON && (checkValue).y >= (testValue).y - FLT_EPSILON); \

TEST(Vector2, Const) {
	CheckVectorVFF(PotatoLib::Vector2::Zero, 0.0f, 0.0f);
	CheckVectorVFF(PotatoLib::Vector2::One, 1.0f, 1.0f);
}

TEST(Vector2, Constructor) {
	CheckVectorVFF(PotatoLib::Vector2(), 0.0f, 0.0f);
	CheckVectorVFF(PotatoLib::Vector2(10.0f, 20.0f), 10.0f, 20.0f);
}

TEST(Vector2, GLMToVector2) {
	CheckVectorVFF(PotatoLib::Vector2::GLMToVector2(glm::vec2(100.0f, 200.0f)), 100.0f, 200.0f);
}

TEST(Vector2, Normalize) {
	CheckVectorVFF(PotatoLib::Vector2::Normalize(PotatoLib::Vector2(1.0f, 0.0f)), 1.0f, 0.0f);
	CheckVectorVFF(PotatoLib::Vector2::Normalize(PotatoLib::Vector2(0.0f, 1.0f)), 0.0f, 1.0f);

	auto v1 = PotatoLib::Vector2::Zero;
	v1.Normalize();
	EXPECT_TRUE(std::isnan(v1.x));
	EXPECT_TRUE(std::isnan(v1.y));

	auto v2 = PotatoLib::Vector2(100.0f, 0.0f);
	v2.Normalize();
	CheckVectorVFF(v2, 1.0f, 0.0f);
}

TEST(Vector2, Length) {
	auto v = PotatoLib::Vector2(3.0f, 4.0f);
	auto length = PotatoLib::Vector2::Length(v);
	EXPECT_FLOAT_EQ(length, 5.0f);
	EXPECT_FLOAT_EQ(v.Length(), 5.0f);
}

TEST(Vector2, Angle) {
	EXPECT_FLOAT_EQ(PotatoLib::Vector2::Angle(PotatoLib::Vector2(100.0f, 0.0f), PotatoLib::Vector2(1.0f, 0.0f)), 0.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Vector2::Angle(PotatoLib::Vector2(1.0f, 0.0f), PotatoLib::Vector2(100.0f, 0.0f)), 0.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Vector2::Angle(PotatoLib::Vector2(1.0f, 0.0f), PotatoLib::Vector2(1.0f, 1.0f)), 45.0f);
	EXPECT_TRUE(std::isnan(PotatoLib::Vector2::Angle(PotatoLib::Vector2(0.0f, 0.0f), PotatoLib::Vector2(1.0f, 0.0f))));
}

TEST(Vector2, Direction) {
	CheckVectorVFF(PotatoLib::Vector2::Direction(0.0f), 1.0f, 0.0f);
	CheckVectorVFF(PotatoLib::Vector2::Direction(90.0f), 0.0f, 1.0f);
	CheckVectorVFF(PotatoLib::Vector2::Direction(180.0f), -1.0f, 0.0f);
	CheckVectorVFF(PotatoLib::Vector2::Direction(270.0f), 0.0f, -1.0f);
}

TEST(Vector2, Distance) {
	EXPECT_FLOAT_EQ(PotatoLib::Vector2::Distance(PotatoLib::Vector2(3.0f, 4.0f), PotatoLib::Vector2::Zero), 5.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Vector2::Distance(PotatoLib::Vector2::Zero, PotatoLib::Vector2::Zero), 0.0f);
}

TEST(Vector2, ToString) {
	auto zeroStr = std::to_string(0.0f);
	EXPECT_EQ(std::string("(" + zeroStr + "," + zeroStr + ")"), PotatoLib::Vector2::Zero.ToString());
}

TEST(Vector2, Operator) {


	auto v1 = PotatoLib::Vector2(100.0f, 100.0f);
	v1 += PotatoLib::Vector2(20.0f, 30.0f);
	CheckVectorVFF(v1, 120.0f, 130.0f);

	v1 -= PotatoLib::Vector2(20.0f, 30.0f);
	CheckVectorVFF(v1, 100.0f, 100.0f);

	v1 *= 2;
	CheckVectorVFF(v1, 200.0f, 200.0f);

	v1 /= 2;
	CheckVectorVFF(v1, 100.0f, 100.0f);

	CheckVectorVV(PotatoLib::Vector2(0.0f, 1.0f) + PotatoLib::Vector2(1.0f, 0.0f), PotatoLib::Vector2(1.0f, 1.0f));
	CheckVectorVV(PotatoLib::Vector2(50.0f, 1.0f) - PotatoLib::Vector2(1.0f, 50.0f), PotatoLib::Vector2(49.0f, -49.0f));
	CheckVectorVV(PotatoLib::Vector2(50.0f, 1.0f) * 3.0f, PotatoLib::Vector2(150.0f, 3.0f));
	CheckVectorVV(3.0f * PotatoLib::Vector2(50.0f, 1.0f), PotatoLib::Vector2(150.0f, 3.0f));
	CheckVectorVV(PotatoLib::Vector2(50.0f, 1.0f) / 10.0f, PotatoLib::Vector2(5.0f, 0.1f));

	CheckVectorVV(+PotatoLib::Vector2(1.0f, 0.0f), PotatoLib::Vector2(1.0f, 0.0f));
	CheckVectorVV(-PotatoLib::Vector2(1.0f, 0.0f), PotatoLib::Vector2(-1.0f, 0.0f));
}