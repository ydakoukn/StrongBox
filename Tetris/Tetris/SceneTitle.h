#ifndef DEF_SCENETITLE_H
#define DEF_SCENETITLE_H
/*
	�^�C�g���V�[���Ǘ��N���X
	�^�C�g���V�[���̂��Ƃ͂����ɋL�q

*/
#include "SceneBase.h"
#include "GameManager.h"

namespace Scene{

	class SceneTitle :
		public Scene::SceneBase
	{
		public:
			// ���J�֐�
			SceneTitle(Tetris::GameManager& appManager);
			~SceneTitle();

			//	���N���X����̃I�[�o�[���C�h	//
			void Initialize()override;
				
			void UpDate()override;

			void Render(HDC buffer)override;

		public:
			// ���J�ϐ�
			int i = 0;	// ����m�F�p�i�����Ă����悗�����j
			// ���O�̓o�^
			static const std::string m_sceneName;
	};
}


#endif // !DEF_SCENETITLE_H