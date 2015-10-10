#ifndef DEF_SINGLETON_H
#define DEF_SINGLETON_H
/*
	�V���O���g���쐬�e���v���[�g�N���X
	Singleton<����̃N���X��>�ł��̃|�C���^���V���O���g���Ƃ��Ĉ����܂��B
	GetPtr()��GetRef()���g���Ύ���N���X�̃����o�ɃA�N�Z�X�\

	ver 1.0
	�����:Ko Hashimoto
*/
namespace OriginalLib{

	template<class TYPE>
	class Singleton
	{

		private:
			// �e���v���[�g�����^���g���̂ɕK�v
			typedef TYPE Style;

		public:

			/*
				�֐���:Create
				�^    : void
				�@�\  : �w��N���X�̃|�C���^�̃A�h���X��private�A�h���X�Ɋm�ۂ���B
				       ���łɊm�ۍς݂Ȃ�m�ۂ��Ȃ�
			*/
			static void Create(){

				if (m_instance != nullptr) return;

				m_instance = new Style();
			}

			 /*
				�֐��� :Destroy
				�^    : void
				�@�\  : �|�C���^���̉��
				       �m�ۂ��Ă��Ȃ��A�������͂��łɍ폜�ς݂Ȃ牽�����Ȃ�
			*/
			static void Destroy(){

				if (m_instance == nullptr) return;

				delete m_instance;
				m_instance = nullptr;
			}

			 /*
				�֐��� :GetPtr
				�^    : �e���v���[�g�����|�C���^�^
				�@�\  : Create�Ŋm�ۂ����C���X�^���X�̃|�C���^��Ԃ��܂��B
			*/
			static Style* GetPtr(){

				if (m_instance == nullptr) return nullptr;

				return m_instance;
			}

			/*
				�֐��� :GetRef
				�^    : �e���v���[�g�����Q�ƌ^
				�@�\  : Create�Ŋm�ۂ����C���X�^���X�̎Q�Ƃ�Ԃ��܂��B
			*/
			static Style& GetRef(){
				if (m_instance == nullptr)
				{
					std::cerr << "Don't Call Create()" << std::endl;
				}
				return *m_instance;
			}

			/*
				�֐��� :IsCreated
				�^    : �X�^�e�B�b�N�u�[���^�֐�
				�@�\  : Create���Ăяo����Ă����true�ƂȂ�
			*/
			static bool IsCreated(){
				if (m_instance != nullptr)
				{
					return true;
				}
				return false;
			}


		private:
			/*
				�O���ł̃C���X�^���X������点�Ȃ�
			*/
			Singleton() = default;
			virtual ~Singleton() = default;
		
		private:
			
			/*
				�����FCreate���̃|�C���^�m�ۗp�B�����l��[nullptr]
			*/
			static Style* Singleton<TYPE>::m_instance;
	};

	template<class TYPE>
	typename Singleton<TYPE>::Style* Singleton<TYPE>::m_instance = nullptr;

}


#endif// !DEF_SINGLETON_H