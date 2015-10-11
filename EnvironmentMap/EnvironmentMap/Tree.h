#pragma once
#include "ObjectBase.h"
namespace Object{

	class Tree :
		public ObjectBase
	{
		public:

			Tree(std::string imagePass);
			~Tree();

			void Initialize()override;

			void UpDate()override;

			void Render()override;
	};

}

