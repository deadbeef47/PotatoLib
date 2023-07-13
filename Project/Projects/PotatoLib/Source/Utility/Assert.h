/*****************************************************************//**
 * \file   Assert.h
 * \brief  �ėp�A�T�[�g�N���X
 *********************************************************************/
#pragma once

//#define PotatoAssert(condition, ...) PotatoLib::Assert::Check(condition, __VA_ARGS__)

namespace PotatoLib {
	/**
	 * @class Assert.
	 * @brief �ėp�A�T�[�g�N���X
	 */
	class Assert {
	public:
		/**
		 * @brief �A�T�[�g.
		 * \param aMessage ���b�Z�[�W
		 */
		static void Check(const char* aMessage);

		/**
		 * @brief �A�T�[�g.
		 * \param aCondition �\������(false�̏ꍇ�\��)
		 * \param aMessage ���b�Z�[�W
		 */
		static void Check(bool aCondition, const char* aMessage);
	};
}
