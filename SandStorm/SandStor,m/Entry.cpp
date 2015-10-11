/*
	エントリーポイント
	ここからすべてがはじまる

	デバッグ用コンソールもここで作成されている

*/
#include <windows.h>
#include "Game.h"

//	コンソール表示用
#include <io.h>
#include <fcntl.h>

// コンソール画面ハンドル保存用
int hConsole = 0;

///
// コンソール画面作成用
void CreateConsoleWindow(){

	::AllocConsole();
	hConsole = ::_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *::_fdopen(hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);

}

///
// コンソール画面終了用
void CloseConsoleWindow(){
	::_close(hConsole);
}


///
// EntryPoint
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT){

	std::unique_ptr<Win32::Game> entry(new Win32::Game(hInstance));

	if (entry == nullptr) return -1;
	

	CreateConsoleWindow();

	// メイン部へGo！！！
	entry->Run();

	// 解放
	entry.release();
	entry.reset(nullptr);

	// コンソールの終了
	CloseConsoleWindow();
	// アプリの終了
	return 0;
}