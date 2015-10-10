#ifndef DEF_BLOCKBASE_H
#define DEF_BLOCKBASE_H
/*
	�u���b�N�N���X���N���X
	�S�Ẵu���b�N�̋��ʏ����͂����ɋL�q
	�V�����u���b�N���쐬����Ƃ��͕K���p������
*/
#include "ObjectBase.h"
namespace Block{

	class BlockBase{

		public:
			BlockBase();
			~BlockBase();

			// ���������������͕K���p������
			// �����������Ńu���b�N�𐶐�����
			virtual void Initialize() = 0;

			virtual int GetBlock(const int xx, const int yy)const;

			virtual void TurnRight();
			virtual void TurnLeft();

		protected:
			static const int m_blockNumber;

			bool  m_isInitialize;


			// �u���b�N���i�[
			int m_saveBlock[BLOCK_HEIGHT][BLOCK_WIDTH];

		protected:
			virtual void IsInitialize(const bool flg = false);
			virtual void BlockClear();
		
	};

}

#endif // !DEF_BLOCKBASE_H