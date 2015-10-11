#include "AppManager.h"
#include "SceneGame.h"

namespace MyApplication{

	// ���[�v���ɍs�����		//
	AppManager::eState AppManager::m_stateScene = eState::eInit;
	
	// ���ۂɌq���V�[��		//
	std::shared_ptr<Scene::SceneBase> AppManager::m_pCurrentScene = nullptr;
	std::shared_ptr<Scene::SceneBase> AppManager::m_pNextScene = nullptr;

	// �V�[�����i�[		//
	std::unordered_map<std::string, std::shared_ptr<Scene::SceneBase>> AppManager::m_pSceneData;


	AppManager::AppManager(){

		// �Q�[�����̃V�[����o�^	//
		Register(std::make_shared<Scene::SceneGame>(*this));
		
		//	�ŏ��̃X�^�[�g�V�[���̐ݒ�	//
		m_pCurrentScene = Find(Scene::SceneGame::m_sceneName);

	}

	AppManager::~AppManager(){
	}

	//
	///
	//	�V�[���̓o�^����	//
	void AppManager::Register(std::shared_ptr<Scene::SceneBase> scene){

		// �����ŘA�z�z��ɃL�[�Ɨv�f��o�^����
		m_pSceneData.insert(std::make_pair(scene->Name(), scene));
	}

	//
	///
	// �V�[�����̍폜	//
	void AppManager::Delete(const std::string& name){
		
		//	�Ή��̖��O�̃V�[����T��
		auto findScene = m_pSceneData.find(name);

		// �Ή��̖��O�̃V�[�����Ȃ��Ȃ牽�����Ȃ�	//
		if (findScene == m_pSceneData.end()) return;

		m_pSceneData.erase(findScene);
	}

	//
	///
	//	�V�[�������������Ď擾	//
	std::shared_ptr<Scene::SceneBase> AppManager::Find(const std::string& name){

		auto findScene = m_pSceneData.find(name);
		if (findScene == m_pSceneData.end())return nullptr;

		return findScene->second;
	}


	//
	///
	// �V�[����؂�ւ���	//
	// ���ɍs���V�[���̓o�^��	//
	void AppManager::ChangeScene(const ChangeSceneData& changeData){

		m_pNextScene = Find(changeData.m_sceneName);

	}

	//
	///
	// ����������	//
	void AppManager::Initialize(){


		if (m_stateScene != eState::eInit)return;

		m_pCurrentScene->Initialize();	//����������

		m_stateScene = eState::eStartUp;

	}

	//
	///
	// �X�^�[�g���̏���	//
	void AppManager::StartUp(){


		if (m_stateScene != eState::eStartUp)return;

		m_pCurrentScene->StartUp();	// �X�^�[�g���̏���

		m_stateScene = eState::eUpDate;

	}

	//
	///
	// �X�V����	//
	void AppManager::UpDate(){

		if (m_stateScene != eState::eUpDate)return;

		// ����m_pCurrentManagement�ɓ����Ă���
		// �V�[�P���X�̍X�V�����ɍs��
		m_pCurrentScene->UpDate();


		m_stateScene = eState::eRender;

	}

	//
	///
	// �`�揈��	//
	void AppManager::Render(){

		if (m_stateScene != eState::eRender)return;

		// ����m_pCurrentManagement�ɓ����Ă���
		// �V�[�P���X�̕`�揈���ɍs��
		m_pCurrentScene->Render();

		m_stateScene = eState::eUpDate;
	}

	

	void AppManager::Main(){
		int fps = 0;

		while (fps > 60)
		{
			fps++;
		}

		this->Initialize();

		this->StartUp();
		
		this->Render();

		this->UpDate();


	}
}

