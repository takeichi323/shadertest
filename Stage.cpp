#include "Stage.h"
#include "Engine/Model.h"
#include "Controller.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1),hGround_(-1)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("assets/Ball.fbx");
    //hGround_ = Model::Load("assets/Ground.fbx");

    assert(hModel_ >= 0);
   // assert(hGround_ >= 0);
   
}

//�X�V
void Stage::Update()
{
   
   

}

//�`��
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

   // Model::SetTransform(hGround_, transform_);
    //Model::Draw(hGround_);
}

//�J��
void Stage::Release()
{
}