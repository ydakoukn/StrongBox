#pragma once
#include "Include.h"
#include "Stage.h"
namespace Object{
	class ObjectBase
	{

		protected:
			int m_X, m_Y;
			bool m_isInitialize;

			virtual void IsInitialize(bool flg = false)
			{
				this->m_isInitialize = flg;
			}

		public:
			ObjectBase():
				m_isInitialize(false){}
			virtual ~ObjectBase() = default;
			
			virtual void Initialize() = 0;
			virtual void Render(HDC buffer, std::shared_ptr<Tetris::Stage>&) = 0;
			virtual void UpDate(){}

			virtual void SetPosition(const int xx, const int yy)
			{
				this->m_X = xx;
				this->m_Y = yy;
			}

			
	};

}

