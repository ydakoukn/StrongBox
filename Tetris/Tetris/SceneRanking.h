#ifndef DEF_SCENERANKING_H
#define DEF_SCENERANKING_H

#include "SceneBase.h"
/*

	ランキング画面管理クラス

*/

namespace Scene{

	class SceneRanking :
		public SceneBase
	{
		public:
			SceneRanking(Tetris::GameManager& appManager);
			~SceneRanking();

			//	基底クラスからのオーバーライド	//
			void Initialize()override;

			void UpDate()override;

			void Render(HDC buffer)override;

		public:

			// 名前の登録
			static const std::string m_sceneName;

		private:
			// 非公開内包オブジェクト
		

	};


}

#endif// !DEF_SCENERANKING_H