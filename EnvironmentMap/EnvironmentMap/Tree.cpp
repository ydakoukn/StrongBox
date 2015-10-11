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
	//	‰Šú‰»ˆ—	//
	void Tree::Initialize(){
		
	}

	//
	///
	//	XVˆ—	//
	void Tree::UpDate(){

	}

	//
	///
	//	•`‰æˆ—	//
	void Tree::Render(){
		
		const int x = this->GetX() * this->GetImageSize();
		const int y = this->GetY()* this->GetImageSize();

		const int width = (this->GetX() + 1) * this->GetImageSize();
		const int height = (this->GetY() + 1)* this->GetImageSize();

		DrawExtendGraph(x, y,
			width, height,this->GetImage(), FALSE);
	}
}

