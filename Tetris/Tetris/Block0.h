#ifndef DEF_BLOCK0_H
#define DEF_BLOCK0_H

/*
	Å†Å†Å†Å†
	Å†Å°Å°Å†
	Å†Å°Å°Å†
	Å†Å†Å†Å†
*/

#include "BlockBase.h"
namespace Block{

	class Block0 :
		public BlockBase
	{
		public:
			Block0();
		
			~Block0();

			void Initialize()final;
	};
}


#endif