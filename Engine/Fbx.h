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

enum RENDER_STATE
{
	RENDER_DIRLIGHT,
	RENDER_PNTLIGHT,
};

class Fbx
{
	//マテリアル
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;//拡散反射光
		//XMFLOAT4 specular;//鏡面反射光反射（スペキュラ）強度
		//XMFLOAT4 polygonCount;//マテリアルのポリゴン数
	};

	struct CBUFF_MODEL
	{
		XMMATRIX	matWVP;//wvp
		XMMATRIX    matW;//wvp
		XMMATRIX	matNormal;//ワールド変換だけのやつ
		XMFLOAT4	diffuseColor;//面の色
		BOOL		isTextured;//テクスチャがあるかどうか判断するやつ
	};


	//一つの頂点情報を格納する構造体
	struct VERTEX
	{
		XMVECTOR position;//位置
		XMVECTOR uv; //テクスチャ座標
		XMVECTOR normal; //法線ベクトル
	};

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;	//マテリアルの個数

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;

	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
	RENDER_STATE state_;
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    SetRenderingShader(RENDER_STATE _state) { state_ = _state; }
	void    Release();
};