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
	//	����������	//
	void Game::Initialize(){
		// �Q�[���}�l�[�W���[�̏�����	//
		m_manager = std::make_shared<Tetris::GameManager>();
		m_manager->Initialize();

		HRESULT result = E_FAIL;

		// �E�B���h�E�̏�����	//
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
	// �O������Ăяo�� //
	int Game::Run(){

		// ����������
		this->Initialize();

		MSG msg = { 0 };
		
		// ���S�ɏ�����
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
				// WM_USER+1�̃S�[���ɼ������������ 
				SendMessage(this->m_hWnd, WM_USER + 1, 0, 0);
			}
		}
		
		// �I��
		return msg.wParam;
	} // !Game::Run()

	// �|�C���^�擾�p
	std::shared_ptr<Tetris::GameManager> Game::GameManager(){
		
		return Game::m_manager;

	}// !Game::GameManager()
	
	///
	//	�R�[���o�b�N�֐�	//
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{

		return Tetris::Game::GameManager()->MainProc(hWnd, Msg, wParam, lParam);

	}// !WindowProc()

}// !Tetris

