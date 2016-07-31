//---------------------------------------------------------
// 
//	iruna_flame_manager.h
//	�t���[���̊Ǘ�
//	�쐬�� 6��24��
//	����� ���� �Ė�
// 
//---------------------------------------------------------

/*----���d�C���N���[�h�h�~-------------------------------------------------*/
#ifndef IRUNA_FLAME_MANAGER_H
#define IRUNA_FLAME_MANAGER_H

/*----�C���N���[�h-------------------------------------------------*/
#include "../Include/iruna_utility.h"

namespace iruna
{
namespace core
{

//=====================================================================
//
//	�N���X��	:	FrameRateManage
//	����		:	�t���[�����[�g�Ǘ��N���X(���m�X�e�[�g)
//	�����		:	���� �Ė�
//	�쐬��		:	2011/06/24	- �쐬
//
//=====================================================================
class FrameRateManage
{
// �v���C�x�[�g	�����o�ϐ�
private:
	static U_LONG		standardOneMS;	// 1�t���[�����_�b�ɂ��邩
	static float		standardFps;	// 1�b���t���[���ɂ��邩
	static float		secondAverage;	// 1�b�ŉ��t���[����������

// �p�u���b�N	�����o�֐�
public:
	//--------------------------------------------------------------------
	// 
	//	����	:	�R���X�g���N�^
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	FrameRateManage();

	//--------------------------------------------------------------------
	// 
	//	����	:	�f�X�g���N�^
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	~FrameRateManage();

	//--------------------------------------------------------------------
	// 
	//	����	:	�t���[���p�[�Z�R���h�̐ݒ肷��(�ÓI�����o�֐�)
	//	��1����	:	[in] setFps	- �w��̃t���[���p�[�Z�R���h
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	static void		SetFrameRate( float setFps );

	//--------------------------------------------------------------------
	// 
	//	����	:	1�b�ŉ��t���[�������������擾����(�ÓI�����o�֐�)
	//	�߂�l	:	1�b�ł̕��σt���[����
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	static float	GetFrameRate();

	//--------------------------------------------------------------------
	// 
	//	����	:	�ݒ肵���t���[���p�[�Z�R���h���擾����(�ÓI�����o�֐�)
	//	�߂�l	:	�ݒ肵���t���[���p�[�Z�R���h
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	static float	GetStandardFrameRate();

	//--------------------------------------------------------------------
	// 
	//	����	:	�t���[�����[�g�𓯊�������
	//	�߂�l	:	�t���[�����[�g���ݒ��艺����Ă��邩�̃t���O true�F���Ȃ��@false�F�x��Ă���
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	bool	Synchronization();
};

}	//	core	end
}	//	iruna	end

#endif	//	IRUNA_FLAME_MANAGER_H	end