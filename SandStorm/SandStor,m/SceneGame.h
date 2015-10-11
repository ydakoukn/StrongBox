#ifndef DEF_SCENEGAME_H
#define DEF_SCENEGAME_H
/*
	�Q�[���V�[���Ǘ��N���X
	�Q�[���V�[���̂��Ƃ͂����ɋL�q

*/
#include "SceneBase.h"
#include "Include.h"
#include "GameManager.h"

namespace Scene{

	class SceneGame :
		public SceneBase
	{
		public:
			// ���J�֐�

			SceneGame(Win32::GameManager& appManager);
			~SceneGame();

			//	���N���X����̃I�[�o�[���C�h	//
			void Initialize()override;

			void UpDate()override;
			
			void Render(HDC buffer)override;

		public:
			
			// ���O�̓o�^
			static const std::string m_sceneName;
			
		private:

	};

}

#endif // !DEF_SCENEGAME_H