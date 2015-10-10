#ifndef DEF_SCENEGAME_H
#define DEF_SCENEGAME_H
/*
	�Q�[���V�[���Ǘ��N���X
	�Q�[���V�[���̂��Ƃ͂����ɋL�q

*/
#include "SceneBase.h"
#include "Include.h"
#include "GameManager.h"
#include "Stage.h"
#include "Wall.h"
#include "ScoreBoard.h"
#include "BlockController.h"
#include "NextBlockDisplay.h"
#include <wchar.h>
namespace Scene{

	class SceneGame :
		public SceneBase
	{
		public:
			// ���J�֐�

			SceneGame(Tetris::GameManager& appManager);
			~SceneGame();

			//	���N���X����̃I�[�o�[���C�h	//
			void Initialize()override;

			void UpDate()override;
			
			void Render(HDC buffer)override;

		public:
			// ���J�ϐ�&�������
			int m_blockMovecount = 0;
			int m_blockMove_y = 0;
			int m_blockMove_x = 0;			
			// ���O�̓o�^
			static const std::string m_sceneName;
			
		private:

			void BlockFall();
			void BlockStop();
			void BlockChange();

		private:

			enum class State{
				eBlockFall,
				eBlockStop,
				eBlockChange,
				eNull,
			};
		private:
			// ����J����I�u�W�F�N�g
			std::shared_ptr<Tetris::Stage>    m_stage;
			std::unique_ptr<Object::Wall>     m_wall;
			std::shared_ptr<Block::BlockController> m_block;
			std::unique_ptr<Object::ScoreBoard> m_score;
			std::shared_ptr<Tetris::NextBlockDisplay>m_nextDisplay;

		private:
			const int m_blockNumber;
			const int m_spaceNumber;

			static State m_state;
	};
	
	// �f�o�b�O�p
	void DebugStage();
}

#endif // !DEF_SCENEGAME_H