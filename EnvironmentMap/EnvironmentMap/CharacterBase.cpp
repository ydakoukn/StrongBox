#include "CharacterBase.h"

namespace Character{
	
	// �摜�̑���
	const int CharacterBase::m_numberOfImage = 4;
	
	// �ړ��̘A�z�z��
	std::unordered_map< MyApplication::AppController::Input, CharacterBase::Position> CharacterBase::m_inputMove;

	CharacterBase::CharacterBase():
		m_size(20),
		m_waitMove(0){
		// �A�z�z��̓o�^	//

		// �ړ��p	//
		// ��
		m_inputMove[MyApplication::AppController::Input::eKeyUp].x = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eKeyUp].y = -0.1f;
		m_inputMove[MyApplication::AppController::Input::eKeyUp].direction = CharacterBase::Direction::eUp;

		// ��
		m_inputMove[MyApplication::AppController::Input::eKeyDown].x = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eKeyDown].y = 0.1f;
		m_inputMove[MyApplication::AppController::Input::eKeyDown].direction = CharacterBase::Direction::eDown;

		// ��
		m_inputMove[MyApplication::AppController::Input::eKeyLeft].x = -0.1f;
		m_inputMove[MyApplication::AppController::Input::eKeyLeft].y = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eKeyLeft].direction = CharacterBase::Direction::eLeft;

		// �E
		m_inputMove[MyApplication::AppController::Input::eKeyRight].x = 0.1f;
		m_inputMove[MyApplication::AppController::Input::eKeyRight].y = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eKeyRight].direction = CharacterBase::Direction::eRight;

		// ���͂Ȃ�
		m_inputMove[MyApplication::AppController::Input::eNull].x = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eNull].y = 0.0f;
		m_inputMove[MyApplication::AppController::Input::eNull].direction = CharacterBase::Direction::eNull;
	}

	//
	///
	float CharacterBase::GetX()const{
		return m_position.x;
	}

	//
	///
	float CharacterBase::GetY()const{
		return m_position.y;
	}

	//
	///
	void CharacterBase::SetX(const float xx){
		m_position.x = xx;
	}

	//
	///
	void CharacterBase::SetY(const float yy){
		m_position.y = yy;
	}

	CharacterBase::Position CharacterBase::GetPostion()const{
		return m_position;
	}
	//
	///
	// ������
	void CharacterBase::SetStartPosition(const CharacterBase::Position position){
		m_position = position;
	}


	//
	///
	// �ړ��p
	void CharacterBase::Move(const Position position){
		m_position.x += position.x;
		m_position.y += position.y;
		m_direction	  = position.direction;

	}
	//
	///
	//	�A�j���[�V�����Đ�	//
	void CharacterBase::AnimationRender(){

		// �A�j���[�V�����p
		m_waitAnimation++;

		if (m_waitAnimation > 20)
		{
			m_animationCount++;

			// ���ۂ�0�Ԗڂ��琔����̂�1�}�C�i�X�����l
			if (m_animationCount > m_numberOfImage - 1)
			{
				m_animationCount = 0;
			}
			m_waitAnimation = 0;
		}


		const float x = GetX()*m_size;
		const float y = GetY()*m_size;
		const float width = (GetX()+1) * m_size;
		const float height = (GetY()+1) * m_size;

		
		if (m_direction == Direction::eNull) m_direction = m_prevDirection;

		switch (m_direction)
		{
		case Direction::eUp:
			
			DrawExtendGraph(x, y,
				width, height, GetUpImage(m_animationCount), TRUE);

			m_prevDirection = Direction::eUp;
			break;
		case Direction::eDown:

			DrawExtendGraph(x, y,
				width, height, GetDownImage(m_animationCount), TRUE);

			m_prevDirection = Direction::eDown;
			break;
		case Direction::eLeft:

			DrawExtendGraph(x, y,
				width, height, GetLeftImage(m_animationCount), TRUE);

			m_prevDirection = Direction::eLeft;
			break;
		case Direction::eRight:

			DrawExtendGraph(x, y,
				width, height, GetRightImage(m_animationCount), TRUE);
			m_prevDirection = Direction::eRight;

			break;

		default:
			break;
		}
	}

	//
	///
	//	�ړ�	//
	void CharacterBase::MoveDirection(const MyApplication::AppController::Input input){

		
		this->Move(m_inputMove[input]);

	}

	//	�摜�̃Q�b�^�[	//

	//
	///
	int CharacterBase::GetUpImage(const int number)const{
		return m_imageTable[number].m_upImage;
	}

	//
	///
	int CharacterBase::GetDownImage(const int number)const{
		return m_imageTable[number].m_downImage;
	}

	//
	///
	int CharacterBase::GetLeftImage(const int number)const{
		return m_imageTable[number].m_leftImage;
	}

	//
	///
	int CharacterBase::GetRightImage(const int number)const{
		return m_imageTable[number].m_rightImage;
	}


	//	�摜�ǂݍ���	//
	void CharacterBase::SetImage(const CharacterBase::ImagePassTable& pass, const int number){
		m_imageTable[number].m_upImage		= LoadGraph(pass.m_upImagePass.c_str());		// ��
		m_imageTable[number].m_downImage	= LoadGraph(pass.m_downImagePass.c_str());		// ��
		m_imageTable[number].m_rightImage	= LoadGraph(pass.m_rightImagePass.c_str());		// �E
		m_imageTable[number].m_leftImage	= LoadGraph(pass.m_leftImagePass.c_str());		// ��
	}
}