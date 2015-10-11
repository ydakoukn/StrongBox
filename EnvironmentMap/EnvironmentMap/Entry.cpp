#include "DxLib.h"
//	コンソール表示用
#include <io.h>
#include <fcntl.h>

//
#include "AppManager.h"


// コンソール表示用
int hConsole = 0;
void CreateConsoleWindow();
void CloseConsoleWindow();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//	ウィンドウのサイズ	//
	const int windowWidth	= 400;
	const int windowHeight	= 400;

	// コンソール表示用
	CreateConsoleWindow();

	ChangeWindowMode(TRUE),
	SetGraphMode(windowWidth, windowHeight, 32),
	DxLib_Init(),
	SetDrawScreen(DX_SCREEN_BACK);
	
	// エントリーポイント
	std::unique_ptr<MyApplication::AppManager> entry(new MyApplication::AppManager);

	// メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 &&
		ClearDrawScreen() == 0)
	{
		entry->Main();
	}

	DxLib_End();

	CloseConsoleWindow();

	return 0;        // ソフトの終了
}

// コンソール表示用
void CreateConsoleWindow()
{

	AllocConsole();
	hConsole = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *_fdopen(hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);
}

// 削除用
void CloseConsoleWindow()
{
	_close(hConsole);
}