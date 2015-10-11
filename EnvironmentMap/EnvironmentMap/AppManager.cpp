#include "AppManager.h"
#include "SceneGame.h"

namespace MyApplication{

	// ループ時に行う状態		//
	AppManager::eState AppManager::m_stateScene = eState::eInit;
	
	// 実際に繋ぐシーン		//
	std::shared_ptr<Scene::SceneBase> AppManager::m_pCurrentScene = nullptr;
	std::shared_ptr<Scene::SceneBase> AppManager::m_pNextScene = nullptr;

	// シーンを格納		//
	std::unordered_map<std::string, std::shared_ptr<Scene::SceneBase>> AppManager::m_pSceneData;


	AppManager::AppManager(){

		// ゲーム内のシーンを登録	//
		Register(std::make_shared<Scene::SceneGame>(*this));
		
		//	最初のスタートシーンの設定	//
		m_pCurrentScene = Find(Scene::SceneGame::m_sceneName);

	}

	AppManager::~AppManager(){
	}

	//
	///
	//	シーンの登録処理	//
	void AppManager::Register(std::shared_ptr<Scene::SceneBase> scene){

		// ここで連想配列にキーと要素を登録する
		m_pSceneData.insert(std::make_pair(scene->Name(), scene));
	}

	//
	///
	// シーン情報の削除	//
	void AppManager::Delete(const std::string& name){
		
		//	対応の名前のシーンを探す
		auto findScene = m_pSceneData.find(name);

		// 対応の名前のシーンがないなら何もしない	//
		if (findScene == m_pSceneData.end()) return;

		m_pSceneData.erase(findScene);
	}

	//
	///
	//	シーン情報を検索して取得	//
	std::shared_ptr<Scene::SceneBase> AppManager::Find(const std::string& name){

		auto findScene = m_pSceneData.find(name);
		if (findScene == m_pSceneData.end())return nullptr;

		return findScene->second;
	}


	//
	///
	// シーンを切り替える	//
	// 次に行くシーンの登録名	//
	void AppManager::ChangeScene(const ChangeSceneData& changeData){

		m_pNextScene = Find(changeData.m_sceneName);

	}

	//
	///
	// 初期化処理	//
	void AppManager::Initialize(){


		if (m_stateScene != eState::eInit)return;

		m_pCurrentScene->Initialize();	//初期化処理

		m_stateScene = eState::eStartUp;

	}

	//
	///
	// スタート時の処理	//
	void AppManager::StartUp(){


		if (m_stateScene != eState::eStartUp)return;

		m_pCurrentScene->StartUp();	// スタート時の処理

		m_stateScene = eState::eUpDate;

	}

	//
	///
	// 更新処理	//
	void AppManager::UpDate(){

		if (m_stateScene != eState::eUpDate)return;

		// 今のm_pCurrentManagementに入っている
		// シーケンスの更新処理に行く
		m_pCurrentScene->UpDate();


		m_stateScene = eState::eRender;

	}

	//
	///
	// 描画処理	//
	void AppManager::Render(){

		if (m_stateScene != eState::eRender)return;

		// 今のm_pCurrentManagementに入っている
		// シーケンスの描画処理に行く
		m_pCurrentScene->Render();

		m_stateScene = eState::eUpDate;
	}

	

	void AppManager::Main(){
		int fps = 0;

		while (fps > 60)
		{
			fps++;
		}

		this->Initialize();

		this->StartUp();
		
		this->Render();

		this->UpDate();


	}
}

