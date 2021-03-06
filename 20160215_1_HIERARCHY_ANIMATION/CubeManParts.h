#pragma once
#include <list>
#include "FVF.h"
#include "Triangle.h"

enum CubeManPartsType
{
	ROOT,
	HEAD,
	LEFT_ARM,
	RIGHT_ARM,
	LEFT_LEG,
	RIGHT_LEG
};

class CubeManParts
{
public:
	CubeManParts();
	~CubeManParts();

	void Initialize(
		CubeManPartsType type,
		D3DXVECTOR3& cubeSize = D3DXVECTOR3(1, 1, 1), 
		D3DXVECTOR3& pivot = D3DXVECTOR3(0, 0, 0), 
		D3DXVECTOR3& baseLocal = D3DXVECTOR3(0, 0, 0),
		bool* cubeManMoving = nullptr);
	void Destroy();
	void Render();
	void Update(D3DXMATRIX* parentWorldMatrix = nullptr);
	
	inline void AddChild(CubeManParts* parts){ 
		child.push_back(parts); }
	inline void SetRotateSpeed(float speed){ 
		rotateSpeed = speed; }
protected:

	static const int TRIANGLE_COUNT = 12;
	TextureTriangle triangles[TRIANGLE_COUNT];

	D3DXMATRIXA16 world;

	D3DXVECTOR3 localTranslation = D3DXVECTOR3(0, 0, 0);

	std::list<CubeManParts*> child;

	float rotateSpeed = 0.0f;
	float rotateX = 0.0f;

	bool* isCubeManMoving = nullptr;
};

