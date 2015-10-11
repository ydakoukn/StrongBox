#ifndef DEF_SCENEGAME_H
#define DEF_SCENEGAME_H

#include "AppController.h"
#include "SceneBase.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "NavigationAI.h"
#include "ObjectBase.h"
#include "Tree.h"
namespace Scene{

	class SceneGame :
		public SceneBase
	{

		
		public:
			SceneGame(MyApplication::AppManager& appManager);
			~SceneGame();

			void Initialize()override;

			void StartUp()override;

			void UpDate()override;
			
			void Render()override;

		public:

			static const std::string m_sceneName;

		private:

			// マップ上にあるもの全部描画
			void InitializeRender(const float xx, const float yy);


		private:
			std::shared_ptr<Map::Map> m_pMap;

			std::shared_ptr<Character::Enemy>  m_pEnemy;
			
			std::shared_ptr<AI::NavigationAI> m_pNavigation;

			std::shared_ptr<Character::Player> m_pPlayer;

			std::shared_ptr<Object::ObjectBase> m_pObject;

			std::shared_ptr<MyApplication::AppController> m_pKey;



			// 画像ハンドル
			int m_imageTable[5];

			static const unsigned int m_NumberOfImage;

			


	};



}

#endif