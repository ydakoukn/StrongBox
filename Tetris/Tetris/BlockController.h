#ifndef DEF_BLOCKCONTROLLER_H
#define DEF_BLOCKCONTROLLER_H
/*
	ブロック管理クラス

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

			// ブロック取得関数
			// ランダムに生成される
			std::shared_ptr<BlockBase> GetRandamBlock()const;

		private:
			
			static std::shared_ptr<BlockBase> m_pNextBlock;


			int m_blockX;
			int m_blockY;
			
			
	};
}



#endif // DEF_BLOCKCONTROLLER_H