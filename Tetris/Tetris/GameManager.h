#ifndef DEF_GAMEMANAGER_H
#define DEF_GAMEMANAGER_H
/*
	�Q�[���̐i�s�Ǘ��N���X

*/

#include "Include.h"

namespace Scene{
	class SceneBase;
}
namespace Tetris{

	class GameManager{

		public:
			// ���J�֐�
			GameManager();
			~GameManager();

			//�@�V�[���J�ڗp�\����
			struct ChangeSceneData{
				ChangeSceneData() = default;
				ChangeSceneData(const std::string& name) :
					m_sceneName(name){}
				std::string m_sceneName;
			};

			// �������p
			void Initialize();

			// �o�^�̍폜
			static void Delete(const std::string& name);
			
			// �V�[���̐؂�ւ�
			void ChangeScene(const ChangeSceneData& changeNextScene);

			// �R�[���o�b�N����Ă΂��
			// ���ۂ̃��C��������
			LRESULT MainProc(const HWND hWnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam);
		
		private:
			// ����J�֐�

			// �V�[���̓o�^
			static void Register(std::shared_ptr<Scene::SceneBase> scene);

			// �������Ď擾
			static std::shared_ptr<Scene::SceneBase> Find(const std::string& name);

			// �Q�[���̏���������
			void GameInitialize();

			// �Q�[���̍X�V����
			void GameUpDate();
	
			// �Q�[���̕`�揈��
			void GameRender(HDC buffer);

		private:
			// ����J�����o�ϐ��Ɨ�

			//���݂̏�����ԁi�񋓁j
			enum class eGameState{

				eInitialize,
				eUpDate,
				eRender,

			};

			// ��ԑJ�ڗp
			static eGameState m_stateScene;

			// ���݂̃V�[�����i�[�p
			static std::shared_ptr<Scene::SceneBase>m_pCurrentScene;

			// ���̃V�[�����i�[�p
			static std::shared_ptr<Scene::SceneBase>m_pNextScene;

			// �V�[�����i�[�p
			static std::unordered_map <std::string, std::shared_ptr<Scene::SceneBase>> m_pSceneData;

			// �V�[���J�ڗp
			ChangeSceneData m_changeSceneData;

	};

}

#endif //!DEF_GAMEMANAGER_H