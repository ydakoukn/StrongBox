#include "Block0.h"

namespace Block{

	Block0::Block0(){}

	Block0::~Block0(){}

	void Block0::Initialize(){

	
		// ���u���b�N
		const int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 },
		};

		// �u���b�N�̃R�s�[
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));

		this->IsInitialize(true);
	}
}
