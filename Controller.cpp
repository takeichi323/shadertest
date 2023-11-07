#include "Controller.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"



Controller::Controller(GameObject* parent) :GameObject(parent, "Controller")
{
    Camera::SetPosition(XMFLOAT3(7, 6, -5));
   /* Camera::SetTarget(XMFLOAT3(7, 2, 1));*/
}



//Controller::~Controller()
//{
//}



void Controller::Initialize()
{
    transform_.position_.x = 7;
}



void Controller::Update()
{




    //if (Input::IsKey(DIK_UP))
    //    transform_.rotate_.y += 1;
    //if (Input::IsKey(DIK_DOWN))
    //    transform_.rotate_.y -= 1;
    /*if (Input::IsKey(DIK_RIGHT))
        transform_.rotate_.x += 1;
    if (Input::IsKey(DIK_LEFT))
        transform_.rotate_.x -= 1;*/



    //���ݒn���x�N�g���^�ɕϊ�
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
    //1�t���[���̈ړ��x�N�g��
    XMVECTOR vMove = { 0.0f, 0.0f, 0.1f, 0.0f };  //����0.1m
    //transform_.rotate_.x�x��]������s����쐬
    XMMATRIX mRotX = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.x));
    //�ړ��x�N�g����ό`�i�{�̂Ɠ��������ɉ�]�j������
    vMove = XMVector3TransformCoord(vMove, mRotX);




    //if (Input::IsKey(DIK_W)) {
    //    //�ړ�
    //    vPos += vMove;
    //    //���ݒn���x�N�g�����炢����transform_.position_�ɖ߂�
    //    XMStoreFloat3(&transform_.position_, vPos);
    //    transform_.position_.z += 0.1f;
    //}
    //if (Input::IsKey(DIK_S))
    //    transform_.position_.z -= 0.1f;
    //if (Input::IsKey(DIK_D))
    //    transform_.position_.x += 0.1f;
    //if (Input::IsKey(DIK_A))
    //    transform_.position_.x -= 0.1f;





    Camera::SetTarget(transform_.position_);
    XMVECTOR vCam = { 0, 5, -10, 0 };  //�l����
    vCam = XMVector3TransformCoord(vCam, mRotX);
    XMFLOAT3 camPos;
    XMStoreFloat3(&camPos, vPos + vCam);
    Camera::SetPosition(camPos);
}



void Controller::Draw()
{
}



void Controller::Release()
{
}