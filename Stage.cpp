#include "Stage.h"
#include "Engine/Model.h"
#include "Controller.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
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

    assert(hModel_ >= 0);
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
}

//�J��
void Stage::Release()
{
}