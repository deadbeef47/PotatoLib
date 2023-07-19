/*****************************************************************//**
 * \file   Math.h
 * \brief  汎用計算クラス
 *********************************************************************/
#pragma once

namespace PotatoLib {
	/**
	 * @class Math.
	 * @brief 汎用計算クラス
	 */
	class Math
	{
	public:

		/**
		 * @brief 円周率.
		 *
		 * \return 円周率
		 */
		static const float PI();

		/**
		 * @brief radian → degree.
		 * \param radian ラジアン値
		 * \return 度数
		 */
		static float ToDegree(float radian);

		/**
		 * @brief degree → radian.
		 *
		 * \param degree 度数
		 * \return  ラジアン値
		 */
		static float ToRadian(float degree);

		/**
		 * サイン.
		 * 
		 * \param degree 角度
		 * \return Sin値
		 */
		static float Sin(float degree);

		/**
		 * コサイン.
		 * 
		 * \param degree 角度
		 * \return Cos値
		 */
		static float Cos(float degree);

		/**
		 * タンジェント.
		 * 
		 * \param degree
		 * \return 
		 */
		static float Tan(float degree);

		/**
		 * 平方根.
		 * 
		 * \param f 元値
		 * \return 計算結果
		 */
		static float Sqrt(float f);
	};
}
