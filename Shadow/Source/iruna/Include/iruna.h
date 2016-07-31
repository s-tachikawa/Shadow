//---------------------------------------------------------
// 
//	iruna.h
//	irunaライブラリの一括インクルード
//	作成日 6月22日
//	製作者 立川 翔野
// 
//---------------------------------------------------------

/*----多重インクルード防止-------------------------------------------------*/
#ifndef _IRUNA_H
#define _IRUNA_H

/*----インクルード-------------------------------------------------*/

// コア系
#include "../Include/iruna_core.h"

// グラフィックス系
#include "../Include/iruna_graphics.h"

//	ジオメトリー系
#include "../Include/iruna_geometry.h"

// I/O系
#include "../Include/iruna_io.h"

// 数学系
#include "../Include/iruna_math.h"

// サウンド系
#include "../Include/iruna_sound.h"

// ユーティリティ系
#include "../Include/iruna_utility.h"

// システム系
#include "../Include/iruna_system.h"

//	スクリプト関連
#include "../Include/iruna_script.h"

/*----プリプロセッサディレクティブ---------------------------------*/
#ifdef _DEBUG
#pragma comment ( lib, "iruna_d.lib" )

#else
#pragma comment ( lib, "iruna.lib"	)



#endif




#endif	//	_IRUNA_H	end