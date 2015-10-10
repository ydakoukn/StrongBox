#include "Game.h"
#include "Window.h"
#include "Include.h"
#include "Define.h"


namespace Tetris{

	std::shared_ptr<Tetris::GameManager> Game::m_manager = nullptr;

	Game::Game(HINSTANCE hInstance):
		m_hInstance(hInstance){}
	Game::~Game(){}

	//
	///
	//	初期化処理	//
	void Game::Initialize(){
		// ゲームマネージャーの初期化	//
		m_manager = std::make_shared<Tetris::GameManager>();
		m_manager->Initialize();

		HRESULT result = E_FAIL;

		// ウィンドウの初期化	//
		m_window = std::make_unique<Window::Window>();

		result = m_window->InitWindow(m_hInstance, 0, 0, 500, 450, L"Tetris");
		if (result != S_OK)
		{
			DEBUG_BOX(L"Could not Window::InitWindow().\nPlease end Application.")
		}

		this->m_hWnd = m_window->GetWindowHandle();

			
	} // !Game::Initialize()

	//
	///
	// 外部から呼び出す //
	int Game::Run(){

		// 初期化処理
		this->Initialize();

		MSG msg = { 0 };
		
		// 安全に初期化
		SecureZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				// WM_USER+1のゴールにｼｭｳｳｳｳｳｳｳｳｳｳｳ 
				SendMessage(this->m_hWnd, WM_USER + 1, 0, 0);
			}
		}
		
		// 終了
		return msg.wParam;
	} // !Game::Run()

	// ポインタ取得用
	std::shared_ptr<Tetris::GameManager> Game::GameManager(){
		
		return Game::m_manager;

	}// !Game::GameManager()
	
	///
	//	コールバック関数	//
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{

		return Tetris::Game::GameManager()->MainProc(hWnd, Msg, wParam, lParam);

	}// !WindowProc()

}// !Tetris

