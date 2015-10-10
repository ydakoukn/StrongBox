#include "BlockBase.h"

namespace Block{

	const int BlockBase::m_blockNumber = 1;

	BlockBase::BlockBase():
	m_isInitialize(false){}


	BlockBase::~BlockBase(){
	}

	//
	///
	int BlockBase::GetBlock(const int xx, const int yy)const{
		return this->m_saveBlock[yy][xx];
	}

	//
	///
	void BlockBase::IsInitialize(bool flg){
		this->m_isInitialize = flg;
	}

	void BlockBase::BlockClear(){
		// ���u���b�N
		const int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		};

		// �u���b�N�̃R�s�[
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));

	}

	//
	/// �E��]
	void BlockBase::TurnRight(){
		// ���u���b�N
		int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		};

		for (int i = 0; i < BLOCK_HEIGHT; i++)
		{
			for (int j = 0; j < BLOCK_WIDTH; j++)
			{
				const int right = BLOCK_WIDTH - 1;
				provisionalBlock[i][j] = this->m_saveBlock[right - j][i];
			}
		}

		// �u���b�N�̃R�s�[
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));
	}// !TurnRight

	//
	/// ����]
	void BlockBase::TurnLeft(){
		// ���u���b�N
		int provisionalBlock[BLOCK_HEIGHT][BLOCK_WIDTH] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		};

		for (int i = 0; i < BLOCK_HEIGHT; i++)
		{
			for (int j = 0; j < BLOCK_WIDTH; j++)
			{
				const int left = BLOCK_WIDTH - 1;
				provisionalBlock[i][j] = this->m_saveBlock[j][left-i];
			}
		}

		// �u���b�N�̃R�s�[
		memcpy(this->m_saveBlock, provisionalBlock, sizeof(provisionalBlock));
	}


}// !namespace

