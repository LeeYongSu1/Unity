//#include <windows.h>
//#include  "resource2.h"
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg;
//	HWND hwnd;
//	WNDCLASS wndClass;
//	
//	wndClass.cbClsExtra = 0;
//	wndClass.cbWndExtra = 0;
//	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	wndClass.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
//	wndClass.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
//	wndClass.hInstance = hInstance;
//	wndClass.lpfnWndProc = WndProc;
//	wndClass.lpszClassName = "Window Class";
//	wndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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
//
//LOGFONT lf;
//char str[] = "��Ʈ ��ȭ���� Test 1234";
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	OPENFILENAME OFN;
//	CHOOSEFONT CFT;
//	HFONT MyFont, OldFont;
//	static LOGFONT LogFont;
//	static COLORREF fColor;
//	char lpstrFile[MAX_PATH] = "";
//	static char str[100][100]; //��� �࿡ ���� ���ڸ� �����ϴ� �� str[0] ù��° �࿡ ���� ���ڿ�
//	static int count, line;
//	char str1[300];
//	static SIZE size;
//	int i;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		CreateCaret(hwnd, NULL, 3, 15);
//		ShowCaret(hwnd);
//		count = 0;
//		line = 0;
//		lf.lfHeight = 20;
//		strcpy_s(lf.lfFaceName,sizeof(lf.lfFaceName), "����");
//		return 0;
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for (i = 0; i < line + 1; i++)
//		{
//			GetTextExtentPoint(hdc, str[i], strlen(str[i]), &size);
//			TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
//			SetCaretPos(size.cx, i * 20);
//		}
//		MyFont = CreateFontIndirect(&lf);
//		OldFont = (HFONT)SelectObject(hdc, MyFont);
//		//TextOut(hdc, 100, 100, str1, strlen(str1));
//		SelectObject(hdc, OldFont);
//		DeleteObject(MyFont);
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
//			if (count == 0 && line == 0)
//			{
//				MessageBox(NULL, "�ѹ��� �� ������ ū�ϳ���.", "����Ѵ�", MB_OK);
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
//	case WM_COMMAND:
//		switch (LOWORD(wParam)) {
//		case ID_FILE_40001:
//			memset(&OFN, 0, sizeof(OPENFILENAME));
//			OFN.lStructSize = sizeof(OPENFILENAME);
//			OFN.hwndOwner = hwnd;
//			OFN.lpstrFilter = "Every File(*.*)\0*.*\0Text File\0*.txt;*.doc\0";
//			OFN.lpstrFile = lpstrFile;
//			OFN.nMaxFile = 256;
//			OFN.lpstrInitialDir = "c:\\";
//			if (GetOpenFileName(&OFN) != 0) {
//				wsprintf(str1, "%s ������ �����߽��ϴ�.", OFN.lpstrFile);
//				MessageBox(hwnd, str1, "���� ���� ����", MB_OK);
//			}
//			break;
//		case ID_FILE_40002:
//			memset(&OFN, 0, sizeof(OPENFILENAME));
//			OFN.lStructSize = sizeof(OPENFILENAME);
//			OFN.hwndOwner = hwnd;
//			OFN.lpstrFilter = "Every File(*.*)\0*.*\0Text File\0*.txt;*.doc\0";
//			OFN.lpstrFile = lpstrFile;
//			OFN.nMaxFile = 256;
//			OFN.lpstrInitialDir = "c:\\";
//			if (GetSaveFileName(&OFN) != 0) {
//				wsprintf(str1, "%s ������ �����߽��ϴ�.", OFN.lpstrFile);
//				MessageBox(hwnd, str1, "���� ���� ����", MB_OK);
//			}
//			
//			break;
//		case ID_FILE_40003:
//			PostQuitMessage(0);
//			break;
//		case ID_40004:
//			memset(&CFT, 0, sizeof(CHOOSEFONT));
//			CFT.lStructSize = sizeof(CHOOSEFONT);
//			CFT.hwndOwner = hwnd;
//			CFT.lpLogFont = &LogFont;
//			CFT.Flags = CF_EFFECTS | CF_SCREENFONTS;
//            if (ChooseFont(&CFT) != 0)
//            {
//                fColor = CFT.rgbColors;
//                InvalidateRect(hwnd, NULL, TRUE);
//            }
//            break;
//		}
//		return 0;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//	}
//}