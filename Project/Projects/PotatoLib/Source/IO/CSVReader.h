/*****************************************************************//**
 * \file   CSVReader.h
 * \brief  CSV入力
 *********************************************************************/
#pragma once

#include "TextReader.h"

#include <vector>

namespace PotatoLib {

	/**
	 * @class CSVReader.
	 * @brief CSV入力
	 */
	class CSVReader {
	public:
		/**
		 * @brief データロード.
		 * 
		 * \param aFileName ファイル名
		 * \return 成功/失敗
		 */
		bool Load(const std::string& aFileName);

		/**
		 * @brief int値取得.
		 * 
		 * \param aRow 行番号
		 * \param aCol 列番号
		 * \return 指定位置のint値
		 */
		int GetInt(int aRow, int aCol)const;

		/**
		 * @brief float値取得.
		 * 
		 * \param aRow 行番号
		 * \param aCol 列番号
		 * \return 指定位置のfloat値
		 */
		float GetFloat(int aRow, int aCol)const;

		/**
		 * @brief string値の取得.
		 * 
		 * \param aRow 行番号
		 * \param aCol 列番号
		 * \return 指定位置のstring値
		 */
		const std::string& GetString(int aRow, int aCol)const;

		/**
		 * @brief 行サイズ取得.
		 * 
		 * \return 行サイズ
		 */
		int GetRowSize()const;

		/**
		 * @brief 列サイズ取得.
		 * 
		 * \param aRow 指定する行
		 * \return 指定行の列サイズ
		 */
		int GetColumnSize(int aRow)const;

	private:
		using Rows = std::vector<std::string>;	//!< 行データ配列型
		using CSVData = std::vector<Rows>;		//!< 全体データ配列型
		CSVData mCSVData;	//!< データ
	};
}
