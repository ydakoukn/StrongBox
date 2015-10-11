#include "SceneGame.h"

namespace Scene{

	// このシーンの名前
	const std::string SceneGame::m_sceneName = "Game";

	// 画像枚数
	const unsigned int SceneGame::m_NumberOfImage = 1;
	

	SceneGame::SceneGame(MyApplication::AppManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneGame::~SceneGame(){}


	// 初期化処理	//
	void SceneGame::Initialize(){
		
		// マップのポインタの初期化
		m_pMap = std::make_shared<Map::Map>();

		// プレイヤーのポインタの初期化
		m_pPlayer = std::make_shared<Character::Player>();
		
		// 敵のポインターの初期化
		m_pEnemy = std::make_shared<Character::Enemy>();

		m_pNavigation = std::make_shared<AI::NavigationAI>(m_pMap);

		// 木のポインターを初期化
		m_pObject = std::make_shared<Object::Tree>("Resources/Tree.png");

		// コントローラーのポインタの初期化
		m_pKey = std::make_shared<MyApplication::AppController>();

		m_pMap->Initialize();		// マップの初期化
		
		m_pPlayer->Initialize();	// プレイヤーの初期化

		m_pEnemy->Initialize();		// 敵の初期化

		m_pNavigation->IniInitialize();

		m_pObject->Initialize();	// 今は木の初期化

		// 最初の描画
		for (int i = 0; i < m_pMap->MapHeight(); i++)
		{
			for (int j = 0; j < m_pMap->MapWidth(); j++)
			{
				InitializeRender(j, i);

			}

		}
		
	}

	//
	///
	//	スタート時の処理	//
	void SceneGame::StartUp(){

	}

	// 描画処理	//
	void SceneGame::Render(){

		
	
		for (int i = 0; i < m_pMap->MapHeight(); i++)
		{
			for (int j = 0; j < m_pMap->MapWidth(); j++)
			{ 

				if (m_pMap->GetMap(j, i) != 1 )
				{
					
					m_pNavigation->Render(j,i,m_pMap->GetMap(j,i));
				}
				else if (m_pMap->GetMap(j,i) == 1)
				{

					m_pObject->SetStartPosition(j,i);

					// 今は木
					m_pObject->Render();
				}
				
				
			}

		}
		// プレイヤー
		m_pPlayer->AnimationRender();

		// 敵
		m_pEnemy->AnimationRender();
		
	}




	//	更新処理	//
	void SceneGame::UpDate(){
		

		m_pPlayer->MoveDirection(m_pKey->KeyCheck());
		
		
	}

	//
	///
	//	マップ上にあるもの全て描画	//
	//	最初にだけ使用	//
	void SceneGame::InitializeRender(const float xx, const float yy){

		// まずは初期化してね
		if (!m_pMap->isCreate())return;

		Character::CharacterBase::Position position;

		switch (m_pMap->GetMap(yy, xx))
		{

		case 2:	//	プレイヤー	//

			position.x = xx;
			position.y = yy;
			m_pPlayer->SetStartPosition(position);
				
			break;

		case 3: //	敵	//
			position.x = xx;
			position.y = yy;
			m_pEnemy->SetStartPosition(position);
			
			break;

		default:
			break;
		}
		
	}

}

