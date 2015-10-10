#include "ScoreBoard.h"

namespace Object{
	ScoreBoard::ScoreBoard()
	{
	}


	ScoreBoard::~ScoreBoard()
	{
		DeleteObject(m_image);
	}

	void ScoreBoard::Initialize(){
		//画像読み込み
		this->m_image = (HBITMAP)LoadImage(NULL, TEXT("Resource/Wall.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		this->IsInitialize(true);
	}

	void ScoreBoard::Render(HDC buffer, std::shared_ptr<Tetris::Stage>& stage){

		if (!m_isInitialize)return;

		//メモリデバイスコンテキストを作成
		HDC m_scoreboardBuffer;
		HDC m_scoreboadString;

		m_scoreboardBuffer = CreateCompatibleDC(buffer);

		SelectObject(m_scoreboardBuffer, m_image);

		const int x = 300;
		const int y = 150;
		const int width = 160;
		const int height = 50;

		BitBlt(buffer, x, y, width, height, m_scoreboardBuffer, 0, 0, SRCCOPY);

		DeleteDC(m_scoreboardBuffer);
	}

	void ScoreBoard::ScoreOut(HDC hdc, int x, int y, int font, UINT color,LPCWSTR str){
		HFONT hfont, oldfont;

		hfont = CreateFont(
			font,
			0,
			0,
			0,
			FW_DONTCARE,
			FALSE,
			FALSE,
			FALSE,
			SHIFTJIS_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			TEXT("メイリオ"));

		if (hfont == NULL)return;

		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, color);
		oldfont = (HFONT)SelectObject(hdc, hfont);

		TextOut(hdc, x, y, str, lstrlen(str));

		SelectObject(hdc, oldfont);
		DeleteObject(hfont);
	}
}
