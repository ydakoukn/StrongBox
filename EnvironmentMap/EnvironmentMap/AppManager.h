#ifndef DEF_APPMANAGER_H
#define DEF_APPMANAGER_H

#include "Include.h"

namespace Scene{
	class SceneBase;
}

namespace MyApplication{
	
	class AppManager
	{
		public:
			AppManager();
			~AppManager();

			struct ChangeSceneData{
				ChangeSceneData() = default;
				ChangeSceneData(const std::string& name) :
					m_sceneName(name){}

				std::string m_sceneName;
			};

			// ���ۂ̃��[�v
			void Main();

			// �o�^�̍폜
			static void Delete(const std::string& name);

			// �V�[���̐؂�ւ�
			void ChangeScene(const ChangeSceneData& changeNextScene);

		private:

			// �V�[���̓o�^
			static void Register(std::shared_ptr<Scene::SceneBase> scene);

			// �������Ď擾
			static std::shared_ptr<Scene::SceneBase> Find(const std::string& name);
			
			// ����������
			void Initialize();

			// �n�܂������̏���
			void StartUp();

			// �X�V����
			void UpDate();

			// �`�揈��
			void Render();

		private:
			//���݂̏�����ԁ@��
			typedef enum class _EState{

				eInit,
				eStartUp,
				eUpDate,
				eRender,

			}eState;

			static eState m_stateScene;
			
			static std::shared_ptr<Scene::SceneBase>m_pCurrentScene;
			static std::shared_ptr<Scene::SceneBase>m_pNextScene;

			static std::unordered_map <std::string, std::shared_ptr<Scene::SceneBase>> m_pSceneData;

			ChangeSceneData m_changeSceneData;

			
			
	};
}


#endif