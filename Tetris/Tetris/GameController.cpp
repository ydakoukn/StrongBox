#include "GameController.h"

namespace Singleton{

	/*	キーの種類	*/
	GameController::Type GameController::m_inputEnumKey= Type::eNull;


	// 連続入力防止
	const int GameController::MAX_WAIT = 100;
	int GameController::m_waitTime = 0;

	/*	キー入力を文字列で返す用	*/
	std::unordered_map <GameController::Type, std::string> GameController::m_inputStringKey{
		{GameController::Type::eNull ,   "Null"},
		{GameController::Type::eUp   ,   "Up" },
		{ GameController::Type::eDown,   "Down"},
		{ GameController::Type::eLeft,   "Left"},
		{ GameController::Type::eRight,  "Right"},
		{ GameController::Type::eSpace,  "Space"},
		{ GameController::Type::eEnter,  "Enter"},
		{ GameController::Type::eEscape, "Escape"},
		{ GameController::Type::eKeyW,	 "KeyW" },
		{ GameController::Type::eKeyA,   "KeyA" },
		{ GameController::Type::eKeyS,   "KeyS" },
		{ GameController::Type::eKeyD,   "KeyD" },
		{ GameController::Type::eKeyZ,   "KeyZ" },
		{ GameController::Type::eKeyX,   "KeyX" },
		{ GameController::Type::eKeyC,   "KeyC" },
	};
	
	// キーの入力するタイミングで呼ぶ
	void GameController::InputKey(){
		
		if (!OriginalLib::Singleton<GameController>::IsCreated()) return;

		m_waitTime++;

		std::cout << m_waitTime << std::endl;
		if (m_waitTime <= MAX_WAIT) return;

		// キーバッファの初期化
		static BYTE keyBuffer[MAX_KEY]{NULL};

		GetKeyboardState(keyBuffer);

		if (keyBuffer[VK_UP] & 0x80)	 m_inputEnumKey	= Type::eUp;
		if (keyBuffer[VK_RIGHT] & 0x80)  m_inputEnumKey	= Type::eRight;
		if (keyBuffer[VK_DOWN] & 0x80)	 m_inputEnumKey	= Type::eDown;
		if (keyBuffer[VK_LEFT] & 0x80)	 m_inputEnumKey	= Type::eLeft;
		if (keyBuffer[VK_ESCAPE] & 0x80) m_inputEnumKey = Type::eEscape;
		if (keyBuffer[VK_RETURN] & 0x80) m_inputEnumKey = Type::eEnter;
		if (keyBuffer[VK_SPACE] & 0x80)  m_inputEnumKey	= Type::eSpace;

		if (keyBuffer['W'] & 0x80) m_inputEnumKey = Type::eKeyW;
		if (keyBuffer['A'] & 0x80) m_inputEnumKey = Type::eKeyA;
		if (keyBuffer['S'] & 0x80) m_inputEnumKey = Type::eKeyS;
		if (keyBuffer['D'] & 0x80) m_inputEnumKey = Type::eKeyD;
		if (keyBuffer['Z'] & 0x80) m_inputEnumKey = Type::eKeyZ;
		if (keyBuffer['X'] & 0x80) m_inputEnumKey = Type::eKeyX;
		if (keyBuffer['C'] & 0x80) m_inputEnumKey = Type::eKeyC;


		// 使い終わったら中身を綺麗にする
		SecureZeroMemory(keyBuffer, sizeof(BYTE));
	}

	/*	対応のキーを列挙型で返す	*/
	GameController::Type GameController::GetEnumKey(){
		
		if (!OriginalLib::Singleton<GameController>::IsCreated()) return Type::eNull;

		return m_inputEnumKey;
	}


	/*	対応のキーをString型で返す	*/
	std::string GameController::GetStringKey(){
		
		if (!OriginalLib::Singleton<GameController>::IsCreated()) return "Null";

		return m_inputStringKey[m_inputEnumKey];
	}

	//
	/// ウェイトタイムを0に戻す
	void GameController::ResetWait(){
		m_waitTime = 0;
	}

	//
	///
	void GameController::SetKeyType(GameController::Type type){
		m_inputEnumKey = type;
	}

}// !namespace
