#include "pch.h"

#include <Utility/Math.h>

#define FLOAT_EQ_EPSILON(floatValue, compairValue)				\
	(floatValue) >= (compairValue) - std::numeric_limits<float>::epsilon() && \
		(floatValue) <= (compairValue) + std::numeric_limits<float>::epsilon()

TEST(Math, PI) {
	EXPECT_EQ((int)(PotatoLib::Math::PI() * 100.0f), 314);
}

TEST(Math, ToDegree) {
	EXPECT_FLOAT_EQ(PotatoLib::Math::ToDegree(PotatoLib::Math::PI() * 2.0f), 360);
	EXPECT_FLOAT_EQ(PotatoLib::Math::ToDegree(PotatoLib::Math::PI()), 180);
}

TEST(Math, ToRadian) {
	EXPECT_FLOAT_EQ(PotatoLib::Math::ToRadian(360), PotatoLib::Math::PI() * 2.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Math::ToRadian(180), PotatoLib::Math::PI());
}


TEST(Math, Sin) {
	EXPECT_FLOAT_EQ(PotatoLib::Math::Sin(0), 0.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Math::Sin(30), 0.5);
	EXPECT_FLOAT_EQ(PotatoLib::Math::Sin(90), 1.0f);
}

TEST(Math, Cos) {
	auto c = PotatoLib::Math::Cos(60);
	EXPECT_FLOAT_EQ(PotatoLib::Math::Cos(0),  1.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Math::Cos(60), 0.5f);

	auto cos90 = PotatoLib::Math::Cos(90);
	EXPECT_TRUE(FLOAT_EQ_EPSILON(cos90, 0.0f));
}

TEST(Math, Tan) {
	EXPECT_FLOAT_EQ(PotatoLib::Math::Tan(0), 0.0f);
	EXPECT_FLOAT_EQ(PotatoLib::Math::Tan(45), 1.0f);
}

TEST(Math, Sqrt) {
  EXPECT_FLOAT_EQ(PotatoLib::Math::Sqrt(4), 2.0f);
}