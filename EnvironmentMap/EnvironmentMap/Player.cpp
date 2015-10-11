#include "Player.h"

namespace Character{

	

	const Player::ImagePassTable Player::m_imagePass[]{
		{ "Resources/Player/Up/Up1.png", "Resources/Player/Down/Down1.png", "Resources/Player/Left/Left1.png", "Resources/Player/Right/Right1.png"},
		{ "Resources/Player/Up/Up2.png", "Resources/Player/Down/Down2.png", "Resources/Player/Left/Left2.png", "Resources/Player/Right/Right2.png" },
		{ "Resources/Player/Up/Up3.png", "Resources/Player/Down/Down3.png", "Resources/Player/Left/Left3.png", "Resources/Player/Right/Right3.png" },
		{ "Resources/Player/Up/Up4.png", "Resources/Player/Down/Down4.png", "Resources/Player/Left/Left4.png", "Resources/Player/Right/Right4.png" },
	};


	Player::Player(){}

	Player::~Player(){}

	void Player::Initialize(){

		// �A�j���[�V�����ԍ��p
		m_animationCount = 0;
		// ����p
		m_waitAnimation = 300;

		// �Ƃ肠����������
		m_direction = Direction::eUp;
		m_prevDirection = Direction::eUp;

		// �摜�̏�����
		for (int i = 0; i < m_numberOfImage; i++)
		{
			this->SetImage(m_imagePass[i],i);
		}
	}


}// !namespace
