//---------------------------------------------------------
// 
//	iruna_debug_geometry.h
//	デバッグ用ジオメトリーの生成
//	作成日 11月13日
//	製作者 立川 翔野
// 
//---------------------------------------------------------
/*----多重インクルード防止-------------------------------------------------*/
#ifndef IRUNA_DEBUG_GEOMETRY_H
#define IRUNA_DEBUG_GEOMETRY_H


/*----インクルード-------------------------------------------------*/
#include "../Include/iruna_utility.h"
#include "../Include/iruna_vector3.h"
#include "../Include/iruna_color4.h"

/*----データ型 宣言------------------------------------------------*/
namespace iruna
{

// 前方宣言
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
//	クラス名	:	DebugVertex
//	処理		:	当たり判定用線分構造体
//
//=====================================================================
struct DebugVertex
{
	
	math::Vector3		pos;
	graphics::Color4	color;
};

//=====================================================================
//
//	クラス名	:	DebugGeometry
//	処理		:	当たり判定用線分構造体
//
//=====================================================================
struct DebugGeometry
{
//	パブリックメンバ変数
public:
	UINT			count;
	DebugVertex*	data;

//	パブリックメンバ関数
public:
	DebugGeometry()
	{
		data = NULL;
		count = 0;
	}

};

/*----グローバル関数宣言------------------------------------------------*/

//--------------------------------------------------------------------
// 
//	処理		:	指定したジオメトリのVertexDataを作成する
//	第1引数		:	[in]	aabb	-	作成するAabb構造体
//	第2引数		:	[inout]	data	-	作成したジオメトリデータを格納する構造体ポインタ
//	第3引数		:	[in]	color	-	ジオメトリの描画色
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Aabb& aabb,		DebugGeometry* data, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	処理		:	指定したジオメトリのVertexDataを作成する
//	第1引数		:	[in]	sphere	-	作成するSphere構造体
//	第2引数		:	[inout]	data	-	作成したジオメトリデータを格納する構造体ポインタ
//	第3引数		:	[in]	slices	-	球の縦の分割数
//	第4引数		:	[in]	stacks	-	球の横の分割数
//	第5引数		:	[in]	color	-	ジオメトリの描画色
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Sphere& sphere,	DebugGeometry* data, UINT slices = 16, UINT stacks = 10, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	処理		:	指定したジオメトリのVertexDataを作成する
//	第1引数		:	[in]	line	-	作成するLine構造体
//	第2引数		:	[inout]	data	-	作成したジオメトリデータを格納する構造体ポインタ
//	第3引数		:	[in]	color	-	ジオメトリの描画色
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Line& line,		DebugGeometry* data, graphics::Color4 color = 0xffffffff );

//--------------------------------------------------------------------
// 
//	処理		:	指定したジオメトリのVertexDataを作成する
//	第1引数		:	[in]	segment	-	作成するSegment構造体
//	第2引数		:	[inout]	data	-	作成したジオメトリデータを格納する構造体ポインタ
//	第3引数		:	[in]	color	-	ジオメトリの描画色
// 
//--------------------------------------------------------------------
void CreateGeonetry( const Segment& segment,DebugGeometry* data, graphics::Color4 color = 0xffffffff );



}	//	geometry	end
}	//	iruna		end


#endif	//	IRUNA_DEBUG_GEOMETRY_H	end