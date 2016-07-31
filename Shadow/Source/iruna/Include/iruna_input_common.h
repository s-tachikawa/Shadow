//---------------------------------------------------------
// 
//	iruna_io.h
//	Iput系共通ヘッダー
//	作成日 6月24日
//	製作者 立川 翔野
// 
//---------------------------------------------------------

/*----多重インクルード防止-------------------------------------------------*/
#ifndef IRUNA_INPUT_COMMON_H
#define IRUNA_INPUT_COMMON_H


/*----インクルード-------------------------------------------------*/
#include "../Include/iruna_utility.h"

namespace iruna
{
namespace io
{
//	インプットデバイスの状態一覧
enum INPUT_STATE{
	INPUT_RELEASE	= 0,	// 離している
	INPUT_PUSH		= 1,	// 押した瞬間
	INPUT_PUSHED	= 2,	// 押している
	INPUT_RELEASED	= 3,	// 離した瞬間
};

// インプットデバイスの状態テーブル
const INPUT_STATE	INPUT_STATE_TABLE[ 2 ][ 2 ] = {
	{ INPUT_RELEASE,	INPUT_RELEASED	},
	{ INPUT_PUSH,		INPUT_PUSHED	},
};

//=====================================================================
//
// @struct	MouseButton
//	処理	:	マウスのボタンの一覧
//	製作者	:	立川 翔野
//	作成日	:	2011/06/24	- 作成
//
//=====================================================================
struct MouseButton
{
	enum Type{
		LEFT,
		RIGHT,
		CENTER,
		KEY3,
		KEY4,
		KEY5,
		KEY6,
		KEY7
	};
};

}	// io		end
}	// iruna	end

/*----関数 宣言----------------------------------------------------*/
namespace iruna
{
namespace io
{

//--------------------------------------------------------------------
// 
//	処理	:	キーボードの指定したキーの状態を返す
//	第1引数	:	[in] key	- 調べたいキー
//	戻り値	:	押されたキーの状態
//	製作者	:	立川 翔野
//	作成日	:	2011/06/24	- 作成
// 
//--------------------------------------------------------------------
INPUT_STATE		CheckKeyState( U_LONG key );

//--------------------------------------------------------------------
// 
//	処理	:	マウスの指定したキーの状態を返す
//	第1引数	:	[in] key	- 調べたいキー
//	戻り値	:	押されたキーの状態
//	製作者	:	立川 翔野
//	作成日	:	2011/06/24	- 作成
// 
//--------------------------------------------------------------------
INPUT_STATE		CheckMouseState( MouseButton::Type key );

//--------------------------------------------------------------------
// 
//	処理	:	マウスカーソルの位置を取得する
//	戻り値	:	マウスカーソルの位置
//	製作者	:	立川 翔野
//	作成日	:	2011/06/24	- 作成
// 
//--------------------------------------------------------------------
POINT			GetMousePosition();

}	//	io		end
}	//	iruna	end
#endif //	IRUNA_INPUT_COMMON_H	end