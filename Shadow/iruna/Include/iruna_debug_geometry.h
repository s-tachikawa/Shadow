//---------------------------------------------------------
// 
//	iruna_debug_geometry.h
//	�f�o�b�O�p�W�I���g���[�̐���
//	�쐬�� 11��13��
//	����� ���� �Ė�
// 
//---------------------------------------------------------
/*----���d�C���N���[�h�h�~-------------------------------------------------*/
#ifndef IRUNA_DEBUG_GEOMETRY_H
#define IRUNA_DEBUG_GEOMETRY_H


/*----�C���N���[�h-------------------------------------------------*/
#include "../Include/iruna_utility.h"
#include "../Include/iruna_vector3.h"
#include "../Include/iruna_color4.h"

/*----�f�[�^�^ �錾------------------------------------------------*/
namespace iruna
{

// �O���錾
namespace graphics
{

class VertexBuffer;

}	// graphics	end


namespace geometry
{
struct Aabb;
struct Sphere;
struct Line;
struct Segment;

//=====================================================================
//
//	�N���X��	:	DebugVertex
//	����		:	�����蔻��p�����\����
//
//=====================================================================
struct DebugVertex
{
	
	math::Vector3		pos;
	graphics::Color4	color;
};

//=====================================================================
//
//	�N���X��	:	DebugGeometry
//	����		:	�����蔻��p�����\����
//
//=====================================================================
struct DebugGeometry
{
//	�p�u���b�N�����o�ϐ�
public:
	UINT			count;
	DebugVertex*	data;

//	�p�u���b�N�����o�֐�
public:
	DebugGeometry()
	{
		data = NULL;
		count = 0;
	}

};

/*----�O���[�o���֐��錾------------------------------------------------*/

//--------------------------------------------------------------------
// 
//	����		:	�w�肵���W�I���g����VertexData���쐬����
//	��1����		:	[in]	aabb	-	�쐬����Aabb�\����
//	��2����		:	[inout]	data	-	�쐬�����W�I���g���f�[�^���i�[����\���̃|�C���^
//	��3����		:	[in]	color	-	�W�I���g���̕`��F
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Aabb& aabb,		DebugGeometry* data, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	����		:	�w�肵���W�I���g����VertexData���쐬����
//	��1����		:	[in]	sphere	-	�쐬����Sphere�\����
//	��2����		:	[inout]	data	-	�쐬�����W�I���g���f�[�^���i�[����\���̃|�C���^
//	��3����		:	[in]	slices	-	���̏c�̕�����
//	��4����		:	[in]	stacks	-	���̉��̕�����
//	��5����		:	[in]	color	-	�W�I���g���̕`��F
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Sphere& sphere,	DebugGeometry* data, UINT slices = 16, UINT stacks = 10, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	����		:	�w�肵���W�I���g����VertexData���쐬����
//	��1����		:	[in]	line	-	�쐬����Line�\����
//	��2����		:	[inout]	data	-	�쐬�����W�I���g���f�[�^���i�[����\���̃|�C���^
//	��3����		:	[in]	color	-	�W�I���g���̕`��F
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Line& line,		DebugGeometry* data, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	����		:	�w�肵���W�I���g����VertexData���쐬����
//	��1����		:	[in]	segment	-	�쐬����Segment�\����
//	��2����		:	[inout]	data	-	�쐬�����W�I���g���f�[�^���i�[����\���̃|�C���^
//	��3����		:	[in]	color	-	�W�I���g���̕`��F
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Segment& segment,DebugGeometry* data, graphics::Color4 color = 0xffffffff );



}	//	geometry	end
}	//	iruna		end


#endif	//	IRUNA_DEBUG_GEOMETRY_H	end