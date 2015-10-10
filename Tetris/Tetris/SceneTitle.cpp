#include "SceneTitle.h"
#include "SceneGame.h"
namespace Scene{

	// ���̃V�[���̖��O
	const std::string SceneTitle::m_sceneName = "Title";


	SceneTitle::SceneTitle(Tetris::GameManager& appManager) :
		SceneBase(m_sceneName, appManager){}


	SceneTitle::~SceneTitle(){}

	///
	// ����������	//
	void SceneTitle::Initialize(){
		// ����m�F�p�i�����Ă����悗�����j
		std::cout << "title::Initialize()"<<std::endl;
		i = 0;
	}

	///
	//	�X�V����	//
	void SceneTitle::UpDate(){
		// ����m�F�p�i�����Ă����悗�����j////////////////////////////////////
		i++;
		std::cout << "title::UpDate()" << std::endl;
		if (i>200)
		{
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "�V�[���ς���" << std::endl;

			ChangeScene(
				Tetris::GameManager::ChangeSceneData(
				SceneGame::m_sceneName)); 
		}
		///////////////////////////////////////////////////////////////
		/*
		// �V�[���؂�ւ��̂���
		if(������)
		{
			ChangeScene(
			Tetris::GameManager::ChangeSceneData(
			Scene�N���X��::m_sceneName)); // �؂�ւ������V�[����m_sceneName��ÓI�ɌĂт���
		}
		*/
	}

	///
	// �`�揈��	//
	void SceneTitle::Render(HDC buffer){

		// ����m�F�p�i�����Ă����悗�����j
		std::cout << "title::Render(HDC buffer)" << std::endl;
	}

	

}
