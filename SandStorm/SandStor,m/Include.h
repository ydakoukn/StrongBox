/*
	大体に共通してインクルードするファイルを
	まとめたヘッダーファイル

	自作の物以外なら自由に追加して

*/
#include <windows.h>	 // Win32API使用のため

#include <unordered_map> // std::unordered_map
#include <memory>		 // std::unique_ptr,std::shared_ptr,
						 // std::make_unique,std::make_shared

#include <array>		 // std::array　固定長配列(静的)
#include <vector>		 // std::vector 可変長配列(動的)

#include <iostream>		 // std::cout,std::endl
#include <string>		 // std::string

#include "Define.h"		 // マクロ関数をまとめたファイル
#include "Const.h"		 // 定数をまとめたファイル
#pragma comment(lib, "msimg32.lib")

