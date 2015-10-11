#ifndef DEF_SCENEBASE_H
#define DEF_SCENEBASE_H
#include "AppManager.h"
#include "Include.h"

namespace Scene{

	class SceneBase
	{
		
		public:
			
			SceneBase() = default;

			SceneBase(const std::string& name, MyApplication::AppManager& scene) :
				m_name(name),
				m_appManager(scene){}

			virtual ~SceneBase() = default;

			// 初期化処理
			virtual void Initialize() = 0;

			// スタート時の処理
			virtual void StartUp() = 0;

			// 更新処理
			virtual void UpDate() = 0;

			// 描画処理
			virtual void Render() = 0;

			const std::string Name()const{ return m_name; }

		protected:

			void ChangeScene(
				const MyApplication::AppManager::ChangeSceneData& changeSceneData){
				m_appManager.ChangeScene(changeSceneData);
			}

		private:

			const std::string m_name;
			MyApplication::AppManager& m_appManager;


	};

}

#endif