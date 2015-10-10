#ifndef DEF_BLOCK4_H
#define DEF_BLOCK4_H

/*
	Å†Å†Å†Å†
	Å†Å†Å†Å°
	Å°Å°Å°Å°
	Å†Å†Å†Å†
*/

#include "BlockBase.h"
namespace Block{
	class Block4 :
		public BlockBase
	{
	public:
		Block4();

		~Block4();

		void Initialize()final;
	};
}


#endif// ! DEF_BLOCK4_H