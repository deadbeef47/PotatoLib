#pragma once

#include <iostream>
#include <time.h>

#define PotatoLog(...) PotatoLib::Log::Show(__VA_ARGS__)

namespace PotatoLib {

	class Log {
	public:
		static void Show() {
			std::cout << std::endl;
		}

		template<class Str, class... Args>
		static void Show(Str str, Args... args) {
			std::cout << str;
			Log::Show(std::forward<Args>(args)...);
		}
	};
}
