#include "StringUtility.h"
#include <sstream>

namespace PotatoLib {

	std::vector<std::string> StringUtility::Split(const std::string& aText, char aDelim) {
		std::vector<std::string> lRes = {};
		std::stringstream lSs(aText);
		std::string lItem = "";
		while (std::getline(lSs, lItem, aDelim)) {
			lRes.emplace_back(lItem);
		}
		return lRes;
	}
}
