#include "Assert.h"

#include <cassert>

namespace PotatoLib {
	void Assert::Check(const char* aMessage) {
		Check(false, aMessage);
	}
	void Assert::Check(bool aCondition, const char* aMessage) {
		// TODO: 将来的にそれっぽくする
		assert(aCondition && aMessage);
	}
}
