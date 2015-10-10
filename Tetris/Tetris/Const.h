#ifndef DEF_CONST_H
#define DEF_CONST_H
/*
	定数定義するところ



*/

// 無名空間　詳しくはググって
namespace{
     // ステージの大きさ
	const int STAGE_WIDTH = 13;
	const int STAGE_HEIGHT = 22;

	// ブロックの大きさ
	const int BLOCK_HEIGHT = 4;
	const int BLOCK_WIDTH = 4;

	// 画像の大きさ
	const int IMAGE_SIZE = 20;

	// 次のブロックの表示するところまでの間隔
	const int NEXT_BOX_INTERVAL = 3;

	// キー情報
	const int MAX_KEY = 256;
}



#endif // !DEF_CONST_H