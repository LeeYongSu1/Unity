#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hlnst;
LPCTSTR lpszClass = TEXT("ÀÌ¿ë¼ö");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevIncstance, LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hlnst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW | WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&Message, NULL, 0, 0))
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)

{

    HDC hdc;
    HBRUSH Brush, oBrush;
    PAINTSTRUCT ps;

    static int x, y;
    static RECT rectView;
    static bool flag;



    switch (iMsg)

    {

    case WM_CREATE:
        GetClientRect(hwnd, &rectView);

        x = 20; y = 20;

        break;

    case WM_PAINT:

        hdc = BeginPaint(hwnd, &ps);
        Brush = CreateSolidBrush(RGB(255, 255, 102));
        if (flag)
            SelectObject(hdc, Brush);


        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);

        EndPaint(hwnd, &ps);

        break;
    case WM_KEYUP:
        flag = false;
        InvalidateRgn(hwnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:

        if (wParam == VK_RIGHT) {

            flag = true;

            x += 40;

            if (x + 20 > rectView.right)

                x -= 40;

        }

        else if (wParam == VK_LEFT) {

            flag = true;

            x -= 40;

            if (x - 20 < rectView.left)

                x += 40;

        }

        else if (wParam == VK_UP) {

            flag = true;

            y -= 40;

            if (y - 20 < rectView.top)

                y += 40;

        }

        else if (wParam == VK_DOWN) {

            flag = true;

            y += 40;

            if (y + 20 > rectView.bottom)

                y -= 40;

        }

        InvalidateRgn(hwnd, NULL, TRUE);

        break;

    case WM_DESTROY:

        PostQuitMessage(0);

        break;

    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}