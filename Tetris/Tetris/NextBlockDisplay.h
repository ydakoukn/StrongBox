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
			/// ���̃u���b�N�̕\���ꏊ
			void NextBlockStage(HDC buffer,std::shared_ptr<Block::BlockBase>)
	};


}

#endif// !DEF_NEXTBLOCKDISPLAY_H