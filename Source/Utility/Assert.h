#pragma once

//#define PotatoAssert(condition, ...) PotatoLib::Assert::Check(condition, __VA_ARGS__)

namespace PotatoLib {
	class Assert {
	public:
		static void Check(const char* aMessage);
		static void Check(bool aCondition, const char* aMessage);
	};
}
