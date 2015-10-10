#ifndef DEF_SINGLETON_H
#define DEF_SINGLETON_H
/*
	シングルトン作成テンプレートクラス
	Singleton<自作のクラス名>でそのポインタをシングルトンとして扱えます。
	GetPtr()かGetRef()を使えば自作クラスのメンバにアクセス可能

	ver 1.0
	制作者:Ko Hashimoto
*/
namespace OriginalLib{

	template<class TYPE>
	class Singleton
	{

		private:
			// テンプレート引数型を使うのに必要
			typedef TYPE Style;

		public:

			/*
				関数名:Create
				型    : void
				機能  : 指定クラスのポインタのアドレスをprivateアドレスに確保する。
				       すでに確保済みなら確保しない
			*/
			static void Create(){

				if (m_instance != nullptr) return;

				m_instance = new Style();
			}

			 /*
				関数名 :Destroy
				型    : void
				機能  : ポインタ情報の解放
				       確保していない、もしくはすでに削除済みなら何もしない
			*/
			static void Destroy(){

				if (m_instance == nullptr) return;

				delete m_instance;
				m_instance = nullptr;
			}

			 /*
				関数名 :GetPtr
				型    : テンプレート引数ポインタ型
				機能  : Createで確保したインスタンスのポインタを返します。
			*/
			static Style* GetPtr(){

				if (m_instance == nullptr) return nullptr;

				return m_instance;
			}

			/*
				関数名 :GetRef
				型    : テンプレート引数参照型
				機能  : Createで確保したインスタンスの参照を返します。
			*/
			static Style& GetRef(){
				if (m_instance == nullptr)
				{
					std::cerr << "Don't Call Create()" << std::endl;
				}
				return *m_instance;
			}

			/*
				関数名 :IsCreated
				型    : スタティックブール型関数
				機能  : Createが呼び出されていればtrueとなる
			*/
			static bool IsCreated(){
				if (m_instance != nullptr)
				{
					return true;
				}
				return false;
			}


		private:
			/*
				外部でのインスタンス化をやらせない
			*/
			Singleton() = default;
			virtual ~Singleton() = default;
		
		private:
			
			/*
				役割：Create時のポインタ確保用。初期値は[nullptr]
			*/
			static Style* Singleton<TYPE>::m_instance;
	};

	template<class TYPE>
	typename Singleton<TYPE>::Style* Singleton<TYPE>::m_instance = nullptr;

}


#endif// !DEF_SINGLETON_H