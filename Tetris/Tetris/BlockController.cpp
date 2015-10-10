#include "BlockController.h"
#include "Block0.h"
#include "Block1.h"
#include "Block2.h"
#include "Block3.h"
#include "Block4.h"
#include "Block5.h"
#include "Block6.h"
#include "OriginalLib\Singleton.h"
#include "GameController.h"
#include <random>
namespace Block{

	std::shared_ptr<BlockBase> BlockController::m_pCurrentBlock = nullptr;
	std::shared_ptr<BlockBase> BlockController::m_pNextBlock = nullptr;

	BlockController::BlockController(){}


	BlockController::~BlockController(){}

	//
	/// ������
	void  BlockController::Initialize(){
		m_pCurrentBlock = this->GetRandamBlock();
		m_pNextBlock = this->GetRandamBlock();

		m_pCurrentBlock->Initialize();
		m_pNextBlock->Initialize();

		m_blockX = 0;
		m_blockY = 0;

	}

	//
	/// �L�[����
	/// switch���g��Ȃ��Ă��ł��邯�ǁA�ǂ�����`�H( ^^) _�U~~
	void BlockController::KeyControll(){

		if (Singleton::GameController::GetEnumKey() == Singleton::GameController::Type::eNull)return;
		switch (Singleton::GameController::GetEnumKey())
		{
			// (�L�E�ցE`)(�L�E�ցE`)(�L�E�ցE`)�g�����炢��������܂��񂪍Ō�ɂ��̂P�������Ă�������(�L�E�ցE`)(�L�E�ցE`)(�L�E�ցE`)�@//
			//Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);

			// �ǂ�Ŏ��̂��Ƃ��E�����ꂽ���̏����I
			case Singleton::GameController::Type::eRight:
				std::cout << "����" << std::endl;
				this->m_blockX += 1;

				break;
			// �܂��A�@���Ă����(^_-)-��
			case Singleton::GameController::Type::eLeft:
				this->m_blockX -= 1;

				break;
			// ��������������ˁH( *�L䇁M)
			case Singleton::GameController::Type::eDown:
				this->m_blockY += 1;

				break;

			case Singleton::GameController::Type::eSpace:

				this->m_pCurrentBlock->TurnRight();

				break;
			// (�B-`��-)
			case Singleton::GameController::Type::eUp:
				this->m_blockY -= 1;
				
				break;
			default:
				// �o�[�J�o�[�J //
				Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);
			
			break;
		}

		// �L�[���������͂���ĂȂ���Ԃɂ����|�t�)
		Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);
		// �厖�Ȃ͕̂��͋C�����ނ��Ƃ��I(�O���O)
		Singleton::GameController::ResetWait();
	}

	//
	///
	// �Ȃ�Ń|�C���g�^�ɂ��Ȃ�������(�L�E�ցE`)
	int BlockController::GetX()const{
		return this->m_blockX;
	}


	int BlockController::GetY()const{
		return this->m_blockY;
	}


	//
	/// �u���b�N�̐���
	std::shared_ptr<BlockBase> BlockController::GetRandamBlock()const{

		std::random_device randam;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(randam());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		std::uniform_int_distribution<> create(0, 6); 

		const int randamValue = create(randam);

		std::cout << randamValue << std::endl;

		switch (6)
		{
		case 0:

			return std::make_shared<Block0>();

		case 1:

			return std::make_shared<Block1>();
		case 2:

			return std::make_shared<Block2>();

		case 3:

			return std::make_shared<Block3>();
		case 4:

			return std::make_shared<Block4>();

		case 5:

			return std::make_shared<Block5>();
		case 6:

			return std::make_shared<Block6>();

		default:
				return nullptr;
			break;
		}

		return nullptr;
	}

}// !namespace