#pragma once
#include "ObjectBase.h"

namespace Object{
	
	class Wall :
		public ObjectBase
	{
		public:
			Wall();
			~Wall();
			
			void Render(HDC buffer, std::shared_ptr<Tetris::Stage>&)override;
			void Initialize()override;

			

		private:
			void DrawWall(HDC buffer);

		private:
			static const int m_wallNumber;
			HBITMAP m_wallImage; // ‰æ‘œ•Û‘¶—p
	};
}


