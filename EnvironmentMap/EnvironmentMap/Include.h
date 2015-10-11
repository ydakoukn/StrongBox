#ifndef DEF_INCLUDE_H
#define DEF_INCLUDE_H

/*

	必要なヘッダーをインクルードしておくファイル
	マクロも定義しよう


*/

// Windows ヘッダーから使用されていない部分を除外します。
#define WIN32_LEAN_AND_MEAN 

/*	DxLib使うときは必須	*/
#include "DxLib.h"

/*	STL系	*/
#include <iostream>
#include <memory>	//スマートポインタを使うときに必要。
#include <vector>	//vectorコンテナ使用時に必要。
#include <string>	//文字列使うとき必要

#include <unordered_map>	//ハッシュ連想配列使用時に必要

#include "Define.h"
#endif