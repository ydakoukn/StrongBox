#ifndef DEF_BLOCK1_H
#define DEF_BLOCK1_H
/*
	��������
	��������
	��������
	��������

*/


#include "BlockBase.h"

namespace Block{
	
	class Block1 :
		public BlockBase
	{
		public:
			Block1();
			~Block1();

			void Initialize()final;
	};
}


#endif// !DEF_BLOCK1_H