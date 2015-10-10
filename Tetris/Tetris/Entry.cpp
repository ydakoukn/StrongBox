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

	std::unique_ptr<Tetris::Game> game(new Tetris::Game(hInstance));

	if (game == nullptr) return -1;

	// コンソール画面表示
	CreateConsoleWindow();

	// メイン部へGo！！！
	game->Run();

	// 解放
	game.release();
	game.reset(nullptr);

	// コンソールの終了
	CloseConsoleWindow();
	// アプリの終了
	return 0;
}