#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H

#include "CharacterBase.h"
#include "Map.h"
namespace Character{

	class Player :
		public CharacterBase
	{


		private:
			// 画像パス用テーブル
			static const ImagePassTable m_imagePass[];

		public:
			
			Player();
			~Player();

			void Initialize();

			
	};

}

#endif