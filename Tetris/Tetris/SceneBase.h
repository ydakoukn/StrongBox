#ifndef DEF_SCENEBASE_H
#define DEF_SCENEBASE_H
/*

	シーンクラス基底クラス
	新しくシーンを作るときは必ず継承する

*/
#include "GameManager.h"
#include "Include.h"

namespace Scene{

	class SceneBase
	{

		public:

			SceneBase() = default;

			SceneBase(const std::string& name, Tetris::GameManager& scene) :
				m_name(name),
				m_gameManager(scene){}

			virtual ~SceneBase() = default;

			// 初期化処理
			virtual void Initialize() = 0;

			// 更新処理
			virtual void UpDate() = 0;

			// 描画処理
			virtual void Render(HDC buffer) = 0;

			const std::string Name()const{ return m_name; }

		protected:

			void ChangeScene(
				const Tetris::GameManager::ChangeSceneData& changeSceneData){
				m_gameManager.ChangeScene(changeSceneData);
			}

		private:

			const std::string m_name;
			Tetris::GameManager& m_gameManager;
	};

}// !Scene

#endif //DEF_SCENEBASE_H