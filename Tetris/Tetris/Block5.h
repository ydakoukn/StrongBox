#ifndef DEF_BLOCK5_H
#define DEF_BLOCK5_H

/*
	��������
	��������
	��������
	��������
*/

#include "BlockBase.h"
namespace Block{
	class Block5 :
		public BlockBase
	{
	public:
		Block5();

		~Block5();

		void Initialize()final;
	};
}


#endif// ! DEF_BLOCK5_H
