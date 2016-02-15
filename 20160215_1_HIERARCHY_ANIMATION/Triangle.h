#pragma once

#include "FVF.h"


struct Triangle
{
	Triangle()
	{
		vertex[0] = FVF_PositionColor();
		vertex[1] = FVF_PositionColor();
		vertex[2] = FVF_PositionColor();
	}
	Triangle(const D3DXVECTOR3& v1, const D3DXVECTOR3& v2, 
		const D3DXVECTOR3& v3, const D3DCOLOR color)
	{
		vertex[0] = FVF_PositionColor(v1, color);
		vertex[1] = FVF_PositionColor(v2, color);
		vertex[2] = FVF_PositionColor(v3, color);
	}
	FVF_PositionColor vertex[3];
};

struct TextureTriangle
{
	TextureTriangle()
	{
		vertex[0] = FVF_PositionTexture();
		vertex[1] = FVF_PositionTexture();
		vertex[2] = FVF_PositionTexture();
	}
	TextureTriangle(const FVF_PositionTexture& v1, 
		const FVF_PositionTexture& v2, 
		const FVF_PositionTexture& v3)
	{
		vertex[0] = v1;
		vertex[1] = v2;
		vertex[2] = v3;
	}
	TextureTriangle(
		const D3DXVECTOR3& v1, 
		const D3DXVECTOR3& v2, 
		const D3DXVECTOR3& v3,
		const D3DXVECTOR2& uv1, 
		const D3DXVECTOR2& uv2, 
		const D3DXVECTOR2& uv3)
	{
		vertex[0] = FVF_PositionTexture(v1, uv1);
		vertex[1] = FVF_PositionTexture(v2, uv2);
		vertex[2] = FVF_PositionTexture(v3, uv3);
	}
	FVF_PositionTexture vertex[3];
};