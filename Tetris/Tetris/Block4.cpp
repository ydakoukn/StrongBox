#include "Block4.h"

//
namespace Block{

	Block4::Block4(){}

	Block4::~Block4(){}

	void Block4::Initialize(){


		// 仮ブロック
		const int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 },
		};

		// ブロックのコピー
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));

		this->IsInitialize(true);
	}
}

