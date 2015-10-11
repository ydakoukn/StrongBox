#include "SceneGame.h"
#include "Include.h"

namespace Scene{

	// このシーンの名前
	const std::string SceneGame::m_sceneName = "Game";


	SceneGame::SceneGame(Win32::GameManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneGame::~SceneGame(){}


	// 初期化処理	//
	void SceneGame::Initialize(){

	
	
		
	}

	//	更新処理	//
	void SceneGame::UpDate(){
	

		
	}


	// 描画処理	//
	void SceneGame::Render(HDC buffer){



	}


}// !namespace

