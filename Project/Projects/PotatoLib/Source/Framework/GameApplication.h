/*****************************************************************//**
 * \file   GameApplication.h
 * \brief  ゲームループ/イベント実行クラス
 *********************************************************************/

#pragma once

 //#include "Source\Utility\Singleton.h"
#include "Utility\Singleton.h"

namespace PotatoLib {

	/**
	 * @class GameApplication
	 * @brief ゲームループ/イベント実行クラス
	 */
	class GameApplication {
	public:
		/**
		 * @brief コンストラクタ.
		 */
		GameApplication();

		/**
		 * @brief ループ開始
		 */
		void Run();

	protected:
		/**
		 * ゲームループ初期化 (ユーザー拡張可)
		 * @brief ゲームループ初期化
		 */
		virtual void Initialize() {}
		/**
		 * ゲームループ ロジック更新 (ユーザー拡張可).
		 * @brief ゲームループロジック更新
		 */
		virtual void Update() {}
		/**
		 * ゲームループ 描画更新 (ユーザー拡張可).
		 * @brief ゲームループ 描画更新
		 */
		virtual void Draw() {}
		/**
		 * ゲームループ 終了処理 (ユーザー拡張可).
		 * @brief ゲームループ 終了処理
		 */
		virtual void Finish() {}

	protected:
		//! OpenGL メジャーバージョン
		int mMajorVersion;
		//! OpenGL マイナーバージョン
		int mMinorVersion;
	private:
	};
}

