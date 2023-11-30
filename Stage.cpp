#include "Stage.h"
#include "Engine/Model.h"
#include "Controller.h"
#include "Engine/Camera.h"

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
   
}

//更新
void Stage::Update()
{
   
   

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