#ifndef DEF_NAVIGATIONAI_H
#define DEF_NAVIGATIONAI_H
#include "Map.h"

namespace AI{

	class NavigationAI
	{
		
		public:
			NavigationAI(std::shared_ptr<Map::Map> map);
			~NavigationAI();

			void IniInitialize();
			void SetStartPosition(const int xx, const int yy);
			void Render(const int xx, const int yy, const int value);
			void UpDateMapLevel();

		private:
			struct LevelImage{
				LevelImage() = default;

				std::string m_imagePass;
				
			};
		private:
			std::shared_ptr<Map::Map> m_pMap;

			static LevelImage m_image[];

			int m_imageArray[6];

			const int m_size;
			const int m_numberOfImage;

			int m_x, m_y;
	};

}
#endif