//#include <Windows.h>
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LPCSTR lpszClass = "��������Ƽ��";
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg;
//	HWND hwnd;
//	WNDCLASS wndClass;
//	wndClass.cbClsExtra = 0;
//	wndClass.cbWndExtra = 0;
//	wndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
//	wndClass.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
//	wndClass.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
//	wndClass.hInstance = hInstance;
//	wndClass.lpfnWndProc = WndProc;
//	wndClass.lpszClassName = lpszClass;
//	wndClass.lpszMenuName = "NULL";
//	wndClass.style = CS_HREDRAW | CS_VREDRAW;
//	RegisterClass(&wndClass);
//	hwnd = CreateWindow("Window Class",
//		"�޸���",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		NULL,
//		NULL,
//		hInstance,
//		NULL);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static char str[10][100]; //��� �࿡ ���� ���ڸ� �����ϴ� �� str[0] ù��° �࿡ ���� ���ڿ�
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
//			MessageBox(NULL, "�� �̻� �Է� �� �� �����ϴ�.", "���", MB_OK);
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
//			if (count <= 0 && line == 0)
//			{
//				MessageBox(NULL, "������ ����", "�˸�", MB_OK);
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
//				MessageBox(NULL, "10���̻� Enter����.", "Warning", MB_OK);
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