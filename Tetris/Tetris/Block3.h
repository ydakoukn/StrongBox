#ifndef DEF_BLOCK3_H
#define DEF_BLOCK3_H
#include "BlockBase.h"
/*
	��������
	��������
	��������
	��������



*/


namespace Block{
	class Block3 :
		public BlockBase
	{
		public:
			Block3();

			~Block3();

			void Initialize()final;
	};
}


#endif// ! DEF_BLOCK3_H
