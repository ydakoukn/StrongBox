#ifndef DEF_SCENERANKING_H
#define DEF_SCENERANKING_H

#include "SceneBase.h"
/*

	�����L���O��ʊǗ��N���X

*/

namespace Scene{

	class SceneRanking :
		public SceneBase
	{
		public:
			SceneRanking(Tetris::GameManager& appManager);
			~SceneRanking();

			//	���N���X����̃I�[�o�[���C�h	//
			void Initialize()override;

			void UpDate()override;

			void Render(HDC buffer)override;

		public:

			// ���O�̓o�^
			static const std::string m_sceneName;

		private:
			// ����J����I�u�W�F�N�g
		

	};


}

#endif// !DEF_SCENERANKING_H