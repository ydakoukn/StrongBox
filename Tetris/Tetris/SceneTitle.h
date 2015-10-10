#ifndef DEF_SCENETITLE_H
#define DEF_SCENETITLE_H
/*
	タイトルシーン管理クラス
	タイトルシーンのことはここに記述

*/
#include "SceneBase.h"
#include "GameManager.h"

namespace Scene{

	class SceneTitle :
		public Scene::SceneBase
	{
		public:
			// 公開関数
			SceneTitle(Tetris::GameManager& appManager);
			~SceneTitle();

			//	基底クラスからのオーバーライド	//
			void Initialize()override;
				
			void UpDate()override;

			void Render(HDC buffer)override;

		public:
			// 公開変数
			int i = 0;	// 動作確認用（消していいよｗｗｗ）
			// 名前の登録
			static const std::string m_sceneName;
	};
}


#endif // !DEF_SCENETITLE_H