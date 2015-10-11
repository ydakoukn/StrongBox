#include "SceneGame.h"

namespace Scene{

	// ���̃V�[���̖��O
	const std::string SceneGame::m_sceneName = "Game";

	// �摜����
	const unsigned int SceneGame::m_NumberOfImage = 1;
	

	SceneGame::SceneGame(MyApplication::AppManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneGame::~SceneGame(){}


	// ����������	//
	void SceneGame::Initialize(){
		
		// �}�b�v�̃|�C���^�̏�����
		m_pMap = std::make_shared<Map::Map>();

		// �v���C���[�̃|�C���^�̏�����
		m_pPlayer = std::make_shared<Character::Player>();
		
		// �G�̃|�C���^�[�̏�����
		m_pEnemy = std::make_shared<Character::Enemy>();

		m_pNavigation = std::make_shared<AI::NavigationAI>(m_pMap);

		// �؂̃|�C���^�[��������
		m_pObject = std::make_shared<Object::Tree>("Resources/Tree.png");

		// �R���g���[���[�̃|�C���^�̏�����
		m_pKey = std::make_shared<MyApplication::AppController>();

		m_pMap->Initialize();		// �}�b�v�̏�����
		
		m_pPlayer->Initialize();	// �v���C���[�̏�����

		m_pEnemy->Initialize();		// �G�̏�����

		m_pNavigation->IniInitialize();

		m_pObject->Initialize();	// ���͖؂̏�����

		// �ŏ��̕`��
		for (int i = 0; i < m_pMap->MapHeight(); i++)
		{
			for (int j = 0; j < m_pMap->MapWidth(); j++)
			{
				InitializeRender(j, i);

			}

		}
		
	}

	//
	///
	//	�X�^�[�g���̏���	//
	void SceneGame::StartUp(){

	}

	// �`�揈��	//
	void SceneGame::Render(){

		
	
		for (int i = 0; i < m_pMap->MapHeight(); i++)
		{
			for (int j = 0; j < m_pMap->MapWidth(); j++)
			{ 

				if (m_pMap->GetMap(j, i) != 1 )
				{
					
					m_pNavigation->Render(j,i,m_pMap->GetMap(j,i));
				}
				else if (m_pMap->GetMap(j,i) == 1)
				{

					m_pObject->SetStartPosition(j,i);

					// ���͖�
					m_pObject->Render();
				}
				
				
			}

		}
		// �v���C���[
		m_pPlayer->AnimationRender();

		// �G
		m_pEnemy->AnimationRender();
		
	}




	//	�X�V����	//
	void SceneGame::UpDate(){
		

		m_pPlayer->MoveDirection(m_pKey->KeyCheck());
		
		
	}

	//
	///
	//	�}�b�v��ɂ�����̑S�ĕ`��	//
	//	�ŏ��ɂ����g�p	//
	void SceneGame::InitializeRender(const float xx, const float yy){

		// �܂��͏��������Ă�
		if (!m_pMap->isCreate())return;

		Character::CharacterBase::Position position;

		switch (m_pMap->GetMap(yy, xx))
		{

		case 2:	//	�v���C���[	//

			position.x = xx;
			position.y = yy;
			m_pPlayer->SetStartPosition(position);
				
			break;

		case 3: //	�G	//
			position.x = xx;
			position.y = yy;
			m_pEnemy->SetStartPosition(position);
			
			break;

		default:
			break;
		}
		
	}

}

