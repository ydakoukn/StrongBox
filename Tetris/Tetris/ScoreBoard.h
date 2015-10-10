#pragma once
#include "ObjectBase.h"

namespace Object{
	class ScoreBoard :
		public ObjectBase
	{
	public:
		ScoreBoard();
		~ScoreBoard();

		void Render(HDC buffer, std::shared_ptr<Tetris::Stage>&)override;
		void Initialize()override;
		
		void ScoreOut(HDC buffer, int x, int y, int font, UINT color,LPCWSTR str);

	private:
		HBITMAP m_image;
	};
}
