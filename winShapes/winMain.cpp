//
#define WIN32_LEAN_AND_MEAN

#include <windows.h> 

// Global variable 

HINSTANCE hinst;

// Function prototypes. 

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
BOOL InitApplication(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

// Application entry point. 

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    if (!InitApplication(hinstance))
        return FALSE;

    if (!InitInstance(hinstance, nCmdShow))
        return FALSE;

    BOOL fGotMessage;
    while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && fGotMessage != -1)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
    UNREFERENCED_PARAMETER(lpCmdLine);
}

BOOL InitApplication(HINSTANCE hinstance)
{
    WNDCLASSEX wcx;

    // Fill in the window class structure with parameters 
    // that describe the main window. 

    wcx.cbSize = sizeof(wcx);          // size of structure 
    wcx.style = CS_HREDRAW |
        CS_VREDRAW;                    // redraw if size changes 
    wcx.lpfnWndProc = MainWndProc;     // points to window procedure 
    wcx.cbClsExtra = 0;                // no extra class memory 
    wcx.cbWndExtra = 0;                // no extra window memory 
    wcx.hInstance = hinstance;         // handle to instance 
    wcx.hIcon = LoadIcon(NULL,
        IDI_APPLICATION);              // predefined app. icon 
    wcx.hCursor = LoadCursor(NULL,
        IDC_ARROW);                    // predefined arrow 
    wcx.hbrBackground = (HBRUSH)GetStockObject(
        WHITE_BRUSH);                  // white background brush 
    wcx.lpszMenuName = NULL; //"MainMenu";    // name of menu resource 
    wcx.lpszClassName = "MainWClass";  // name of window class
    wcx.hIconSm = LoadIcon(NULL,
        IDI_APPLICATION);
    //wcx.hIconSm = LoadImage(hinstance, // small class icon 
    //    MAKEINTRESOURCE(5),
    //    IMAGE_ICON,
    //    GetSystemMetrics(SM_CXSMICON),
    //    GetSystemMetrics(SM_CYSMICON),
    //    LR_DEFAULTCOLOR);

    // Register the window class. 

    return RegisterClassEx(&wcx);
}

BOOL InitInstance(HINSTANCE hinstance, int nCmdShow)
{
    HWND hwnd;

    // Save the application-instance handle. 

    hinst = hinstance;

    // Create the main window. 

    hwnd = CreateWindow(
        "MainWClass",        // name of window class 
        "Basic Window App",            // title-bar string 
        WS_OVERLAPPEDWINDOW, // top-level window 
        CW_USEDEFAULT,       // default horizontal position 
        CW_USEDEFAULT,       // default vertical position 
        CW_USEDEFAULT,       // default width 
        CW_USEDEFAULT,       // default height 
        (HWND)NULL,         // no owner window 
        (HMENU)NULL,        // use class menu 
        hinstance,           // handle to application instance 
        (LPVOID)NULL);      // no window-creation data 

    if (!hwnd)
        return FALSE;

    // Show the window and send a WM_PAINT message to the window 
    // procedure. 

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return TRUE;

}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    switch (msg)
    {
    case WM_CREATE:
    {
        return (0);
    } break;
    case WM_PAINT:
    {
        InvalidateRect(hwnd, NULL, FALSE);
        hdc = BeginPaint(hwnd, &ps);
        // ...
        Ellipse(hdc, 100, 100, 200, 200);
        Rectangle(hdc, 300, 100, 400, 200);

        POINT points[3];
        points[0].x = 500;
        points[0].y = 100;
        points[1].x = 450;
        points[1].y = 200;
        points[2].x = 600;
        points[2].y = 200;
        Polygon(hdc, points, 3);
        EndPaint(hwnd, &ps);
        return(0);
    } break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return(0);
    }
    default:
        break;
    }
    return(DefWindowProcW(hwnd, msg, wparam, lparam));
}