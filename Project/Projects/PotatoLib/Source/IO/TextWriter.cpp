#include "TextWriter.h"

#include <fstream>
#include <direct.h>
#include <errno.h>
#include "Utility/PathUtility.h"

namespace PotatoLib {

	bool TextWriter::Save(const std::string& aPath, const std::string& aSaveText) {

		if (!CreateDirectory(aPath)) return false;

		std::ofstream lFile(aPath);
		if (!lFile.is_open()) {
			return false;
		}

		lFile << aSaveText;
		return true;
	}

	bool TextWriter::CreateDirectory(const std::string& aPath) {
		const auto lDirectory = PathUtility::GetDirectory(aPath);
		const auto lFolderNames = PathUtility::GetElementArray(lDirectory);

		bool lIsFailCreateDir = false;
		std::string lCreatedFolder = "";
		for (const auto& lFolderName : lFolderNames) {
			lCreatedFolder += lFolderName;

			errno = 0;
			if (_mkdir(lCreatedFolder.c_str()) == -1) continue;

			lCreatedFolder += "/";
		}
		errno = 0;

		return !lIsFailCreateDir;
	}
}