#include "Tree.h"

namespace Object{
	Tree::Tree(std::string imagePass):
		ObjectBase(imagePass)
	{
	}


	Tree::~Tree()
	{
	}

	//
	///
	//	����������	//
	void Tree::Initialize(){
		
	}

	//
	///
	//	�X�V����	//
	void Tree::UpDate(){

	}

	//
	///
	//	�`�揈��	//
	void Tree::Render(){
		
		const int x = this->GetX() * this->GetImageSize();
		const int y = this->GetY()* this->GetImageSize();

		const int width = (this->GetX() + 1) * this->GetImageSize();
		const int height = (this->GetY() + 1)* this->GetImageSize();

		DrawExtendGraph(x, y,
			width, height,this->GetImage(), FALSE);
	}
}

