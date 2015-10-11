#include "Window.h"
#include "Game.h"

namespace Win32{

	Window::~Window()
	{
	}

	HRESULT Window::InitWindow(HINSTANCE hInstance,
		INT iX, INT iY, INT iWidth, INT iHeight, LPCWSTR WindowName)
	{
		WNDCLASSEX wc;

		SecureZeroMemory(&wc, sizeof(wc));

		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = Win32::WindowProc;

		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);

		wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		wc.lpszClassName = WindowName;
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		RegisterClassEx(&wc);


		this->m_hWnd = CreateWindow(
			//WS_EX_COMPOSITED,
			WindowName,WindowName,
			WS_OVERLAPPED | WS_SYSMENU,
			iX,	// x
			iY,	// y
			// �E�B���h�E�̂ӂ����܂߂�����
			(iX+iWidth + 10) + (GetSystemMetrics(SM_CXDLGFRAME) * 2),
			// �E�B���h�E�̂ӂ����܂߂��c��
			(iY+iHeight + 10)+ (GetSystemMetrics(SM_CXDLGFRAME) * 2)+ GetSystemMetrics(SM_CYCAPTION),
			NULL, NULL,hInstance, NULL);
		
		
		ShowWindow(this->m_hWnd, SW_SHOW);
		UpdateWindow(this->m_hWnd);

		// �쐬�����E�B���h�E����Ԃ�
		return S_OK;
	}

	HWND Window::GetWindowHandle()const{
		return this->m_hWnd;
	}
}
