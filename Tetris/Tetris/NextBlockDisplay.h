#ifndef DEF_NEXTBLOCKDISPLAY_H
#define DEF_NEXTBLOCKDISPLAY_H
#include "Include.h"
#include "BlockBase.h"
namespace Tetris{

	class NextBlockDisplay
	{
		public:
			NextBlockDisplay();
			~NextBlockDisplay();

			//
			/// 次のブロックの表示場所
			void NextBlockStage(HDC buffer,std::shared_ptr<Block::BlockBase>)
	};


}

#endif// !DEF_NEXTBLOCKDISPLAY_H