//#include <Windows.h>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPCSTR lpszClass = TEXT("국비 유니티 - 이용수");
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
//	, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASS WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
//	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hInstance = hInstance;
//	WndClass.lpfnWndProc = (WNDPROC)WndProc;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.lpszMenuName = NULL;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	RegisterClass(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszClass, WS_CAPTION | WS_SYSMENU | WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
//		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//		NULL, (HMENU)NULL, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//
//	while (GetMessage(&Message, 0, 0, 0)) {
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//	return Message.wParam;
//}
//
//
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static char str[10][100]; 
//	static int count, line;
//	static SIZE size;
//	int i;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		CreateCaret(hwnd, NULL, 3, 15);
//		ShowCaret(hwnd);
//		count = 0;
//		line = 0;
//		break;
//	case WM_LBUTTONDOWN:
//		hdc = GetDC(hwnd);
//		TextOut(hdc, 500, 500, "I Love You",10);
//		ReleaseDC(hwnd, hdc);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for (i = 0; i < line + 1; i++)
//		{
//			GetTextExtentPoint(hdc, str[i], strlen(str[i]), &size);
//			TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
//			SetCaretPos(size.cx, i * 20);
//		}
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_CHAR:
//		if (count > 99)
//		{
//			MessageBox(NULL, "더 이상 입력 할 수 없습니다.", "경고", MB_OK);
//			count--;
//		}
//		else if (wParam == VK_BACK)
//		{
//			count--;
//			if (count < 0)
//			{
//				line--;
//				count = strlen(str[line]);
//			}
//			if (count == 0 && line == 0)
//			{
//				MessageBox(NULL, "내용 없음.", "알림", MB_OK);
//			}
//		}
//		else if (wParam == VK_RETURN)
//		{
//			if (line < 9)
//			{
//				count = 0;
//				line++;
//			}
//			else
//			{
//				MessageBox(NULL, "10번이상 Enter금지.", "Warning", MB_OK);
//			}
//		}
//		else str[line][count++] = wParam;
//		str[line][count] = '\0';
//		InvalidateRgn(hwnd, NULL, TRUE);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}