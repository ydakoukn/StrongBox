#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

#include "CharacterBase.h"
#include "Map.h"
namespace Character{

	class Player :
		public CharacterBase
	{


		private:
			// �摜�p�X�p�e�[�u��
			static const ImagePassTable m_imagePass[];

		public:
			
			Player();
			~Player();

			void Initialize();

			
	};

}

#endif