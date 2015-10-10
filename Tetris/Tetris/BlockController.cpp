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
	/// 初期化
	void  BlockController::Initialize(){
		m_pCurrentBlock = this->GetRandamBlock();
		m_pNextBlock = this->GetRandamBlock();

		m_pCurrentBlock->Initialize();
		m_pNextBlock->Initialize();

		m_blockX = 0;
		m_blockY = 0;

	}

	//
	/// キー入力
	/// switch文使わなくてもできるけど、どうする～？( ^^) _旦~~
	void BlockController::KeyControll(){

		if (Singleton::GameController::GetEnumKey() == Singleton::GameController::Type::eNull)return;
		switch (Singleton::GameController::GetEnumKey())
		{
			// (´・ω・`)(´・ω・`)(´・ω・`)使いずらいかもしれませんが最後にこの１文を入れてください(´・ω・`)(´・ω・`)(´・ω・`)　//
			//Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);

			// 読んで字のごとく右押された時の処理！
			case Singleton::GameController::Type::eRight:
				std::cout << "きた" << std::endl;
				this->m_blockX += 1;

				break;
			// まあ、察してくれよ(^_-)-☆
			case Singleton::GameController::Type::eLeft:
				this->m_blockX -= 1;

				break;
			// いい加減いいよね？( *´艸｀)
			case Singleton::GameController::Type::eDown:
				this->m_blockY += 1;

				break;

			case Singleton::GameController::Type::eSpace:

				this->m_pCurrentBlock->TurnRight();

				break;
			// (。-`ω-)
			case Singleton::GameController::Type::eUp:
				this->m_blockY -= 1;
				
				break;
			default:
				// バーカバーカ //
				Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);
			
			break;
		}

		// キーを何も入力されてない状態にすんべ|дﾟ)
		Singleton::GameController::SetKeyType(Singleton::GameController::Type::eNull);
		// 大事なのは雰囲気をつかむことだ！(＾◇＾)
		Singleton::GameController::ResetWait();
	}

	//
	///
	// なんでポイント型にしなかった俺(´・ω・`)
	int BlockController::GetX()const{
		return this->m_blockX;
	}


	int BlockController::GetY()const{
		return this->m_blockY;
	}


	//
	/// ブロックの生成
	std::shared_ptr<BlockBase> BlockController::GetRandamBlock()const{

		std::random_device randam;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(randam());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
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