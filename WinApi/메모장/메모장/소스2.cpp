#include <Windows.h>
#include "resource2.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCSTR lpszClass = TEXT("�޸���");
LPCSTR lpszTitle = TEXT("�޸���");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    static char str[9][99]; //2�����迭
    static  int count, yPos;
    static RECT rt; //ȭ�鿵���� �����ϱ� ���� ����ü
    static SIZE size;

    int i;
    int answer;

    OPENFILENAME OFN;
    char str1[100];
    char lpstrFile[100] = "";
    char filter[] = "Every File(*,*)\0*.*\0Text File\0*.txt,*.doc\0";
    OPENFILENAME SFN;
    char str2[100];
    char lpstrFile1[100] = "";
    char filter1[] = "Every File(*,*)\0*.*\0Text File\0*.txt,*.doc\0";

    CHOOSEFONT FONT;
    static COLORREF fColor;
    HFONT hFont, oldFont;
    static LOGFONT LogFont;

    switch (iMessage) {
    case WM_CREATE:
        CreateCaret(hWnd, nullptr, 5, 15);
        //Ŀ�� �������� ������ִ� �Լ� ����
        ShowCaret(hWnd); //Ŀ�� �������� �����ִ� �Լ�
        yPos = 0;
        count = 0;
        return 0;

    case WM_CHAR:
        if (wParam == VK_BACK)
        {
            if (count == 0 && yPos == 0)break;
            count--;
            if (count < 0)
            {
                yPos--;
                count = strlen(str[yPos]);
            }
        }

        else if (wParam == VK_RETURN)
        {
            if (yPos < 9)
            {
                count = 0;
                yPos++;
            }
        }

        else
        {
            if (count < 98)
            {
                str[yPos][count++] = wParam;
            }
        }
        str[yPos][count] = NULL;
        InvalidateRect(hWnd, NULL, TRUE);
        return 0;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_FILE_40001:
            memset(&OFN, 0, sizeof(OPENFILENAME));
            OFN.lStructSize = sizeof(OPENFILENAME);
            OFN.hwndOwner = hWnd;
            OFN.lpstrFile = lpstrFile;
            OFN.lpstrFilter = filter;
            OFN.nMaxFile = 100;
            OFN.lpstrInitialDir = ".";

            if (GetOpenFileName(&OFN) != 0)
            {
                wsprintf(str1, "%s ������ ���ڽ��ϱ�?", OFN, lpstrFile);
                MessageBox(hWnd, str1, "���� ����", MB_OK);
            }
            break;

        case ID_FILE_40002:
            memset(&SFN, 0, sizeof(OPENFILENAME));
            SFN.lStructSize = sizeof(OPENFILENAME);
            SFN.hwndOwner = hWnd;
            SFN.lpstrFile = lpstrFile1;
            SFN.lpstrFilter = filter1;
            SFN.nMaxFile = 100;
            SFN.lpstrInitialDir = ".";

            if (GetSaveFileName(&SFN) != 0)
            {
                wsprintf(str2, "%s ������ ���ڽ��ϱ�?", OFN, lpstrFile1);
                MessageBox(hWnd, str2, "���� ����", MB_OK);
            }
            break;

        case ID_FILE_40003:
            answer = MessageBox(hWnd, "���� ������ ���� ������ �����Ͻðڽ��ϱ�?", "�޸���", MB_YESNOCANCEL);
            if (answer == IDNO)
            {
                PostQuitMessage(0);
            }
            break;

        case ID_40004:
            memset(&FONT, 0, sizeof(CHOOSEFONT));
            FONT.lStructSize = sizeof(CHOOSEFONT);
            FONT.hwndOwner = hWnd;
            FONT.lpLogFont = &LogFont;
            FONT.Flags = CF_EFFECTS | CF_SCREENFONTS;
            if (ChooseFont(&FONT) != 0)
            {
                fColor = FONT.rgbColors;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        }
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        hFont = CreateFontIndirect(&LogFont);
        oldFont = (HFONT)SelectObject(hdc, hFont);
        SetTextColor(hdc, fColor);

        for (i = 0; i < yPos + 1; i++)
        {   //���ڵڿ� Ŀ���� �̵��ϱ� ���� �Լ�
           //size�� ���ڱ��̸� ��� ���Ѱ�
            GetTextExtentPoint(hdc, str[i],
                strlen(str[i]), &size);
            TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
            SetCaretPos(size.cx, i * 20);
            //Ŀ�� �������� �����ϴ� �Լ�
        }

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);

        EndPaint(hWnd, &ps);
        return 0;

    case WM_DESTROY:
        HideCaret(hWnd); //Ŀ���������� �����.
        DestroyCaret();//Ŀ�� �������� ���ش�.
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}