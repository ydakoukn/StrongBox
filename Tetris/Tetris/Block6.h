#ifndef DEF_BLOCK6_H
#define DEF_BLOCK6_H

/*
	��������
	��������
	��������
	��������
*/

#include "BlockBase.h"
namespace Block{
	class Block6 :
		public BlockBase
	{
	public:
		Block6();

		~Block6();

		void Initialize()final;
	};
}


#endif// ! DEF_BLOCK6_H