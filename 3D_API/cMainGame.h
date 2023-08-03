#pragma once

#include "cVector3.h"
#include "cMatrix.h"

class cMainGame
{
public:
	cMainGame();
	~cMainGame();
private:
	HDC			m_MemDC;
	HBITMAP		m_hOldBitmap, m_hBitmap;
	std::vector<cVector3>	m_vecVertex; // 정점
	std::vector<DWORD>		m_vecIndex;  // 0~7번, 원점을 기준으로 정육면체의 모든 꼭짓점

	cMatrix		m_matWorld; 
	cMatrix		m_matView;  // 카메라 위치
	cMatrix		m_matProj;
	cMatrix		m_matViewport;

	cVector3	m_vEye;
	cVector3	m_vLookAt;
	cVector3	m_vUp;

	cVector3	m_vPosition;	 // 위치
	float		m_fBoxRotY;		 // 회전
	cVector3	m_vBoxDirection; // 방향 벡터

	// >> : grid
	std::vector<cVector3>	m_vecLineVertex;
	cVector3				m_vAxisXTextPosition;
	cVector3				m_vAxisZTextPosition;
	// << :

	POINT		m_ptPrevMouse;
	bool		m_isLButtonDown;
	float		m_fCameraDistance; // 카메라 거리 조정
	cVector3	m_vCamRotAngle;

	float m_fScale; // 크기


public:
	void Setup();  // 초기값 정리
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	bool IsBackFace(cVector3& v1, cVector3& v2, cVector3& v3);

	void SetGrid();
	void DrawGrid();

	void Update_Rotation();
	void Update_Move();
	void Update_Scale();
};

