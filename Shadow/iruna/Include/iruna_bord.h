//---------------------------------------------------------
// 
//	iruna_bord.h
//	�|���̃f�t�H���g�N���X(�h�����ăr���{�[�h�Ƃ��ɂ���)
//	�쐬�� 6��24��
//	����� ���� �Ė�
// 
//---------------------------------------------------------

/*----���d�C���N���[�h�h�~-------------------------------------------------*/
#ifndef IRUNA_BORD_H
#define IRUNA_BORD_H

/*----�C���N���[�h-------------------------------------------------*/
#include "../Include/iruna_utility.h"
#include "../Include/iruna_math.h"
#include "../Include/iruna_color4.h"
#include "../Include/iruna_vertex_declaration.h"
#include "../Include/iruna_vertex_buffer.h"
#include "../Include/iruna_device_controller.h"

/*----�f�[�^�^ �錾------------------------------------------------*/
namespace iruna
{
namespace graphics
{

//=====================================================================
//
//	�N���X��	:	Board
//	����		:	�|���S���N���X
//	�����		:	���� �Ė�
//	�쐬��		:	2011/06/24	- �쐬
//
//=====================================================================
class Board
{
//	�v���e�N�e�b�h	�����o�ϐ�
protected:
	VertexBuffer*				positionBuffer;	// ���_�̍��W�o�b�t�@
	VertexBuffer*				texcoordBuffer;	// ���_��uv���W�o�b�t�@
	VertexBuffer*				colorBuffer;	// ���_�̐F�o�b�t�@
	VertexBuffer*				normalBuffer;	// �@���̐F�o�b�t�@
	math::Vector3				size[ 4 ];		// �o�b�N�A�b�v�p�̃{�[�h�T�C�Y
	math::Vector2				texcoord[ 4 ];	// �o�b�N�A�b�v�p��uv���W
	math::Vector3				normal[ 4 ];	//	�o�b�N�A�b�v�p�@��
	Color4						color[ 4 ];		// �o�b�N�A�b�v�p�̐F
	DeviceController*			render;			// �ԐړI�Ƀf�o�C�X�𑀍삷��
	static VertexDeclaration	declaration;	// �{�[�h�̒��_�錾(�ÓI�����o�ϐ�)

//	�p�u���b�N	�����o�֐�
public:
	//--------------------------------------------------------------------
	// 
	//	����	:	�R���X�g���N�^
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	Board();

	//--------------------------------------------------------------------
	// 
	//	����	:	�f�X�g���N�^(���z�֐�)
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	virtual	~Board();

	//--------------------------------------------------------------------
	// 
	//	����	:	�|���S���̃T�C�Y��ݒ肷��(���z�֐�)
	//	��1����	:	[in] setSize	- �|���S���̃T�C�Y
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	virtual	void	SetSize( math::Vector2 setSize );

	//--------------------------------------------------------------------
	// 
	//	����	:	�|���S���Ƀe�N�X�`���̂ǂ̕�����\�邩(���z�֐�)
	//	��1����	:	[in] uvRect	- �e�N�X�`���̕�����`
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	virtual void	SetTexUV( math::RectF uvRect );

	//--------------------------------------------------------------------
	// 
	//	����	:	�|���S���̐F��ݒ肷��(���z�֐�)
	//	��1����	:	[in] setColor	- �|���S���̐F
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	virtual void	SetColor( Color4 setColor );

	//--------------------------------------------------------------------
	// 
	//	����	:	�|���S����\������(���z�֐�)
	//	�߂�l	:	���ʃt���O	ture�F�����@false�F���s
	//	�����	:	���� �Ė�
	//	�쐬��	:	2011/06/24	- �쐬
	// 
	//--------------------------------------------------------------------
	virtual bool	Draw();

};

}	//	graphics	end
}	//	iruna		end

#endif	//	IRUNA_BORD_H	end