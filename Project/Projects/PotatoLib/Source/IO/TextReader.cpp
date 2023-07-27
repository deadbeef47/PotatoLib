#include "TextReader.h"

#include <fstream>

namespace PotatoLib {

	bool TextReader::Load(const std::string& aFileName, std::string* aLoadText) {
		if (mFileName == aFileName) {
			(*aLoadText) = mFullText;
			return !mFileName.empty();
		}

		std::ifstream lFile(aFileName);
		if (!lFile.is_open()) {
			mFullText = (*aLoadText) = "";
			mFileName = "";
			return false;
		}

		SkipUTF8BOM(&lFile);

		mFileName = aFileName;
		mFullText = (*aLoadText) = std::string((std::istreambuf_iterator<char>(lFile)), (std::istreambuf_iterator<char>()));
	}

	void TextReader::SkipUTF8BOM(std::ifstream* aFile) {
		int lHeader[3] = { 0 };
		for (auto& lChar : lHeader) lChar = aFile->get();
		constexpr int utf8[] = { 0xEF, 0xBB, 0xBF };
		if (!std::equal(std::begin(lHeader), std::end(lHeader), utf8)) {
			aFile->seekg(0);
		}
	}
}
