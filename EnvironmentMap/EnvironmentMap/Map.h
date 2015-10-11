#ifndef DEF_MAP_H
#define DEF_MAP_H

#include "Include.h"
namespace Map{
	
	class Map{

		
		public:
			Map();
			~Map();

			int GetMap(const int xx,const int yy)const;

			void ChangeMapDate(const int xx, const int yy, const int changeValue);

			bool isCreate()const;

			void Initialize();
			
			int MapWidth()const;
			int MapHeight()const;

		private:

			
			const int m_mapWidth;
			const int m_mapHeight;
			void CreateMap();

		private:

			bool m_isCreate;

			int m_map[20][20];

			
	};


}

#endif