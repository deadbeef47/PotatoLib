/*****************************************************************//**
 * \file   Log.h
 * \brief  汎用ログクラス
 *********************************************************************/
#pragma once

#include <iostream>
#include <time.h>

#define PotatoLog(...) PotatoLib::Log::Show(__VA_ARGS__)

namespace PotatoLib {

	/**
	 * @class Log.
	 * @brief 汎用ログクラス
	 */
	class Log {
	public:
		/**
		 * @brief ？.
		 * 
		 */
		static void Show() {
			std::cout << std::endl;
		}

		/**
		 * @brief ログ表示.
		 * \param str 出力文字列
		 * \param ...args 追加引数
		 */
		template<class Str, class... Args>
		static void Show(Str str, Args... args) {
			std::cout << str;
			Log::Show(std::forward<Args>(args)...);
		}
	};
}
