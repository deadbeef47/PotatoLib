#include "Converter.h"

namespace PotatoLib {

	int Converter::StrToInt(const std::string& str) {
		return std::atoi(str.c_str());
	}

	float Converter::StrToFloat(const std::string& str) {
		return (float)StrToDouble(str);
	}

	double Converter::StrToDouble(const std::string& str) {
		return std::atof(str.c_str());
	}
}