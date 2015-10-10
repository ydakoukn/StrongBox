#include "Wall.h"

namespace Object{
	Wall::Wall()
	{

	}


	Wall::~Wall()
	{
		DeleteObject(m_wallImage);
	}

	// �ǂ̔ԍ�
	const int Wall::m_wallNumber = 9;

	
	void Wall::Initialize(){
		// �摜�̓ǂݍ���


		this->m_wallImage = (HBITMAP)LoadImage(NULL, TEXT("Resource/Wall.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		this->IsInitialize(true);
	}

	void Wall::Render(HDC buffer, std::shared_ptr<Tetris::Stage>& stage){
		
		if (!m_isInitialize)
		{
			DEBUG_BOX(L"Don't Call Wall::Initialize()");
			return;
		}

		for (int y = 0; y < STAGE_HEIGHT; y++)
		{
			for (int x = 0; x < STAGE_WIDTH; x++)
			{
				if (stage->NowStageNumber(x, y) == this->m_wallNumber)
				{
					this->SetPosition(x, y);
					this->DrawWall(buffer);
				}
			}
		}
		
	}

	void Wall::DrawWall(HDC buffer){

		// �������f�o�C�X�R���e�L�X�g���쐬
		HDC m_wallBuffre = CreateCompatibleDC(buffer);
		// �I�u�W�F�N�g�̑I��
		SelectObject(m_wallBuffre, m_wallImage);

		//	�����p
		const int x = this->m_X * IMAGE_SIZE;
		const int y = this->m_Y * IMAGE_SIZE;
		const int width = IMAGE_SIZE;
		const int height = IMAGE_SIZE;

		TransparentBlt(buffer, x, y, width, height, m_wallBuffre,
			0, 0, 200, 200, RGB(0, 0, 0));
		//�f�o�C�X�R���e�L�X�g�̉��
		DeleteDC(m_wallBuffre);
	}

}// !namespace

