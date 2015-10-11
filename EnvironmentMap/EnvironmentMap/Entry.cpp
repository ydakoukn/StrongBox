#include "DxLib.h"
//	�R���\�[���\���p
#include <io.h>
#include <fcntl.h>

//
#include "AppManager.h"


// �R���\�[���\���p
int hConsole = 0;
void CreateConsoleWindow();
void CloseConsoleWindow();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//	�E�B���h�E�̃T�C�Y	//
	const int windowWidth	= 400;
	const int windowHeight	= 400;

	// �R���\�[���\���p
	CreateConsoleWindow();

	ChangeWindowMode(TRUE),
	SetGraphMode(windowWidth, windowHeight, 32),
	DxLib_Init(),
	SetDrawScreen(DX_SCREEN_BACK);
	
	// �G���g���[�|�C���g
	std::unique_ptr<MyApplication::AppManager> entry(new MyApplication::AppManager);

	// ���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 &&
		ClearDrawScreen() == 0)
	{
		entry->Main();
	}

	DxLib_End();

	CloseConsoleWindow();

	return 0;        // �\�t�g�̏I��
}

// �R���\�[���\���p
void CreateConsoleWindow()
{

	AllocConsole();
	hConsole = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *_fdopen(hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);
}

// �폜�p
void CloseConsoleWindow()
{
	_close(hConsole);
}