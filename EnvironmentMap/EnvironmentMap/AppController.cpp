#include "AppController.h"


namespace MyApplication{

	AppController::AppController():
		m_waitKey(200),
		m_waitTime(300)
	{
	}


	AppController::~AppController()
	{
	}


	AppController::Input AppController::KeyCheck(){

		
		// �L�[�̓��͏�Ԃ��X�V����
		m_waitKey++;

		if (m_waitKey >15)
		{
			char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
			GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
			

			for (int i = 0; i < 256; i++){
				if (tmpKey[i] != 0){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
					Key[i]++;     // ���Z
				}else
				if (tmpKey[i] == 0){              // ������Ă��Ȃ����
					Key[i] = 0;   // 0�ɂ���
					m_input = AppController::Input::eNull;
				}
			}
			
		}
		

		if (Key[KEY_INPUT_RIGHT] > 1)
		{
			m_input = AppController::Input::eKeyRight;
		}
		else if (Key[KEY_INPUT_LEFT] > 1)
		{
			m_input = AppController::Input::eKeyLeft;
		}
		else if (Key[KEY_INPUT_UP] > 1)
		{
			m_input = AppController::Input::eKeyUp;
		}
		else if (Key[KEY_INPUT_DOWN] > 1)
		{
			m_input = AppController::Input::eKeyDown;
		}

		return m_input;

	}

}
