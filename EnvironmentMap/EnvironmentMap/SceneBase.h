#ifndef DEF_SCENEBASE_H
#define DEF_SCENEBASE_H
#include "AppManager.h"
#include "Include.h"

namespace Scene{

	class SceneBase
	{
		
		public:
			
			SceneBase() = default;

			SceneBase(const std::string& name, MyApplication::AppManager& scene) :
				m_name(name),
				m_appManager(scene){}

			virtual ~SceneBase() = default;

			// ����������
			virtual void Initialize() = 0;

			// �X�^�[�g���̏���
			virtual void StartUp() = 0;

			// �X�V����
			virtual void UpDate() = 0;

			// �`�揈��
			virtual void Render() = 0;

			const std::string Name()const{ return m_name; }

		protected:

			void ChangeScene(
				const MyApplication::AppManager::ChangeSceneData& changeSceneData){
				m_appManager.ChangeScene(changeSceneData);
			}

		private:

			const std::string m_name;
			MyApplication::AppManager& m_appManager;


	};

}

#endif