/*****************************************************************//**
 * \file   StringUtility.h
 * \brief  string関連汎用処理
 *********************************************************************/
#pragma once

#include <string>
#include <vector>

namespace PotatoLib {
	/**
	 * @class StringUtility.
	 * @brief string関連汎用処理
	 */
	class StringUtility {
	public:
		/**
		 * @brief 文字列分割.
		 * 
		 * \param aText 分割対象文字列
		 * \param aDelim デリミタ
		 * \return  分割結果
		 */
		static std::vector<std::string> Split(const std::string& aText, char aDelim);

	private:
	};
}
