#ifndef DEF_GAME_H
#define DEF_GAME_H
/*
	ゲームの進行役につなぐクラス

*/


#include "Include.h"
#include "Window.h"
#include "GameManager.h"

namespace Tetris{

	// コールバック関数
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	class Game{
		
		public:
			// 公開関数
			Game(HINSTANCE hInstance);
			~Game();

			// 外部からの呼び出し
			int Run();
			static std::shared_ptr<Tetris::GameManager> GameManager();
		private:
			// 非公開変数

			HWND		m_hWnd;			// デバイスの取得
			HINSTANCE	m_hInstance;    // インスタンスの取得

			static const unsigned int m_windowWidth;
			static const unsigned int m_windowHeight;
			static const unsigned int m_windowX;
			static const unsigned int m_windowY;

		private:
			// 非公開内包オブジェクト

			// std::unique<T> _uniqueHoge と　T* _uniqueHogeはほとんど一緒
			// std::shared<T> _sharedHoge と　T* _sharedHogeはほとんど一緒
			std::unique_ptr<Window::Window> m_window;
			static std::shared_ptr<Tetris::GameManager> m_manager;

		private:
			// 非公開関数
			
			// 初期化用
			void Initialize();


	};

} // !Tetris

#endif