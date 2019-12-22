#include "Assert.h"

#include <cassert>

namespace PotatoLib {
	void Assert::Check(const char* aMessage) {
		Check(false, aMessage);
	}
	void Assert::Check(bool aCondition, const char* aMessage) {
		// TODO: «—ˆ“I‚É‚»‚ê‚Á‚Û‚­‚·‚é
		assert(aCondition && aMessage);
	}
}
