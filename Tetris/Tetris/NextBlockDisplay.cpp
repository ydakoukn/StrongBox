#include "NextBlockDisplay.h"

namespace Tetris{
	NextBlockDisplay::NextBlockDisplay()
	{
	}


	NextBlockDisplay::~NextBlockDisplay()
	{
	}

	void NextBlockDisplay::NextBlockStage(HDC buffer, std::shared_ptr<Block::BlockBase>){
		Rectangle(buffer, (STAGE_WIDTH + NEXT_BOX_INTERVAL) * IMAGE_SIZE, IMAGE_SIZE,
			(STAGE_WIDTH + NEXT_BOX_INTERVAL + BLOCK_WIDTH) * IMAGE_SIZE, (BLOCK_HEIGHT + 1) * IMAGE_SIZE);
	}
}