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

		
		// キーの入力状態を更新する
		m_waitKey++;

		if (m_waitKey >15)
		{
			char tmpKey[256]; // 現在のキーの入力状態を格納する
			GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
			

			for (int i = 0; i < 256; i++){
				if (tmpKey[i] != 0){ // i番のキーコードに対応するキーが押されていたら
					Key[i]++;     // 加算
				}else
				if (tmpKey[i] == 0){              // 押されていなければ
					Key[i] = 0;   // 0にする
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
