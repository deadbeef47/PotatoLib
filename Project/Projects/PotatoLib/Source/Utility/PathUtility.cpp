#include "PathUtility.h"
#include "StringUtility.h"

namespace PotatoLib {

	std::string PathUtility::GetDirectory(const std::string& aPath) {
		const auto lLastPos = aPath.find_last_of("\\/");
		if (lLastPos == std::string::npos) return "";
		return aPath.substr(0, lLastPos);
	}

	std::string PathUtility::GetFileName(const std::string& aPath) {
		const auto lLastPos = aPath.find_last_of("\\/");
		if (lLastPos == std::string::npos) return aPath;
		return aPath.substr(lLastPos + 1);
	}

	std::string PathUtility::GetFileExtension(const std::string& aPath) {
		const auto lFileName = GetFileName(aPath);
		const auto lLastPos = lFileName.find_last_of('.');
		if (lLastPos == std::string::npos) return "";
		return lFileName.substr(lLastPos + 1);
	}

	std::vector<std::string> PathUtility::GetElementArray(const std::string& aPath) {
		std::vector<std::string> lRes = {};
		for (const auto& lSplitBackSlash : StringUtility::Split(aPath, '\\')) {
			for (const auto lSplitSlash : StringUtility::Split(lSplitBackSlash, '/')) {
				lRes.emplace_back(lSplitSlash);
			}
		}
		return lRes;
	}
}
