#include "../iruna/Include/iruna.h"



using namespace iruna;
using namespace	graphics;
using namespace core;



int WINAPI WinMain( HINSTANCE , HINSTANCE, LPTSTR, int )
{


	//_CrtSetBreakAlloc( 173 );

	// ライブラリ管理クラス
	// ライブラリの起動、一番最初にする
	System*	system	= &System::GetInstance();
	if( !system->Setup( 800, 600, true,  "影を作ってみた" ) )	// WS_POPUPで枠が消える
		return -1;
	
	//	街モデルの読み込み
	Model city;
	city.Load( "../Resource/Model/shadow_city.x" );

	//	デバイスコントローラー
	DeviceController render;

	//	カメラの初期化
	Camera camera;
	camera.aspect	= 800.0f / 600.0f;
	camera.eye		= math::Vector3( 0, 20, -15 );
	camera.fovY		= D3DXToRadian(45.0f);
	camera.lookAt	= math::Vector3( 0, 0, 0 );
	camera.upVector = math::Vector3( 0, 1, 0 );
	camera.zFar		= 100.0f;
	camera.zNear	= 1.0f;

	math::Vector3	lightVec = math::Vector3( 0.0f, 0.0f, 0.0f );
	float			angle = 0.0f;
	

	//	シェーダーの読み込み
	Effect	shadowMap;		//	シャドウマップ生成用シェーダー
	Effect	modelEffect;	//	モデル描画用シェーダー

	shadowMap.Create( "../Resource/Effect/shadowmap.fx",1 );
	modelEffect.Create( "../Resource/Effect/shadow_diffuse.fx",1 );

	//	サーフェースの作成
	Texture		shadowTex;	//	深度バッファを書き込むテクスチャ
	Surface		shadowSur;	//	深度バッファを書き込み用レンダリングターゲットサーフェース
	Surface		depthSur;	//	深度バッファを書き込み用サーフェース
	//	からのテクスチャを作成
	shadowTex.Create( 800, 600, D3DUSAGE_RENDERTARGET );
	//	サーフェースの取得
	shadowTex.GetSurface( shadowSur );
	depthSur.CreateDepth( 800, 600, Surface::Z_D24 );

	//	保持用サーフェース
	Surface zBuffer;
	Surface backBuffer;
	Viewport oldVeiwPort;

	//	シャドウマップ描画用スプライト
	Sprite shadowSpr;
	shadowSpr.SetSize( math::Vector2( 800, 600 ) );
	

	// メインループ
	while( system->Run() )
	{
	
		// ウィンドウがアクティブの時だけ実行
		if( system->IsActive() )
		{
			angle += 0.01f;
			lightVec = math::Vector3( 20.0f * cosf( angle ), 15.0f, 20.0f * sinf( angle ) );
			//	1　影マップの作成

			//	現在のビューポート取得
			
			GetViewport( oldVeiwPort );
			//	現在のバックバッファを取得
			GetRenderTarget( backBuffer, 0 );
			//	現在の深度バッファを取得
			GetDepthTarget( zBuffer );

			//	バッファをクリア
			ClearScreen();

			//	深度バッファをテクスチャに設定
			shadowSur.SetRenderTarget( 0 );
			depthSur.SetDepthTarget();
			//	新たに作成したビューポートを設定
			Viewport newVeiwPort;
			newVeiwPort.SetSize( 0, 0, 800, 600 );
			newVeiwPort.SetViewport();

			ClearBackBuffer( D3DCLEAR_ZBUFFER );
			

			//	深度バッファ用カメラ(光源)
			camera.eye		= math::Vector3( lightVec.x, lightVec.y, lightVec.z );
	
			//	シェーダーに値をセット
			shadowMap.SetTechnique( "BasicTech" );
			shadowMap.SetMatrix( "g_vlp", camera.GetView() * camera.GetProjection() );

			shadowMap.CommitChanges();

			//	モデルの描画(深度だけ)
			shadowMap.Begin( 0, 0 );
			shadowMap.BeginPass( 0 );
			for( int i = 0; i < city.GetMaterialCount(); i++ )
			{
				city.Draw( i );
			}
			shadowMap.EndPass();
			shadowMap.End();
			
			//	2　作成した影マップを元にモデルを描画

			//	保持していたものを元に戻す
			backBuffer.SetRenderTarget( 0 );
			zBuffer.SetDepthTarget();
			oldVeiwPort.SetViewport();

		//	render.SetTexture( 0, shadowTex.GetTexture() );
		//	shadowSpr.Draw( math::Vector2( 0, 0 ) );

			math::WoldMatrix wold;
			math::Matrix invMat;
			wold.SetTranslation( 0, 0, 0 );
			D3DXMatrixInverse( &invMat,0, &wold.GetWoldMatrix() );
			//	シェーダーの設定
			modelEffect.SetTechnique( "BasicTech" );
			modelEffect.SetMatrix( "g_world", wold.GetWoldMatrix() );
			modelEffect.SetMatrix( "g_world_inv", invMat );

			camera.eye		= math::Vector3( 0, 20, -15 );

			modelEffect.SetMatrix( "g_view",camera.GetView() );
			modelEffect.SetMatrix( "g_proj",camera.GetProjection() );

			//	ライト用のカメラ
			camera.eye		= math::Vector3( lightVec.x, lightVec.y, lightVec.z );

			modelEffect.SetMatrix( "g_vlp", camera.GetView() * camera.GetProjection() );

			//	ライトの方向の設定
			math::Vector4 lightDir = math::Vector4( lightVec.x, lightVec.y, lightVec.z, 0.0f );
			D3DXVec4Normalize( &lightDir, &lightDir );
			modelEffect.SetVector( "g_light_dir", lightDir );

			//	影マップの設定
			modelEffect.SetTexture( "g_shadowbuf", shadowTex.GetTexture() );

			//	影マップのUVオフセット
			math::Vector4 shadowOffset = math::Vector4( 0.5f / 800.0f, 0.5f / 600.0f, 0.0f, 0.0f );
			modelEffect.SetVector( "g_offset" ,shadowOffset );
			modelEffect.CommitChanges();

			//	街の描画
			modelEffect.Begin( 0 , 0);
			modelEffect.BeginPass( 0 );

			for( int i = 0; i < city.GetMaterialCount(); i++ )
			{
				modelEffect.SetTexture( "g_texture", city.GetTexture( i ) );
				math::Vector4 tempColor = math::Vector4(	city.GetMaterial( i )->emissive.r,
															city.GetMaterial( i )->emissive.g,
															city.GetMaterial( i )->emissive.b,
															city.GetMaterial( i )->emissive.a);

				modelEffect.SetVector( "g_color0", tempColor );

				tempColor = math::Vector4(					city.GetMaterial( i )->diffuse.r,
															city.GetMaterial( i )->diffuse.g,
															city.GetMaterial( i )->diffuse.b,
															city.GetMaterial( i )->diffuse.a);
				modelEffect.SetVector( "g_color1", tempColor );
				modelEffect.CommitChanges();
				city.Draw( i );
			}

			modelEffect.EndPass();
			modelEffect.End();

			//	Fpsの描画
			DrawFormatString( 0, 0, Color4( 255, 255, 0 ),  "FPS[%.1f]" , FrameRateManage::GetFrameRate() );

			// 描画終了
			SwapScreen();
		}

		// ウィンドウがノンアクティブの時の処理
		else
			system->Idle();

		
	}

	
	// ライブラリの終了
	system->Release();

	return 0;
}