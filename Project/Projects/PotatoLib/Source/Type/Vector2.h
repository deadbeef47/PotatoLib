/*****************************************************************//**
 * \file   Vector2.h
 * \brief  xyベクトル計算構造体
 *********************************************************************/
#pragma once

#include <glm/vec2.hpp>
#include <string>
namespace std {
	template <class _Elem, class _Traits, class _Alloc> class basic_string;
	using string = basic_string<char, char_traits<char>, allocator<char>>;
}

namespace PotatoLib {
	/**
	 * @struct Vector2.
	 * @brief xyベクトル計算構造体
	 */
	struct Vector2
	{
		//! (0.0f, 0.0f)のゼロベクトル
		static const Vector2 Zero;
		//! (1.0f, 1.0f)のベクトル
		static const Vector2 One;

		union {
			struct {
				float x; //!< x成分
				float y; //!< y成分
			};
			//! xy成分配列
			float xy[2];
			//! glm xy成分
			glm::vec2 glmVec2;
		};

		/**
		 * @brief コンストラクタ
		 * @details xy成分は0で初期化される
		 */
		Vector2();

		/**
		 * @brief コンストラクタ
		 * @details xy値指定
		 * @param x x
		 * @param y y
		 */
		Vector2(float x, float y);

		/**
		 * @brief glmからVector2への変換
		 * @param v 変換元
		 * @return 変換値
		 */
		static Vector2 GLMToVector2(const glm::vec2& v);

		/**
		 * @brief 自身のベクトル正規化.
		 *
		 * \return 正規化された自身のインスタンス
		 */
		const Vector2& Normalize();

		/**
		 * @brief ベクトル正規化.
		 *
		 * \param v 参照ベクトル
		 * \return 正規化されたベクトルインスタンス
		 */
		static Vector2 Normalize(const Vector2& v);

		/**
		 * @brief 自身のノムル.
		 *
		 * \return 計算結果 自身のノムル値
		 */
		float Length()const;

		/**
		 * @brief ノムル.
		 *
		 * \param v 参照ベクトル
		 * \return 計算結果 ノムル値
		 */
		static float Length(const Vector2& v);

		/**
		 * @brief ２点ベクトルから角度を求める.
		 * @details 角度 => degree
		 *
		 * \param v1 参照ベクトル1
		 * \param v2 参照ベクトル2
		 * \return 角度
		 */
		static float Angle(const Vector2& v1, const Vector2& v2);

		/** 
		 * @brief 角度からベクトルを求める
		 * @details angle => degree
		 * 
		 * @param angle 角度
		 * @return 角度から算出したベクトル
		 */
		static Vector2 Direction(float angle);

		/**
		 * @brief ベクトル間の距離
		 * 
		 * @param v1 始点
		 * @param v2 終点
		 * @return 距離
		 */
		static float Distance(const Vector2& v1, const Vector2& v2);


		/**
		 * @brief 文字列変換.
		 *
		 * \return (x,y)形式での文字出力
		 */
		std::string ToString()const;

		/**
		 * @brief 単項演算子オーバーロード +
		 */
		Vector2 operator + ()const;
		/**
		 * @brief 単項演算子オーバーロード -
		 */
		Vector2 operator - ()const;

		/**
		 * @brief 代入演算子オーバーロード +=
		 */
		Vector2& operator += (const Vector2& v);
		/**
		 * @brief 代入演算子オーバーロード -=
		 */
		Vector2& operator -= (const Vector2& v);
		/**
		 * @brief 代入演算子オーバーロード *=
		 */
		Vector2& operator *= (float s);
		/**
		 * @brief 代入演算子オーバーロード /=
		 */
		Vector2& operator /= (float s);
	};

	/**
	 * @brief ２項演算子オーバーロード +
	 */
	const Vector2 operator + (const Vector2& v1, const Vector2& v2);
	/**
	 * @brief ２項演算子オーバーロード -
	 */
	const Vector2 operator - (const Vector2& v1, const Vector2& v2);
	/**
	 * @brief ２項演算子オーバーロード s * vec
	 */
	const Vector2 operator * (const Vector2& v, float s);
	/**
	 * @brief ２項演算子オーバーロード vec * s
	 */
	const Vector2 operator * (float s, const Vector2& v);
	/**
	 * @brief ２項演算子オーバーロード /
	 */
	const Vector2 operator / (const Vector2& v, float s);
}
