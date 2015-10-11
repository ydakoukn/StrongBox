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

	std::unique_ptr<Win32::Game> entry(new Win32::Game(hInstance));

	if (entry == nullptr) return -1;
	

	CreateConsoleWindow();

	// ���C������Go�I�I�I
	entry->Run();

	// ���
	entry.release();
	entry.reset(nullptr);

	// �R���\�[���̏I��
	CloseConsoleWindow();
	// �A�v���̏I��
	return 0;
}