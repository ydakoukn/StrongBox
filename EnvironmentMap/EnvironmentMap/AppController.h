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

			// ���͂���ɊĎ�
			Input KeyCheck();

		private:

			int Key[256]; // �L�[��������Ă���t���[�������i�[����

			int m_waitKey;
			const int m_waitTime;

			Input m_input;
	};

}

#endif