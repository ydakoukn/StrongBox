#ifndef DEF_GAMECONTROLLER_H
#define DEF_GAMECONTROLLER_H
/*

	ゲーム内のコントローラークラス
	シングルトン
	主にキー入力とかを受け付ける


*/
#include "Include.h"
#include "OriginalLib\Singleton.h"
namespace Singleton{

	class GameController
	{
		private:
		
			friend OriginalLib::Singleton<GameController>;
	
		public:

			// キー入力用列挙型
			enum class Type{
				eUp,
				eDown,
				eRight,
				eLeft,
				eSpace,
				eEnter,
				eEscape,
				eKeyW,
				eKeyA,
				eKeyS,
				eKeyD,
				eKeyZ,
				eKeyX,
				eKeyC,

				eNull,	// 何もない状態
			};

		public:
			// 対応のキーを列挙型で返す
			static GameController::Type GetEnumKey();

			// 対応のキーを文字列で返す
			static std::string GetStringKey();
			
			// キー入力をするタイミングで呼ぶ
			static void InputKey();

			static void ResetWait();

			static void SetKeyType(GameController::Type type);
		
		private:

			GameController() = default;

		private:
			static const int MAX_WAIT;
			static int m_waitTime;
			// キー入力保存用
			static Type m_inputEnumKey;

			// 入力情報を文字列で返すために使用
			static std::unordered_map <Type, std::string> m_inputStringKey;


	};
}// !namespace


#endif //!DEF_GAMECONTROLLER_H