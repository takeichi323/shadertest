#pragma once
//必要なインクルードを書く
#include <string>
#include <vector>
#include "fbx.h"

namespace Model
{
	struct ModelData
	{
		Fbx* pfbx_;
		Transform transform_;//トランスフォーム
		std::string filename_;

	};
	int Load(std::string fileName);
	void SetTransform(int hModel, Transform transform);
	Fbx* GetModel(int _hModel);
	void Draw(int hModel);
	void Release();
	void ToggleRenderState();
}



