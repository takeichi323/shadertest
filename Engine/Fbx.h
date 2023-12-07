#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include <vector>


#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

using std::vector;

class Texture;

class Fbx
{
	//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;//�g�U���ˌ�
		XMFLOAT4 specular;//���ʔ��ˌ����ˁi�X�y�L�����j���x
		XMFLOAT4 polygonCount;//�}�e���A���̃|���S����
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;//wvp
		XMMATRIX	matNormal;
		XMMATRIX    matW;//���[���h�ϊ������̂��
		XMFLOAT4	diffuseColor;//�ʂ̐F
		XMFLOAT4    lightPosition;//���C�g�̃|�W�V�����i�����j
		XMFLOAT4    speculer;//�X�y�L�����[(Lambert�̏ꍇ��)
		XMFLOAT4    eyePos;
		BOOL		isTextured;//�e�N�X�`�������邩�ǂ������f������
	};


	//��̒��_�����i�[����\����
	struct VERTEX
	{
		XMVECTOR position;//�ʒu
		XMVECTOR uv; //�e�N�X�`�����W
		XMVECTOR normal; //�@���x�N�g��
	};

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;

	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};