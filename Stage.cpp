#include "Stage.h"
#include "Engine/Model.h"
#include "Controller.h"
#include "Engine/Camera.h"
#include "Engine/Quad.h"
#include "Engine/Input.h"


void Stage::InConstantBuffer()
{
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// コンスタントバッファの作成
	HRESULT hr;
	hr = Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, "コンスタントバッファの作成に失敗しました", "エラー", MB_OK);
	}
}

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1),hGround_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("assets/Ball.fbx");
    //hGround_ = Model::Load("assets/Ground.fbx");

    assert(hModel_ >= 0);
   // assert(hGround_ >= 0);
   
	InConstantBuffer();
}

//更新
void Stage::Update()
{
	if (Input::IsKey(DIK_S))
	{
		XMFLOAT4 p = GetLightPos();
		XMFLOAT4 margin{p.x-0.0f,}
	}




	XMFLOAT4 tmp{ GetLightPos() };
	trLightBall.position_ = { tmp.x,tmp.y,tmp.z };

	CBUFF_STAGESCENE cb;
	cb.lightPosition = lightSourcePosition_;
	XMStoreFloat4(&cb.eyePos, Camera::GetEyePosition());

	Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, );

	Direct3D::pContext_->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
	Direct3D::pContext_->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
}

//描画
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

   // Model::SetTransform(hGround_, transform_);
    //Model::Draw(hGround_);
}

//開放
void Stage::Release()
{
}