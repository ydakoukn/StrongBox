#ifndef DEF_STAGE_H
#define DEF_STAGE_H
/*
	ステージ生成クラス


*/
#include "Include.h"


namespace Block{
	class BlockBase;
}

namespace Tetris{

	class Stage
	{

		
		public:
			Stage();
			~Stage();

			void Initialize();

			int NowStageNumber(const int xx, const int yy)const;
			
			void FixBlock(std::shared_ptr<Block::BlockBase> block);

			void IsInitialize(const bool flg = false);

			void StageInfoDraw(HDC buffer);

			void DrawBlock(HDC buffer,const int xx,const int yy);

			void ClearDraw(HDC buffer);

			void Delete();

			void ClearStage();

			void MoveBlock(std::shared_ptr<Block::BlockBase> block, const int x, const int y);

		private:
			// 非公開変数

			// 実際のステージ保存用
			int m_saveStage[STAGE_HEIGHT][STAGE_WIDTH];

			// 初期化終わったかの確認用
			bool m_isInitialize;

			HBITMAP m_blockImage;
		
			// 座標を格納
			int m_blockX, m_blockY;

		private:
			void DrawGameStage(HDC buffer);
			void DrawLine(HDC buffer);
			
		
	};

}// !namespace


#endif // !DEF_STAGE_H