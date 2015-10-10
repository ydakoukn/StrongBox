﻿#include "Include.h"
#include "GameManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "GameController.h"
#include "OriginalLib\Singleton.h"

namespace Tetris{
	
	// 現在の処理状態		//
	GameManager::eGameState GameManager::m_stateScene = eGameState::eInitialize;

	//　今のシーン
	std::shared_ptr<Scene::SceneBase> GameManager::m_pCurrentScene	= nullptr;
	// 次のシーン
	std::shared_ptr<Scene::SceneBase> GameManager::m_pNextScene		= nullptr;

	// シーンを格納する連想配列	//
	std::unordered_map<std::string, std::shared_ptr<Scene::SceneBase>> GameManager::m_pSceneData;

	
	GameManager::GameManager(){}

	GameManager::~GameManager(){}

	///
	//	初期化	//
	void GameManager::Initialize(){

		// ゲーム内のシーンを登録	//
		this->Register(std::make_shared<Scene::SceneGame>(*this));
		this->Register(std::make_shared<Scene::SceneTitle>(*this));

		//	最初のシーンの設定	//
		this->m_pCurrentScene = this->Find(Scene::SceneGame::m_sceneName);

	}

	///
	//	シーンの登録処理	//
	void GameManager::Register(std::shared_ptr<Scene::SceneBase> scene){

		// ここで連想配列にキーと要素を登録する
		m_pSceneData.insert(std::make_pair(scene->Name(), scene));
	}

	///
	// シーン情報の削除	//
	void GameManager::Delete(const std::string& name){

		//	対応の名前を検索検索！
		auto findScene = m_pSceneData.find(name);

		// 対応の名前のシーンがないなら何もしない
		if (findScene == m_pSceneData.end()) return;

		//	あったら削除
		m_pSceneData.erase(findScene);
	}

	///
	//	シーン情報を検索して取得	//
	std::shared_ptr<Scene::SceneBase> GameManager::Find(const std::string& name){

		//	対応の名前を検索検索！
		auto findScene = m_pSceneData.find(name);

		//	無かったらなんもしない
		if (findScene == m_pSceneData.end())return nullptr;

		// あったらポインタを返す
		return findScene->second;
	}


	///
	// シーンを切り替える	//
	// 次に行くシーンの登録名	//
	void GameManager::ChangeScene(const ChangeSceneData& changeData){

		//	対応のシーンを検索検索!
		m_pNextScene = Find(changeData.m_sceneName);

		//　今と次を入れ替える
		m_pCurrentScene = m_pNextScene;

		// シーン切り替えるときは初期化からな
		m_stateScene = eGameState::eInitialize;

	}

	

	// メイン処理
	LRESULT GameManager::MainProc(
		const HWND hWnd, const UINT uMsg,
		const WPARAM wParam, const LPARAM lParam){

		static HDC			mainBuffer;	
		static HDC			backBuffer;  
		static HBITMAP		hbBackBuffer;
		static PAINTSTRUCT  ps;		    
		static RECT windowRect;			  
		
		switch (uMsg)
		{
		case WM_CREATE:

			::GetClientRect(hWnd, &windowRect);

			mainBuffer = ::GetDC(hWnd);

			hbBackBuffer = ::CreateCompatibleBitmap(mainBuffer, windowRect.right, windowRect.bottom);


			backBuffer = ::CreateCompatibleDC(mainBuffer);
			::SelectObject(backBuffer, hbBackBuffer);

			// コントローラーの作成
			OriginalLib::Singleton<Singleton::GameController>::Create();

		
			// 忘れずに解放	//
			::ReleaseDC(hWnd, mainBuffer);

			break;
		case WM_USER + 1:

			// ゲームの初期化
			this->GameInitialize();

			// ゲームの更新処理
			this->GameUpDate();

			// キー入力
			Singleton::GameController::InputKey();


			// WM_PAINTのゴールにｼｭｳｳｳｳｳｳｳｳｳｳｳ 
			::InvalidateRect(hWnd, NULL, FALSE);

			break;
		case WM_PAINT:
			// InvalidateRectからやってくるんやで
	
			// 描画の開始
			mainBuffer = ::BeginPaint(hWnd, &ps);

			// シーンの描画処理へ
			this->GameRender(backBuffer);

			// バッファの入れ替え
			::BitBlt(mainBuffer, windowRect.left, windowRect.top,
				windowRect.right, windowRect.bottom, backBuffer, 0, 0, SRCCOPY);

			// 忘れずに解放処理
			::EndPaint(hWnd, &ps);
		
			break;
		case WM_DESTROY:
			// 終了時処理

			// メインバッファーと
			// バックバッファーの削除
			::DeleteDC(mainBuffer);
			::DeleteDC(backBuffer);
			SecureZeroMemory(&mainBuffer, sizeof(HDC));
			SecureZeroMemory(&backBuffer, sizeof(HDC));

			// 互換ビットマップの削除
			::DeleteObject(hbBackBuffer);
			SecureZeroMemory(&hbBackBuffer, sizeof(HBITMAP));
			
			// Windowサイズを格納した奴を初期化
			SecureZeroMemory(&windowRect, sizeof(RECT));

			// コントローラーの削除
			OriginalLib::Singleton<Singleton::GameController>::Destroy();
	
			// 終了
			::PostQuitMessage(0);

			break;
		default:
			break;
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}// !MainProc()

	///
	// ゲームの初期化処理	//
	// 一回だけ実行される
	void GameManager::GameInitialize(){

		if (m_stateScene != eGameState::eInitialize)return;

		m_pCurrentScene->Initialize();	//今の初期化処理

		m_stateScene = eGameState::eUpDate;

	}

	///
	// ゲームの更新処理	//
	// 毎フレーム処理
	void GameManager::GameUpDate(){

		if (m_stateScene != eGameState::eUpDate)return;

		m_pCurrentScene->UpDate();		// 今のシーンの更新処理

		m_stateScene = eGameState::eRender;

	}

	///
	// ゲームの描画処理	//
	// 毎フレーム処理
	void GameManager::GameRender(HDC buffer){

		if (m_stateScene != eGameState::eRender)return;

		m_pCurrentScene->Render(buffer);// 今のシーンの描画処理

		m_stateScene = eGameState::eUpDate;
	}
}// !namespace