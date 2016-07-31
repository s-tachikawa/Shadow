//---------------------------------------------------------
// 
//	iruna_model_decoder.h
//	モデル読み込みの基底クラス
//	作成日 10月21日
//	製作者 立川 翔野
// 
//---------------------------------------------------------
#ifndef MODEL_DECODER_H
#define MODEL_DECODER_H

/*----インクルード------------------------------------------------*/
#include "../Include/iruna_utility.h"
#include "../Include/iruna_model_data.h"

/*----データ型 宣言------------------------------------------------*/
namespace iruna
{
namespace graphics
{

//=====================================================================
//
//	クラス名	:	ModelDecoder
//	処理		:	モデル読み込み基底クラス
//	製作者		:	立川 翔野
//	作成日		:	2011/10/21	- 作成
//
//=====================================================================
class ModelDecoder
{
protected:

public:
	//--------------------------------------------------------------------
	// 
	//	処理	:	デストラクタ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/10/21	- 作成
	// 
	//--------------------------------------------------------------------
	virtual					~ModelDecoder(){}

	//--------------------------------------------------------------------
	// 
	//	処理	:	解放処理
	//	製作者	:	立川 翔野
	//	作成日	:	2011/10/21	- 作成
	// 
	//--------------------------------------------------------------------
	virtual	void			Relese()							= 0;

	//--------------------------------------------------------------------
	// 
	//	処理	:	初期化処理
	//	製作者	:	立川 翔野
	//	作成日	:	2011/10/21	- 作成
	// 
	//--------------------------------------------------------------------
	virtual	void			Init()								= 0;
		
	//--------------------------------------------------------------------
	// 
	//	処理	:	指定したモデルの読み込み
	//	第1引数	:	モデルファイルのあるディレクトリ
	//	戻り値	:	結果フラグ	true : 成功 false : 失敗
	//	製作者	:	立川 翔野
	//	作成日	:	2011/10/21	- 作成
	// 
	//--------------------------------------------------------------------
	virtual bool			Decode( std::string in_path )		= 0;

	//--------------------------------------------------------------------
	// 
	//	処理	:	読み込んだメッシュデータの取得
	//	戻り値	:	読み込んだファイルデータ
	//	製作者	:	立川 翔野
	//	作成日	:	2011/10/21	- 作成
	// 
	//--------------------------------------------------------------------
	virtual ModelData*		GetModelData()						= 0;


};

}	//	graphics	end
}	//	iruna		end

#endif	//	MODEL_DECODER_H	end