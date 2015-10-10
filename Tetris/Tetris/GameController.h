#ifndef DEF_GAMECONTROLLER_H
#define DEF_GAMECONTROLLER_H
/*

	�Q�[�����̃R���g���[���[�N���X
	�V���O���g��
	��ɃL�[���͂Ƃ����󂯕t����


*/
#include "Include.h"
#include "OriginalLib\Singleton.h"
namespace Singleton{

	class GameController
	{
		private:
		
			friend OriginalLib::Singleton<GameController>;
	
		public:

			// �L�[���͗p�񋓌^
			enum class Type{
				eUp,
				eDown,
				eRight,
				eLeft,
				eSpace,
				eEnter,
				eEscape,
				eKeyW,
				eKeyA,
				eKeyS,
				eKeyD,
				eKeyZ,
				eKeyX,
				eKeyC,

				eNull,	// �����Ȃ����
			};

		public:
			// �Ή��̃L�[��񋓌^�ŕԂ�
			static GameController::Type GetEnumKey();

			// �Ή��̃L�[�𕶎���ŕԂ�
			static std::string GetStringKey();
			
			// �L�[���͂�����^�C�~���O�ŌĂ�
			static void InputKey();

			static void ResetWait();

			static void SetKeyType(GameController::Type type);
		
		private:

			GameController() = default;

		private:
			static const int MAX_WAIT;
			static int m_waitTime;
			// �L�[���͕ۑ��p
			static Type m_inputEnumKey;

			// ���͏��𕶎���ŕԂ����߂Ɏg�p
			static std::unordered_map <Type, std::string> m_inputStringKey;


	};
}// !namespace


#endif //!DEF_GAMECONTROLLER_H