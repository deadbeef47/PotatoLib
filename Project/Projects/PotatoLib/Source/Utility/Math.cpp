#include "Math.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace PotatoLib {

	const float Math::PI() {
		return glm::pi<float>();
	}

	float Math::ToDegree(float radian) {
		return glm::degrees(radian);
	}

	float Math::ToRadian(float degree) {
		return glm::radians(degree);
	}

	float Math::Sin(float degree) {
		return glm::sin(ToRadian(degree));
	}

	float Math::Cos(float degree) {
		return glm::cos(ToRadian(degree));
	}

	float Math::Tan(float degree) {
		return glm::tan(ToRadian(degree));
	}

	float Math::Sqrt(float f) {
		return glm::sqrt(f);
	}
}
