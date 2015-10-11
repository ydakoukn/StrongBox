#ifndef DEF_GAME_H
#define DEF_GAME_H
/*
	�Q�[���̐i�s���ɂȂ��N���X

*/


#include "Include.h"
#include "Window.h"
#include "GameManager.h"

namespace Win32{

	// �R�[���o�b�N�֐�
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	class Game{
		
		public:
			// ���J�֐�
			Game(HINSTANCE hInstance);
			~Game();

			// �O������̌Ăяo��
			int Run();
			static std::shared_ptr<Win32::GameManager> GameManager();
		private:
			// ����J�ϐ�

			HWND		m_hWnd;			// �f�o�C�X�̎擾
			HINSTANCE	m_hInstance;    // �C���X�^���X�̎擾

			static const unsigned int m_windowWidth;
			static const unsigned int m_windowHeight;
			static const unsigned int m_windowX;
			static const unsigned int m_windowY;

		private:
			// ����J����I�u�W�F�N�g

			// std::unique<T> _uniqueHoge �Ɓ@T* _uniqueHoge�͂قƂ�ǈꏏ
			// std::shared<T> _sharedHoge �Ɓ@T* _sharedHoge�͂قƂ�ǈꏏ
			std::unique_ptr<Win32::Window> m_window;
			static std::shared_ptr<Win32::GameManager> m_manager;

		private:
			// ����J�֐�
			
			// �������p
			void Initialize();


	};

} // !Tetris

#endif