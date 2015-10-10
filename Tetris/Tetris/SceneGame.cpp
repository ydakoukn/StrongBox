#include "SceneGame.h"
#include "SceneTitle.h"
#include "Include.h"
#include "GameController.h"
namespace Scene{
	
	// ���̃V�[���̖��O
	const std::string SceneGame::m_sceneName = "Game";

	SceneGame::State SceneGame::m_state = State::eNull;
	SceneGame::SceneGame(Tetris::GameManager& appManager) :
		SceneBase(m_sceneName, appManager),
		m_blockNumber(1),
		m_spaceNumber(0){}


	SceneGame::~SceneGame(){}


	// ����������	//
	void SceneGame::Initialize(){
	
		m_stage = std::make_shared<Tetris::Stage>();
		m_wall  = std::make_unique<Object::Wall>();
		m_block = std::make_shared<Block::BlockController>();
		m_score = std::make_unique<Object::ScoreBoard>();
		m_nextDisplay = std::make_shared<Tetris>
		// ���ꂼ��̏�����
		m_stage->Initialize();
		m_wall->Initialize();
		m_block->Initialize();
		m_score->Initialize();
	}

	//	�X�V����	//
	void SceneGame::UpDate(){
		
		m_stage->ClearStage();

		this->BlockFall();
		this->BlockStop();
		this->BlockChange();
		

		
	}


	// �`�揈��	//
	void SceneGame::Render(HDC buffer){
		static int cnt;
		WCHAR str[12];
		cnt++;

		m_stage->ClearDraw(buffer);
		m_score->Render(buffer,m_stage);
		m_score->ScoreOut(buffer, 350, 150, 60, RGB(255,255,255),_itow(cnt,str,10));

		for (int i = 0; i < STAGE_HEIGHT; i++)
		{
			for (int j = 0; j < STAGE_WIDTH; j++)
			{

				switch (m_stage->NowStageNumber(j, i))
				{
				case 1:
				
					m_stage->DrawBlock(buffer, j, i);
					break;

				
				}

			}

		}
		
		m_stage->StageInfoDraw(buffer);
		m_wall->Render(buffer, m_stage);

	}

	// ����K������
	int cnt = 0;

	int down = 0;
	/*	�u���b�N�������鏈��	*/
	void SceneGame::BlockFall(){

		m_block->KeyControll();

		if (cnt >= 1000){
			down++;
			cnt = 0;
		}

		const int y = down + m_block->GetY();
		m_stage->MoveBlock(m_block->m_pCurrentBlock, m_block->GetX(), y);
		cnt++;

		// ���̏�����������
		this->m_state = State::eBlockStop;


	}
	/*	�u���b�N���~�܂鏈��	*/
	void SceneGame::BlockStop(){

		this->m_state = State::eBlockChange;
	}

	/*	�u���b�N��ς��鏈��	*/
	void SceneGame::BlockChange(){


		this->m_state = State::eBlockFall;
	}

}// !namespace

