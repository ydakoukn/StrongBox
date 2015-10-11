#ifndef DEF_APPCONTROLLER_H
#define DEF_APPCONTROLLER_H
#include "Include.h"
namespace MyApplication
{
	class AppController
	{

		public:

			enum class Input{
				eKeyUp,
				eKeyDown,
				eKeyRight,
				eKeyLeft,
				eNull,
			};
		



		public:
			AppController();
			~AppController();

			// 入力を常に監視
			Input KeyCheck();

		private:

			int Key[256]; // キーが押されているフレーム数を格納する

			int m_waitKey;
			const int m_waitTime;

			Input m_input;
	};

}

#endif