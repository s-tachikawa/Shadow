//---------------------------------------------------------
// 
//	iruna_model.h
//	固定メッシュモデルクラス
//	作成日 6月27日
//	製作者 立川 翔野
// 
//---------------------------------------------------------

/*----多重インクルード防止-------------------------------------------------*/
#ifndef IRUNA_MODEL_H
#define IRUNA_MODEL_H

/*----インクルード-------------------------------------------------*/
#include "../Include/iruna_utility.h"
#include "../Include/iruna_math.h"
#include "../Include/iruna_vertex_declaration.h"
#include "../Include/iruna_texture.h"
#include "../Include/iruna_material.h"

/*----データ型 宣言------------------------------------------------*/
namespace iruna
{
namespace graphics
{

//=====================================================================
//
//	クラス名	:	Mesh
//	処理		:	固定モデルの管理
//	製作者		:	立川 翔野
//	作成日		:	2011/06/27	- 作成
//
//=====================================================================
class Model
{
//	プライベート	メンバ変数
private:
	LPD3DXMESH		mesh;			// メッシュ
	Material*		material;		// メッシュの質感、マテリアル
	Texture*		texture;		// テクスチャ
	U_LONG			materialCount;	// マテリアルの数
	std::string		recoveryPath;	// ファイルパス

//	パブリック	メンバ関数
public:

	//--------------------------------------------------------------------
	// 
	//	処理	:	コンストラクタ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/27	- 作成
	// 
	//--------------------------------------------------------------------
	Model();

	//--------------------------------------------------------------------
	// 
	//	処理	:	デストラクタ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/27	- 作成
	// 
	//--------------------------------------------------------------------
	~Model();

	//--------------------------------------------------------------------
	// 
	//	処理	:	固定のXfileの読み込み
	//	第1引数	:	[in] path	- Xファイルのパス
	//	戻り値	:	結果フラグ	ture：成功　false：失敗
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/27	- 作成
	// 
	//--------------------------------------------------------------------
	bool Load( std::string path );

	//--------------------------------------------------------------------
	// 
	//	処理	:	モデルの描画
	//	第1引数	:	[in] count	- 何番目のメッシュを描画するか
	//	戻り値	:	結果フラグ	ture：成功　false：失敗
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/27	- 作成
	// 
	//--------------------------------------------------------------------
	bool Draw( U_LONG count );

	//--------------------------------------------------------------------
	// 
	//	処理	:	頂点宣言の作り直し
	//	第1引数	:	[in] element	- 新しい頂点宣言配列
	//	戻り値	:	結果フラグ	ture：成功　false：失敗
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/25	- 作成
	// 
	//--------------------------------------------------------------------
	bool RemakeVertexFormat( const VertexDeclaration::Element* element );

	//--------------------------------------------------------------------
	// 
	//	処理	:	マテリアルの個数取得
	//	戻り値	:	マテリアルの個数
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/25	- 作成
	// 
	//--------------------------------------------------------------------
	U_LONG	GetMaterialCount();

	//--------------------------------------------------------------------
	// 
	//	処理	:	マテリアルの取得
	//	第1引数	:	[in] count	- 何番目のマテリアルを取得するか
	//	戻り値	:	マテリアルクラスのポインタ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/25	- 作成
	// 
	//--------------------------------------------------------------------
	const Material* GetMaterial( U_LONG count );

	//--------------------------------------------------------------------
	// 
	//	処理	:	メッシュのテクスチャーの取得
	//	第1引数	:	[in] count	- 何番目のテクスチャーを取得するか
	//	戻り値	:	テクスチャー構造体のポインタ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/06/25	- 作成
	// 
	//--------------------------------------------------------------------
	const LPDIRECT3DTEXTURE9 GetTexture( U_LONG count );

};


}	//	graphics	end
}	//	iruna		end

#endif	//	IRUNA_MODEL_H	end