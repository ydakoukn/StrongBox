#include "SceneGame.h"
#include "Include.h"

namespace Scene{

	// ���̃V�[���̖��O
	const std::string SceneGame::m_sceneName = "Game";


	SceneGame::SceneGame(Win32::GameManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneGame::~SceneGame(){}


	// ����������	//
	void SceneGame::Initialize(){

	
	
		
	}

	//	�X�V����	//
	void SceneGame::UpDate(){
	

		
	}


	// �`�揈��	//
	void SceneGame::Render(HDC buffer){



	}


}// !namespace

