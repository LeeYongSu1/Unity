//#include <windows.h>//�������� �ü������ �����ϴ� �������
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPCSTR lpszClass = TEXT("WINDOW");	//LPCSTR = const char Pointer/ LPSTR = char Pointer
////TEXT()���ڿ��� ��� ��ũ��
//LPCSTR lpszMenu = TEXT("Unity3D");
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance//�׷��� ���
//	, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASS WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hInstance = hInstance;
//	WndClass.lpfnWndProc = (WNDPROC)WndProc;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.lpszMenuName = NULL;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	RegisterClass(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszMenu,  WS_SYSMENU | WS_HSCROLL | WS_VSCROLL | WS_MAXIMIZEBOX| WS_MINIMIZEBOX| WS_THICKFRAME,
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
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{//�޼��� ó�� ���
//	switch (iMessage) {
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}