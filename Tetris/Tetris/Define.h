#ifndef DEF_DEFINE_H
#define DEF_DEFINE_H
/*

	マクロ系を定義しておくとこ
	マクロ関数はここ以外に記述しないこと
	コメントで何用かも明記しておく

	一応Include.hにインクルードしておく
*/


// 動作確認など(デバッグ)に手軽にメッセージボックス作れる用
#define DEBUG_BOX(x) MessageBox(NULL, x, L"Debug", MB_OK);

// Windows ヘッダーから使用されていない部分を除外
#define WIN32_LEAN_AND_MEAN  




#endif // !DEF_DEFINE_H