/*****************************************************************//**
 * \file   Converter.h
 * \brief  汎用コンバートクラス
 *********************************************************************/
#pragma once

#include <string>
#include <sstream>

namespace PotatoLib {
	/**
	 * @class Converter.
	 * @brief 汎用コンバートクラス
	 */
	class Converter {
	public:

		/**
		 * @brief string → int
		 *
		 * @param[in] str 文字列
		 * @return 変換したint型
		 */
		static int StrToInt(const std::string& str);

		/**
		 * @brief string → float
		 *
		 * @param[in] str 文字列
		 * @return 変換したfloat型
		 */
		static float StrToFloat(const std::string& str);

		/**
		 * @brief string → double
		 *
		 * @param[in] str 文字列
		 * @return 変換したdouble型
		 */
		static double StrToDouble(const std::string& str);

		/**
		 * @brief T → string
		 *
		 * @param[in] n 対象数値
		 * @return 変換したstring型
		 */
		template<typename T>
		static const std::string NumToStr(T n) {
			std::stringstream ss;
			ss << n;
			return ss.str();
		}

		/**
		 * @brief 文字列、数列の連結
		 * @atttention 再帰の終着点
		 */
		template<typename T>
		static std::string ConnectString(const T& t) {
			return NumToStr(t);
		}

		/**
		 * @brief 文字列、数列の連結
		 *
		 *@param[in] first
		 *@param[in] rest...
		 */
		template<typename First, typename... Rest>
		static std::string ConnectString(const First& first, const Rest&... rest) {
			return NumToStr(first) + ConnectString(rest...);
		}
	};
}
