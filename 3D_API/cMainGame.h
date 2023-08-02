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
	std::vector<cVector3>	m_vecVertex; // ����
	std::vector<DWORD>		m_vecIndex;  // 0~7��, ������ �������� ������ü�� ��� ������

	cMatrix		m_matWorld; 
	cMatrix		m_matView;  // ī�޶� ��ġ
	cMatrix		m_matProj;
	cMatrix		m_matViewport;

	cVector3	m_vEye;
	cVector3	m_vLookAt;
	cVector3	m_vUp;

	cVector3	m_vPosition; // ��ġ
	float		m_fBoxRotY;   // ȸ��

public:
	void Setup();  // �ʱⰪ ����
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};
