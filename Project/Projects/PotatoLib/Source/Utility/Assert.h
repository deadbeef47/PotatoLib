/*****************************************************************//**
 * \file   Assert.h
 * \brief  汎用アサートクラス
 *********************************************************************/
#pragma once

 //#define PotatoAssert(condition, ...) PotatoLib::Assert::Check(condition, __VA_ARGS__)

namespace PotatoLib {
	/**
	 * @class Assert.
	 * @brief 汎用アサートクラス
	 */
	class Assert {
	public:
		/**
		 * @brief アサート.
		 * \param aMessage メッセージ
		 */
		static void Check(const char* aMessage);

		/**
		 * @brief アサート.
		 * \param aCondition 表示条件(falseの場合表示)
		 * \param aMessage メッセージ
		 */
		static void Check(bool aCondition, const char* aMessage);
	};
}
