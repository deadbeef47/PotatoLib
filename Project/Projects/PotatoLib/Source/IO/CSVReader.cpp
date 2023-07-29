#include "CSVReader.h"

#include "Utility/Converter.h"

#include <sstream>

namespace PotatoLib {

	bool CSVReader::Load(const std::string& aFileName) {
		std::string lFullText = "";
		TextReader lTextReader;
		auto lRes = lTextReader.Load(aFileName, &lFullText);
		if (!lRes)return false;

		std::stringstream lFullTextStream(lFullText);
		std::string lLine;
		while (std::getline(lFullTextStream, lLine)) {
			Rows lRows;
			std::stringstream lLineStream(lLine);
			std::string lSplitStr;
			while (std::getline(lLineStream, lSplitStr, ',')) {
				lRows.emplace_back(lSplitStr);
			}
			mCSVData.emplace_back(lRows);
		}
		return true;
	}

	int CSVReader::GetInt(int aRow, int aCol)const {
		return Converter::StrToInt(GetString(aRow, aCol));
	}
	float CSVReader::GetFloat(int aRow, int aCol)const {
		return Converter::StrToFloat(GetString(aRow, aCol));
	}

	const std::string& CSVReader::GetString(int aRow, int aCol)const {
		static const std::string lEmptyString = "";
		auto rowSize = GetRowSize();
		if (rowSize <= aRow || 0 > aRow)
			return lEmptyString;

		auto colSize = GetColumnSize(aRow);
		if (colSize == -1)
			return lEmptyString;
		if (colSize <= aCol || 0 > aCol)
			return lEmptyString;

		const auto& lRowData = mCSVData[aRow];
		return lRowData[aCol];
	}

	int CSVReader::GetRowSize()const {
		return mCSVData.size();
	}

	int CSVReader::GetColumnSize(int aRow)const {
		if (GetRowSize() <= aRow)return -1;

		return mCSVData[aRow].size();
	}
}
