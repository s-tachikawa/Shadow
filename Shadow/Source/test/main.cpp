#include "../iruna/Include/iruna.h"



using namespace iruna;
using namespace	graphics;
using namespace core;



int WINAPI WinMain( HINSTANCE , HINSTANCE, LPTSTR, int )
{


	//_CrtSetBreakAlloc( 173 );

	// ���C�u�����Ǘ��N���X
	// ���C�u�����̋N���A��ԍŏ��ɂ���
	System*	system	= &System::GetInstance();
	if( !system->Setup( 800, 600, true,  "�e������Ă݂�" ) )	// WS_POPUP�Řg��������
		return -1;
	
	//	�X���f���̓ǂݍ���
	Model city;
	city.Load( "../Resource/Model/shadow_city.x" );

	//	�f�o�C�X�R���g���[���[
	DeviceController render;

	//	�J�����̏�����
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
	

	//	�V�F�[�_�[�̓ǂݍ���
	Effect	shadowMap;		//	�V���h�E�}�b�v�����p�V�F�[�_�[
	Effect	modelEffect;	//	���f���`��p�V�F�[�_�[

	shadowMap.Create( "../Resource/Effect/shadowmap.fx",1 );
	modelEffect.Create( "../Resource/Effect/shadow_diffuse.fx",1 );

	//	�T�[�t�F�[�X�̍쐬
	Texture		shadowTex;	//	�[�x�o�b�t�@���������ރe�N�X�`��
	Surface		shadowSur;	//	�[�x�o�b�t�@���������ݗp�����_�����O�^�[�Q�b�g�T�[�t�F�[�X
	Surface		depthSur;	//	�[�x�o�b�t�@���������ݗp�T�[�t�F�[�X
	//	����̃e�N�X�`�����쐬
	shadowTex.Create( 800, 600, D3DUSAGE_RENDERTARGET );
	//	�T�[�t�F�[�X�̎擾
	shadowTex.GetSurface( shadowSur );
	depthSur.CreateDepth( 800, 600, Surface::Z_D24 );

	//	�ێ��p�T�[�t�F�[�X
	Surface zBuffer;
	Surface backBuffer;
	Viewport oldVeiwPort;

	//	�V���h�E�}�b�v�`��p�X�v���C�g
	Sprite shadowSpr;
	shadowSpr.SetSize( math::Vector2( 800, 600 ) );
	

	// ���C�����[�v
	while( system->Run() )
	{
	
		// �E�B���h�E���A�N�e�B�u�̎��������s
		if( system->IsActive() )
		{
			angle += 0.01f;
			lightVec = math::Vector3( 20.0f * cosf( angle ), 15.0f, 20.0f * sinf( angle ) );
			//	1�@�e�}�b�v�̍쐬

			//	���݂̃r���[�|�[�g�擾
			
			GetViewport( oldVeiwPort );
			//	���݂̃o�b�N�o�b�t�@���擾
			GetRenderTarget( backBuffer, 0 );
			//	���݂̐[�x�o�b�t�@���擾
			GetDepthTarget( zBuffer );

			//	�o�b�t�@���N���A
			ClearScreen();

			//	�[�x�o�b�t�@���e�N�X�`���ɐݒ�
			shadowSur.SetRenderTarget( 0 );
			depthSur.SetDepthTarget();
			//	�V���ɍ쐬�����r���[�|�[�g��ݒ�
			Viewport newVeiwPort;
			newVeiwPort.SetSize( 0, 0, 800, 600 );
			newVeiwPort.SetViewport();

			ClearBackBuffer( D3DCLEAR_ZBUFFER );
			

			//	�[�x�o�b�t�@�p�J����(����)
			camera.eye		= math::Vector3( lightVec.x, lightVec.y, lightVec.z );
	
			//	�V�F�[�_�[�ɒl���Z�b�g
			shadowMap.SetTechnique( "BasicTech" );
			shadowMap.SetMatrix( "g_vlp", camera.GetView() * camera.GetProjection() );

			shadowMap.CommitChanges();

			//	���f���̕`��(�[�x����)
			shadowMap.Begin( 0, 0 );
			shadowMap.BeginPass( 0 );
			for( int i = 0; i < city.GetMaterialCount(); i++ )
			{
				city.Draw( i );
			}
			shadowMap.EndPass();
			shadowMap.End();
			
			//	2�@�쐬�����e�}�b�v�����Ƀ��f����`��

			//	�ێ����Ă������̂����ɖ߂�
			backBuffer.SetRenderTarget( 0 );
			zBuffer.SetDepthTarget();
			oldVeiwPort.SetViewport();

		//	render.SetTexture( 0, shadowTex.GetTexture() );
		//	shadowSpr.Draw( math::Vector2( 0, 0 ) );

			math::WoldMatrix wold;
			math::Matrix invMat;
			wold.SetTranslation( 0, 0, 0 );
			D3DXMatrixInverse( &invMat,0, &wold.GetWoldMatrix() );
			//	�V�F�[�_�[�̐ݒ�
			modelEffect.SetTechnique( "BasicTech" );
			modelEffect.SetMatrix( "g_world", wold.GetWoldMatrix() );
			modelEffect.SetMatrix( "g_world_inv", invMat );

			camera.eye		= math::Vector3( 0, 20, -15 );

			modelEffect.SetMatrix( "g_view",camera.GetView() );
			modelEffect.SetMatrix( "g_proj",camera.GetProjection() );

			//	���C�g�p�̃J����
			camera.eye		= math::Vector3( lightVec.x, lightVec.y, lightVec.z );

			modelEffect.SetMatrix( "g_vlp", camera.GetView() * camera.GetProjection() );

			//	���C�g�̕����̐ݒ�
			math::Vector4 lightDir = math::Vector4( lightVec.x, lightVec.y, lightVec.z, 0.0f );
			D3DXVec4Normalize( &lightDir, &lightDir );
			modelEffect.SetVector( "g_light_dir", lightDir );

			//	�e�}�b�v�̐ݒ�
			modelEffect.SetTexture( "g_shadowbuf", shadowTex.GetTexture() );

			//	�e�}�b�v��UV�I�t�Z�b�g
			math::Vector4 shadowOffset = math::Vector4( 0.5f / 800.0f, 0.5f / 600.0f, 0.0f, 0.0f );
			modelEffect.SetVector( "g_offset" ,shadowOffset );
			modelEffect.CommitChanges();

			//	�X�̕`��
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

			//	Fps�̕`��
			DrawFormatString( 0, 0, Color4( 255, 255, 0 ),  "FPS[%.1f]" , FrameRateManage::GetFrameRate() );

			// �`��I��
			SwapScreen();
		}

		// �E�B���h�E���m���A�N�e�B�u�̎��̏���
		else
			system->Idle();

		
	}

	
	// ���C�u�����̏I��
	system->Release();

	return 0;
}