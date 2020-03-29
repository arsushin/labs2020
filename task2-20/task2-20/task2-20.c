
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

const char g_szClassName[] = "myWindowClass";
LRESULT CALLBACK WndProc( HWND hwnd,  UINT msg,  WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT paintStruct;
	POINT FAR* lppt = NULL;
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		break;
	case WM_PAINT:
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain( HINSTANCE hInstance,  HINSTANCE nPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, (LPCWSTR)g_szClassName, L"The curve Levy.", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
