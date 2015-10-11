#ifndef DEF_SANDSTORM_H
#define DEF_SANDSTORM_H
#include <memory>
#include <windows.h>
class SandStrom
{

	public:
		SandStrom();
		~SandStrom();

		void Initialize(HDC buffer,int windowWidth,int windowHeight);

		
		void Start(HDC buffer);

		void End();


	private:
	

	private:

		int m_random;

		const static int m_scale;

		bool m_isStart;
		BITMAPINFO m_bitInfo;

		RECT m_window;

		unsigned char* m_sand;

		int plus;
};

#endif// !DEF_SANDSTORM_H