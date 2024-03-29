#include "SandStrom.h"
#include <iostream>

const int SandStrom::m_scale = 3;

SandStrom::SandStrom() :
m_isStart(false),
m_random(1)
{
}


SandStrom::~SandStrom()
{
}

void SandStrom::Initialize(HDC buffer,const int windowWidth,const int windowHeight){


	m_window={ 0, 0, windowWidth, windowHeight };
	
	m_sand.reset(new unsigned char[m_window.right*m_window.bottom * m_scale]);


	HDC hdc;
	hdc = ::CreateCompatibleDC(buffer);

	HBITMAP hbit;
	hbit = ::CreateCompatibleBitmap(buffer, windowWidth, windowHeight);

	m_bitInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_bitInfo.bmiHeader.biWidth = windowWidth;
	m_bitInfo.bmiHeader.biHeight = windowHeight;
	m_bitInfo.bmiHeader.biPlanes = 1;
	m_bitInfo.bmiHeader.biBitCount = 24;
	m_bitInfo.bmiHeader.biCompression = BI_RGB;

	// 正確なBITMAPINFOを取得
	::GetDIBits(hdc, (HBITMAP)hbit, m_window.left, m_window.bottom, 0, &this->m_bitInfo, DIB_RGB_COLORS);
	
	::DeleteObject((HBITMAP)hbit);
	::DeleteDC(hdc);

	this->m_isStart = true;
}

void SandStrom::Start(HDC buffer){

	if (!m_isStart) return;

	const int width = m_window.right;
	const int height = m_window.bottom;
	const int scale = m_scale*m_scale;
	for (int i = 0; i < width * height * m_scale; i+=3) {
	
		m_sand.get()[i] = m_sand.get()[i + 1] = m_sand.get()[i + 1] = m_sand.get()[i + 2] = m_sand.get()[i + 2] = m_random >> 20;
		
		
		// 疑似乱数の生成
		m_random = (m_random * scale + 5);
	}


	SetDIBitsToDevice(buffer, 0, 0, width, height, 0, 0, 0, height, m_sand.get(), &m_bitInfo, DIB_RGB_COLORS);


}

//
/// 終了処理
void SandStrom::End(){

	m_sand.reset();

	m_sand = nullptr;

	m_isStart = false;
}