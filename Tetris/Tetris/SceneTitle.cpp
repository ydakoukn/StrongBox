#include "SceneTitle.h"
#include "SceneGame.h"
namespace Scene{

	// このシーンの名前
	const std::string SceneTitle::m_sceneName = "Title";


	SceneTitle::SceneTitle(Tetris::GameManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneTitle::~SceneTitle(){}

	///
	// 初期化処理	//
	void SceneTitle::Initialize(){
		// 動作確認用（消していいよｗｗｗ）
		std::cout << "title::Initialize()"<<std::endl;
		i = 0;
	}

	///
	//	更新処理	//
	void SceneTitle::UpDate(){
		// 動作確認用（消していいよｗｗｗ）////////////////////////////////////
		i++;
		std::cout << "title::UpDate()" << std::endl;
		if (i>200)
		{
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "シーン変わるわ" << std::endl;

			ChangeScene(
				Tetris::GameManager::ChangeSceneData(
				SceneGame::m_sceneName)); 
		}
		///////////////////////////////////////////////////////////////
		/*
		// シーン切り替えのやり方
		if(条件文)
		{
			ChangeScene(
			Tetris::GameManager::ChangeSceneData(
			Sceneクラス名::m_sceneName)); // 切り替えたいシーンのm_sceneNameを静的に呼びだす
		}
		*/
	}

	///
	// 描画処理	//
	void SceneTitle::Render(HDC buffer){

		// 動作確認用（消していいよｗｗｗ）
		std::cout << "title::Render(HDC buffer)" << std::endl;
	}

	

}
