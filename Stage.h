#pragma once
#include "Engine/GameObject.h"

struct CBUFF_STAGESCENE
{                                            
    XMFLOAT4 lightPosition;
    XMFLOAT4 eyePos;
};

//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hModel_;    //���f���ԍ�
    int hGround_;
    int hLightBall_;
    Transform trDonuts_;
    Transform trGround;
    Transform trLightBall;
    ID3D11Buffer* pCBStageScene_;

    void InConstantBuffer();
    XMFLOAT4 lightSourcePosition_;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};