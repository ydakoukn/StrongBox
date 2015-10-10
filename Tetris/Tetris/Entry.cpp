/*
	�G���g���[�|�C���g
	�������炷�ׂĂ��͂��܂�

	�f�o�b�O�p�R���\�[���������ō쐬����Ă���

*/
#include <windows.h>
#include "Game.h"

//	�R���\�[���\���p
#include <io.h>
#include <fcntl.h>

// �R���\�[����ʃn���h���ۑ��p
int hConsole = 0;

///
// �R���\�[����ʍ쐬�p
void CreateConsoleWindow(){

	::AllocConsole();
	hConsole = ::_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *::_fdopen(hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);

}

///
// �R���\�[����ʏI���p
void CloseConsoleWindow(){
	::_close(hConsole);
}


///
// EntryPoint
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT){

	std::unique_ptr<Tetris::Game> game(new Tetris::Game(hInstance));

	if (game == nullptr) return -1;

	// �R���\�[����ʕ\��
	CreateConsoleWindow();

	// ���C������Go�I�I�I
	game->Run();

	// ���
	game.release();
	game.reset(nullptr);

	// �R���\�[���̏I��
	CloseConsoleWindow();
	// �A�v���̏I��
	return 0;
}