#ifndef DEF_GAMEMANAGER_H
#define DEF_GAMEMANAGER_H
/*
	ゲームの進行管理クラス

*/

#include "Include.h"

namespace Scene{
	class SceneBase;
}
namespace Tetris{

	class GameManager{

		public:
			// 公開関数
			GameManager();
			~GameManager();

			//　シーン遷移用構造体
			struct ChangeSceneData{
				ChangeSceneData() = default;
				ChangeSceneData(const std::string& name) :
					m_sceneName(name){}
				std::string m_sceneName;
			};

			// 初期化用
			void Initialize();

			// 登録の削除
			static void Delete(const std::string& name);
			
			// シーンの切り替え
			void ChangeScene(const ChangeSceneData& changeNextScene);

			// コールバックから呼ばれる
			// 実際のメイン処理部
			LRESULT MainProc(const HWND hWnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam);
		
		private:
			// 非公開関数

			// シーンの登録
			static void Register(std::shared_ptr<Scene::SceneBase> scene);

			// 検索して取得
			static std::shared_ptr<Scene::SceneBase> Find(const std::string& name);

			// ゲームの初期化処理
			void GameInitialize();

			// ゲームの更新処理
			void GameUpDate();
	
			// ゲームの描画処理
			void GameRender(HDC buffer);

		private:
			// 非公開メンバ変数と列挙

			//現在の処理状態（列挙）
			enum class eGameState{

				eInitialize,
				eUpDate,
				eRender,

			};

			// 状態遷移用
			static eGameState m_stateScene;

			// 現在のシーンを格納用
			static std::shared_ptr<Scene::SceneBase>m_pCurrentScene;

			// 次のシーンを格納用
			static std::shared_ptr<Scene::SceneBase>m_pNextScene;

			// シーン情報格納用
			static std::unordered_map <std::string, std::shared_ptr<Scene::SceneBase>> m_pSceneData;

			// シーン遷移用
			ChangeSceneData m_changeSceneData;

	};

}

#endif //!DEF_GAMEMANAGER_H