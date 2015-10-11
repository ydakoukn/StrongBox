#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H
#include "Include.h"
/*
	ウィンドウ生成クラス

*/
namespace Win32{

	class Window
	{

		public:
			// 公開メンバ関数
			Window() = default;
			~Window();

			//ウィンドウの初期化
			// HWND型
			HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCWSTR);
			HWND GetWindowHandle()const;
		private:
			// 非公開メンバ変数
			HWND m_hWnd;
	};
}


#endif // !DEF_WINDOW_H