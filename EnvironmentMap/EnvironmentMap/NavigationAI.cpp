#include "NavigationAI.h"

namespace AI{

	NavigationAI::LevelImage NavigationAI::m_image[]{
		
		{ "Resources/MapLevel/MapLevel1.png"},
		{ "Resources/MapLevel/MapLevel2.png"},
		{ "Resources/MapLevel/MapLevel3.png"},
		{ "Resources/MapLevel/MapLevel4.png"},
		{ "Resources/MapLevel/MapLevel5.png"},
		{ "Resources/MapLevel/MapLevel6.png"},
	};

	//
	///
	NavigationAI::NavigationAI(std::shared_ptr<Map::Map> map) :
	m_numberOfImage(6),
	m_size(20){
		m_pMap = map;
	}

	//
	///
	NavigationAI::~NavigationAI(){
	}
	
	//
	///
	//	‰Šú‰»
	void NavigationAI::IniInitialize(){
		// ‰æ‘œ‚Ì‰Šú‰»
		for (int i = 0; i < m_numberOfImage; i++)
		{
			m_imageArray[i] = LoadGraph(m_image[i].m_imagePass.c_str());

		}
	}

	void NavigationAI::Render(const int xx, const int yy,const int value){

		const int x = xx * m_size;
		const int y = yy * m_size;
		const int width		= (xx + 1) * m_size;
		const int height	= (yy + 1)* m_size;

			DrawExtendGraph(x, y,
				width, height, m_imageArray[value], FALSE);
		
	}

	void NavigationAI::UpDateMapLevel(){

	}

	void NavigationAI::SetStartPosition(const int xx, const int yy){
		m_x = xx;
		m_y = yy;
	}

}
