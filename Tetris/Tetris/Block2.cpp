#include "Block2.h"
/*

	��������
	��������
	��������
	��������
*/
namespace Block{

	Block2::Block2(){}

	Block2::~Block2(){}

	void Block2::Initialize(){


		// ���u���b�N
		const int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 },
		};

		// �u���b�N�̃R�s�[
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));

		this->IsInitialize(true);
	}
}