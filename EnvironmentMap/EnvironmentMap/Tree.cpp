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
	//	初期化処理	//
	void Tree::Initialize(){
		
	}

	//
	///
	//	更新処理	//
	void Tree::UpDate(){

	}

	//
	///
	//	描画処理	//
	void Tree::Render(){
		
		const int x = this->GetX() * this->GetImageSize();
		const int y = this->GetY()* this->GetImageSize();

		const int width = (this->GetX() + 1) * this->GetImageSize();
		const int height = (this->GetY() + 1)* this->GetImageSize();

		DrawExtendGraph(x, y,
			width, height,this->GetImage(), FALSE);
	}
}

