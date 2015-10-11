#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H
#include "Include.h"
/*
	�E�B���h�E�����N���X

*/
namespace Win32{

	class Window
	{

		public:
			// ���J�����o�֐�
			Window() = default;
			~Window();

			//�E�B���h�E�̏�����
			// HWND�^
			HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCWSTR);
			HWND GetWindowHandle()const;
		private:
			// ����J�����o�ϐ�
			HWND m_hWnd;
	};
}


#endif // !DEF_WINDOW_H