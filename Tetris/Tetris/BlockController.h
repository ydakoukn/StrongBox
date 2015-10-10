#ifndef DEF_BLOCKCONTROLLER_H
#define DEF_BLOCKCONTROLLER_H
/*
	�u���b�N�Ǘ��N���X

*/
#include "Include.h"
#include "BlockBase.h"
#include <random>
namespace Block{

	class BlockController
	{
		

		public:
			BlockController();
			~BlockController();

			void  Initialize();

			void KeyControll();

			static std::shared_ptr<BlockBase> m_pCurrentBlock;


			int GetX()const;
			int GetY()const;

		private:

			// �u���b�N�擾�֐�
			// �����_���ɐ��������
			std::shared_ptr<BlockBase> GetRandamBlock()const;

		private:
			
			static std::shared_ptr<BlockBase> m_pNextBlock;


			int m_blockX;
			int m_blockY;
			
			
	};
}



#endif // DEF_BLOCKCONTROLLER_H