#pragma once

#include "CharacterBase.h"
#include "NavigationAI.h"

namespace Character
{
	class Enemy :
		public CharacterBase
	{

		
		public:
			Enemy();
			~Enemy();

			// �������p
			void Initialize();

		private:

			// �摜�p�X�p�e�[�u��
			static const ImagePassTable m_imagePass[];

			

	};


}

