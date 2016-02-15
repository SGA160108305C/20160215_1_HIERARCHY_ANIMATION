#pragma once
#include "GameObject.h"
#include "CubeManParts.h"

class CubeMan : public GameObject
{
public:
	CubeMan();
	~CubeMan();

	void Initialize();
	virtual void Destroy() override;
	virtual void Render() override;
	virtual void Update() override;

	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	inline const LPD3DXVECTOR3 GetPositionAdress(){ return &position; }

protected:
	D3DXMATRIXA16 world;
	CubeManParts* root = nullptr;
	LPDIRECT3DTEXTURE9 texture;
	//위치와 이동, 회전
	float moveSpeed = 10.0f;
	float rotationSpeed = 2.0f;
	bool isMoving = false;
};

