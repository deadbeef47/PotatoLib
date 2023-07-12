#pragma once

//#include "Source\Utility\Singleton.h"
#include "Utility\Singleton.h"

namespace PotatoLib {
	class GameApplication {
	public:
		GameApplication();
		void Run();

	protected:
		virtual void Initialize() {}
		virtual void Update() {}
		virtual void Draw() {}
		virtual void Finish() {}

	protected:
		int mMajorVersion, mMinorVersion;
	private:
	};
}

