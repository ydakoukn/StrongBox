#ifndef DEF_OBJECTBASE_H
#define DEF_OBJECTBASE_H
/*

	�L�����N�^�[�ȊO�̃I�u�W�F�N�g�̊��N���X

*/
#include "Include.h"
namespace Object{

	class ObjectBase
	{
		public:
			ObjectBase()=default;
			ObjectBase(std::string imagePass):
				m_imageSize(20)
			{
				m_imageHandle = LoadGraph(imagePass.c_str());
			}

			virtual ~ObjectBase() = default;

			virtual void Initialize() = 0;

			virtual void UpDate() = 0;

			virtual void Render() = 0;

			// �Z�b�^�[
			inline void SetStartPosition(const int xx, const int yy){
				m_x = xx;
				m_y = yy;
			}

			// �Q�b�^�[
			inline int GetX()const{ return m_x; }
			inline int GetY()const{ return m_y; }
			inline float GetImageSize()const{ return m_imageSize; }
			inline int GetImage()const{ return m_imageHandle; }

	
		private:
			// �摜�p�n���h��
			int m_imageHandle;

			// �摜�T�C�Y
			const float m_imageSize;

			int m_x, m_y;
	};

}

#endif