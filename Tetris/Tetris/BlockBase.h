#ifndef DEF_BLOCKBASE_H
#define DEF_BLOCKBASE_H
/*
	ブロッククラス基底クラス
	全てのブロックの共通処理はここに記述
	新しくブロックを作成するときは必ず継承する
*/
#include "ObjectBase.h"
namespace Block{

	class BlockBase{

		public:
			BlockBase();
			~BlockBase();

			// 初期化処理だけは必ず継承する
			// 初期化処理でブロックを生成する
			virtual void Initialize() = 0;

			virtual int GetBlock(const int xx, const int yy)const;

			virtual void TurnRight();
			virtual void TurnLeft();

		protected:
			static const int m_blockNumber;

			bool  m_isInitialize;


			// ブロックを格納
			int m_saveBlock[BLOCK_HEIGHT][BLOCK_WIDTH];

		protected:
			virtual void IsInitialize(const bool flg = false);
			virtual void BlockClear();
		
	};

}

#endif // !DEF_BLOCKBASE_H