#ifndef DEF_BASE_H
#define DEF_BASE_H
#include "Include.h"
#include "AppController.h"
#include "Map.h"
namespace Character{

	class CharacterBase
	{
		

		public:
			// ���݂̌����Ă����
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

			// �摜�p�X�p
			struct ImagePassTable{
				ImagePassTable() = default;


				std::string m_upImagePass;
				std::string m_downImagePass;
				std::string m_leftImagePass;
				std::string m_rightImagePass;
			};

		private:

			// �摜�̃��[�h��e�[�u��
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
			
			// �����l��������֐�
			void SetStartPosition(const Position position);

			// �ړ��p
			void Move(const Position position);

			// �`��
			void AnimationRender();

			// �L�[�擾�֐�
			void MoveDirection(const MyApplication::AppController::Input input);

			// �摜�̏������p
			void SetImage(const CharacterBase::ImagePassTable& pass, const int number);

		protected:

			// �A�j���[�V��������p
			int m_animationCount;

			// �A�j���[�V�������x�̒���
			int m_waitAnimation;

			// ���͂��ꂽ���
			CharacterBase::Direction m_direction;

			// �O��̓��͏��
			CharacterBase::Direction m_prevDirection;

			// �摜�̖���
			static const int m_numberOfImage;

			
			
		private:

			// �摜�n���h���̃Q�b�^�[
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