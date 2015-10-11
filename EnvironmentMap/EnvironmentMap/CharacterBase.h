#ifndef DEF_BASE_H
#define DEF_BASE_H
#include "Include.h"
#include "AppController.h"
#include "Map.h"
namespace Character{

	class CharacterBase
	{
		

		public:
			// 現在の向いてる方向
			enum class Direction{
				eUp = 0,
				eDown,
				eLeft,
				eRight,
				eNull,
			};

			struct Position{
				Position() = default;
				Position(const float xx,const float yy):
					x(xx),
					y(yy){}
				float x;
				float y;
				CharacterBase::Direction direction;
			};

		protected:

			// 画像パス用
			struct ImagePassTable{
				ImagePassTable() = default;


				std::string m_upImagePass;
				std::string m_downImagePass;
				std::string m_leftImagePass;
				std::string m_rightImagePass;
			};

		private:

			// 画像のロード先テーブル
			struct ImageHandleTable{

				ImageHandleTable() = default;
				int m_upImage;
				int m_downImage;
				int m_leftImage;
				int m_rightImage;
			};


		public:
			CharacterBase();

			~CharacterBase() = default;

			float GetX()const;
			float GetY()const;
			void SetX(const float xx);
			void SetY(const float yy);
			CharacterBase::Position GetPostion()const;
			
			// 初期値を代入する関数
			void SetStartPosition(const Position position);

			// 移動用
			void Move(const Position position);

			// 描画
			void AnimationRender();

			// キー取得関数
			void MoveDirection(const MyApplication::AppController::Input input);

			// 画像の初期化用
			void SetImage(const CharacterBase::ImagePassTable& pass, const int number);

		protected:

			// アニメーション制御用
			int m_animationCount;

			// アニメーション速度の調整
			int m_waitAnimation;

			// 入力された状態
			CharacterBase::Direction m_direction;

			// 前回の入力状態
			CharacterBase::Direction m_prevDirection;

			// 画像の枚数
			static const int m_numberOfImage;

			
			
		private:

			// 画像ハンドルのゲッター
			int GetUpImage(const int number)const;
			int GetDownImage(const int number)const;


			int GetLeftImage(const int number)const;
			int GetRightImage(const int number)const;

		private:
			
			
			Position m_position;

			int m_waitMove;
			
			ImageHandleTable m_imageTable[4];

			const int m_size;

			static std::unordered_map< MyApplication::AppController::Input, Position> m_inputMove;

			
	
	};

} // !namespace Character

#endif // !DEF_BASE_H