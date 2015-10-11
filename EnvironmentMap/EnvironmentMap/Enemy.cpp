#include "Enemy.h"

namespace Character{

	const Enemy::ImagePassTable Enemy::m_imagePass[]{
		{ "Resources/Enemy/Up/Enemy1.png", "Resources/Enemy/Down/Enemy1.png", "Resources/Enemy/Left/Enemy1.png", "Resources/Enemy/Right/Enemy1.png"},
		{ "Resources/Enemy/Up/Enemy2.png", "Resources/Enemy/Down/Enemy2.png", "Resources/Enemy/Left/Enemy2.png", "Resources/Enemy/Right/Enemy2.png" },
		{ "Resources/Enemy/Up/Enemy3.png", "Resources/Enemy/Down/Enemy3.png", "Resources/Enemy/Left/Enemy3.png", "Resources/Enemy/Right/Enemy3.png" },
		{ "Resources/Enemy/Up/Enemy4.png", "Resources/Enemy/Down/Enemy4.png", "Resources/Enemy/Left/Enemy4.png", "Resources/Enemy/Right/Enemy4.png" },
	};

	Enemy::Enemy(){}


	Enemy::~Enemy(){}

	void Enemy::Initialize(){

		// アニメーション番号用
		m_animationCount = 0;
		// 制御用
		m_waitAnimation = 300;

		// とりあえず初期化
		m_direction = Direction::eDown;
		m_prevDirection = Direction::eNull;

		// 画像の初期化
		for (int i = 0; i < m_numberOfImage; i++)
		{
			this->SetImage(m_imagePass[i], i);
		}
	}



}
