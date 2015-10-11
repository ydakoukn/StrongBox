#ifndef DEF_SCENEGAME_H
#define DEF_SCENEGAME_H
/*
	ゲームシーン管理クラス
	ゲームシーンのことはここに記述

*/
#include "SceneBase.h"
#include "Include.h"
#include "GameManager.h"

namespace Scene{

	class SceneGame :
		public SceneBase
	{
		public:
			// 公開関数

			SceneGame(Win32::GameManager& appManager);
			~SceneGame();

			//	基底クラスからのオーバーライド	//
			void Initialize()override;

			void UpDate()override;
			
			void Render(HDC buffer)override;

		public:
			
			// 名前の登録
			static const std::string m_sceneName;
			
		private:

	};

}

#endif // !DEF_SCENEGAME_H