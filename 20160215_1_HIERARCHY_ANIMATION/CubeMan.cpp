#include "stdafx.h"
#include "CubeMan.h"


CubeMan::CubeMan()
{
}


CubeMan::~CubeMan()
{
}

void CubeMan::Initialize()
{
	D3DXMatrixIdentity(&world);


	root = new CubeManParts;
	root->Initialize(D3DXVECTOR3(1.0f, 2.0f, 1.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 3.0f, 0.0f), &isMoving);

	CubeManParts* head = new CubeManParts;
	head->Initialize(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR3(0.0f, -0.5f, 0.0f), D3DXVECTOR3(0.0f, 1.1f, 0.0f), &isMoving);
	root->AddChild(head);

	CubeManParts* leftArm = new CubeManParts;
	leftArm->Initialize(D3DXVECTOR3(0.5f, 2.0f, 0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(-0.8f, 1.0f, 0.0f), &isMoving);
	leftArm->SetRotateSpeed(2.0f);
	root->AddChild(leftArm);

	CubeManParts* rightArm = new CubeManParts;
	rightArm->Initialize(D3DXVECTOR3(0.5f, 2.0f, 0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.8f, 1.0f, 0.0f), &isMoving);
	rightArm->SetRotateSpeed(-2.0f);
	root->AddChild(rightArm);

	CubeManParts* leftLeg = new CubeManParts;
	leftLeg->Initialize(D3DXVECTOR3(0.5f, 2.0f, 0.8f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(-0.3f, -1.0f, 0.0f), &isMoving);
	leftLeg->SetRotateSpeed(-2.0f);
	root->AddChild(leftLeg);

	CubeManParts* rigthLeg = new CubeManParts;
	rigthLeg->Initialize(D3DXVECTOR3(0.5f, 2.0f, 0.8f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.3f, -1.0f, 0.0f), &isMoving);
	rigthLeg->SetRotateSpeed(2.0f);
	root->AddChild(rigthLeg);

	D3DXCreateTextureFromFile(
		GameManager::GetDevice(),
		L"./Data/Texture/Box.jpg",
		&texture);	
}

void CubeMan::Destroy()
{
	GameObject::Destroy();

	SAFE_RELEASE(texture);
	SAFE_DELETE(root);

}

void CubeMan::Update()
{
	GameObject::Update();

	float tick = (float)GameManager::GetTick();

	isMoving = false;
	if ((GetAsyncKeyState('A') & 0x8000) != 0)
	{
		isMoving = true;
		rotationAngle -= (rotationSpeed * tick);
	}
	else if ((GetAsyncKeyState('D') & 0x8000) != 0)
	{
		isMoving = true;
		rotationAngle += (rotationSpeed * tick);
	}


	if ((GetAsyncKeyState('W') & 0x8000) != 0)
	{
		isMoving = true;
		position += (direction * moveSpeed * tick);
	}
	else if ((GetAsyncKeyState('S') & 0x8000) != 0)
	{
		isMoving = true;
		position -= (direction * moveSpeed * tick);		
	}
	


	D3DXMATRIX rotation, translation;
	D3DXMatrixRotationY(&rotation, rotationAngle);

	world = rotation;

	D3DXVECTOR3 baseDirection(0, 0, 1);
	D3DXVec3TransformCoord(&direction, &baseDirection, &world);

	D3DXMatrixTranslation(&translation, position.x, position.y, position.z);
	world *= translation;

	root->Update(&world);
}

void CubeMan::Render()
{
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetFVF(FVF_PositionTexture::FVF);
	root->Render();
}

LRESULT CubeMan::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		//result = WM_LBUTTONDOWN;
	}
	break;
	case WM_LBUTTONUP:
	{
		//result = WM_LBUTTONUP;
	}
	break;
	case WM_MOUSEMOVE:
	{
		//result = WM_MOUSEMOVE;
	}
	break;
	}
	return result;
}