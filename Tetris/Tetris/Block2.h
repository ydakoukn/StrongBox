#ifndef DEF_BLOCK2_H
#define DEF_BLOCK2_H
/*

	��������
	��������
	��������
	��������



*/
#include "BlockBase.h"

namespace Block{
	class Block2:
		public BlockBase
	{
		public:
			Block2();

			~Block2();

			void Initialize()final;
	};

}

#endif// !DEF_BLOCK2_H
