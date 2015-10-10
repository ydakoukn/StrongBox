#include "Stage.h"
#include "BlockBase.h"
#include "Wall.h"
namespace Tetris{

	Stage::Stage():
	m_isInitialize(false){}

	Stage::~Stage(){}

	//
	///
	void Stage::Initialize(){

		// 仮のステージ
		const int provisionalStage[STAGE_HEIGHT][STAGE_WIDTH]{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },

			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
			{ 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		};// !provisionalMap

		// マップのコピー
		memcpy(m_saveStage, provisionalStage, sizeof(provisionalStage));

		this->m_blockImage = (HBITMAP)LoadImage(NULL, TEXT("Resource/block.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		
		this->IsInitialize(true);
	}// !Initialize


	//
	///
	// 初期化終了時にtrue
	void Stage::IsInitialize(const bool flg){
		m_isInitialize = flg;
	}

	//
	// 線のやつ
	void Stage::StageInfoDraw(HDC buffer)
	{
		SelectObject(buffer, GetStockObject(WHITE_PEN));
		SelectObject(buffer, GetStockObject(NULL_BRUSH));
		this->DrawGameStage(buffer);

	}

	//
	// 可動範囲をすべて0にする
	void Stage::ClearStage(){
		for (int y = 1; y < STAGE_HEIGHT - 1; y++)
		{
			for (int x = 2; x < STAGE_WIDTH - 1; x++)
			{
				this->m_saveStage[y][x] = 0;
			}
		}
	}

	//
	/// 可動範囲を塗りつぶす
	void Stage::ClearDraw(HDC buffer){
		// DCペンの色を変更する
		SelectObject(buffer, GetStockObject(BLACK_BRUSH));
		SetDCPenColor(buffer, RGB(127, 127, 127));

		for (int i = 1; i < STAGE_HEIGHT - 1; i++)
		{
			for (int j = 2; j < STAGE_WIDTH - 1; j++)
			{
				const int left = j*IMAGE_SIZE;
				const int top = i*IMAGE_SIZE;
				const int right = left + IMAGE_SIZE;
				const int bottom = top + IMAGE_SIZE;

				Rectangle(buffer, left, top, right, bottom);
			}
		}
	}

	//
	/// 配列の値を返す
	int Stage::NowStageNumber(const int xx, const int yy)const{
		return m_saveStage[yy][xx];
	}

	//
	///
	// ただ表示するだけ
	void Stage::FixBlock(std::shared_ptr<Block::BlockBase> block){
		
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				if (this->NowStageNumber(x+1, y) == 9)continue;
				this->m_saveStage[y][x+5] = block->GetBlock(x, y);
			}
		}
	}

	//  落ちルンバ
	void Stage::MoveBlock(std::shared_ptr<Block::BlockBase> block, const int xx, const int yy){

		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				const int nowY = yy + y;
				const int nowX = xx + x + 5;
				this->m_saveStage[nowY][nowX] = block->GetBlock(x, y);

			}
		}
	}
	//
	// 実際に動かす場所の枠
	void Stage::DrawGameStage(HDC buffer){
		Rectangle(buffer, IMAGE_SIZE, IMAGE_SIZE,
			STAGE_WIDTH * IMAGE_SIZE, STAGE_HEIGHT * IMAGE_SIZE);
		this->DrawLine(buffer);
	}

	//
	///
	void Stage::DrawLine(HDC hdc)
	{
		// DCペンの色を変更する
		SetDCPenColor(hdc, RGB(127, 127, 127));
		SelectObject(hdc, GetStockObject(DC_PEN));

		// 内側描画
		for (int x = 1; x < STAGE_WIDTH; x++)
		{
			int pixelX = (x + 1) * IMAGE_SIZE;
			int pixelY = 1 * IMAGE_SIZE;
			MoveToEx(hdc, pixelX, pixelY, NULL);
			LineTo(hdc, pixelX, STAGE_HEIGHT * IMAGE_SIZE);
		}

		for (int y = 1; y < STAGE_HEIGHT; y++)
		{
			int pixelX = IMAGE_SIZE;
			int pixelY = (y + 1) * IMAGE_SIZE;
			MoveToEx(hdc, pixelX, pixelY, NULL);
			LineTo(hdc, STAGE_WIDTH * IMAGE_SIZE, pixelY);
		}
	}

	// ブロックの表示
	void Stage::DrawBlock(HDC buffer, const int xx, const int yy){

		HDC blockBuffre = CreateCompatibleDC(buffer);

		SelectObject(blockBuffre, m_blockImage);

		//	説明用
		const int x = xx * IMAGE_SIZE;
		const int y = yy * IMAGE_SIZE;
		const int width = IMAGE_SIZE;
		const int height = IMAGE_SIZE;

		TransparentBlt(buffer, x, y, width, height, blockBuffre,
			0, 0, 200, 200, RGB(0, 0, 0));

		DeleteDC(blockBuffre);
	}



}// !namespace

