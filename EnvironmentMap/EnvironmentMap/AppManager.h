#ifndef DEF_APPMANAGER_H
#define DEF_APPMANAGER_H

#include "Include.h"

namespace Scene{
	class SceneBase;
}

namespace MyApplication{
	
	class AppManager
	{
		public:
			AppManager();
			~AppManager();

			struct ChangeSceneData{
				ChangeSceneData() = default;
				ChangeSceneData(const std::string& name) :
					m_sceneName(name){}

				std::string m_sceneName;
			};

			// 実際のループ
			void Main();

			// 登録の削除
			static void Delete(const std::string& name);

			// シーンの切り替え
			void ChangeScene(const ChangeSceneData& changeNextScene);

		private:

			// シーンの登録
			static void Register(std::shared_ptr<Scene::SceneBase> scene);

			// 検索して取得
			static std::shared_ptr<Scene::SceneBase> Find(const std::string& name);
			
			// 初期化処理
			void Initialize();

			// 始まった時の処理
			void StartUp();

			// 更新処理
			void UpDate();

			// 描画処理
			void Render();

		private:
			//現在の処理状態　列挙
			typedef enum class _EState{

				eInit,
				eStartUp,
				eUpDate,
				eRender,

			}eState;

			static eState m_stateScene;
			
			static std::shared_ptr<Scene::SceneBase>m_pCurrentScene;
			static std::shared_ptr<Scene::SceneBase>m_pNextScene;

			static std::unordered_map <std::string, std::shared_ptr<Scene::SceneBase>> m_pSceneData;

			ChangeSceneData m_changeSceneData;

			
			
	};
}


#endif