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

			// 初期化用
			void Initialize();

		private:

			// 画像パス用テーブル
			static const ImagePassTable m_imagePass[];

			

	};


}

