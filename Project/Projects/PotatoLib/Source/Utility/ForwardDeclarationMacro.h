/*****************************************************************//**
 * \file   ForwardDeclarationMacro.h
 * \brief  前方宣言テンプレートマクロ
 *********************************************************************/
#pragma once

namespace PotatoLib {
	/**
	 * std::string 前方宣言用マクロ.
	 */
#define STRING_FORWARD															\
	namespace std {																\
		template <class _Ty> class allocator;									\
		template <class _Elem> struct char_traits;								\
		template <class _Elem, class _Traits, class _Alloc> class basic_string; \
		using string = basic_string<char, char_traits<char>, allocator<char>>;	\
	}
}
