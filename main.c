#include <windows.h>
#include <gl/gl.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          450,
                          450,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

        //pentagon 5
            glBegin(GL_POLYGON);

                glColor3f(1.0f, 0.0f, 1.0f);

                glVertex3f(-0.6f,   -0.2f,0.0f);
                glVertex3f(-0.35f,   -0.36f, 0.0f);
                glVertex3f(-0.4f,   -0.65f, 0.0f);
                glVertex3f(-0.8f,   -0.65f, 0.0f);
                glVertex3f(-0.85f, -0.36f, 0.0f);


            glEnd();

            //hexagon 6
             glBegin(GL_POLYGON);

                glColor3f(1.0f, 0.0f, 0.0f);

                glVertex3f(-0.18f, -0.2f, 0.0f);
                glVertex3f(0.12f,   -0.2f,0.0f);
                glVertex3f(0.22f,   -0.42f, 0.0f);
                glVertex3f(0.12f,   -0.62f, 0.0f);
                glVertex3f(-0.18f,   -0.62f, 0.0f);
                glVertex3f(-0.28f, -0.43f, 0.0f);


            glEnd();

            //heptagon 7
            glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 0.0f);

                glVertex3f(0.65f,-0.11f, 0.0f); //f
                glVertex3f(0.85f,   -0.22f,0.0f);  //n
                glVertex3f(0.95f,   -0.42f, 0.0f); //k
                glVertex3f(0.80f,   -0.67f, 0.0f); //j
                glVertex3f(0.50f,   -0.67f, 0.0f); //i
                glVertex3f(0.35f, -0.42f, 0.0f); //h
                glVertex3f(0.45f, -0.22f, 0.0f); //g
                glEnd();

                //octagon 8
                glBegin(GL_POLYGON);
                glColor3f(1.0f, 1.0f, 1.0f);
                glVertex3f(0.51f,0.77f, 0.0f); //f
                glVertex3f(0.7f,   0.77f,0.0f);  //g
                glVertex3f(0.83f,   0.63f, 0.0f); //h
                glVertex3f(0.83f,   0.43f, 0.0f); //i
                glVertex3f(0.7f,   0.29f, 0.0f); //j
                glVertex3f(0.51f, 0.29f, 0.0f); //k
                glVertex3f(0.38f, 0.43f, 0.0f); //m
                glVertex3f(0.38f, 0.63f, 0.0f); //n



                glEnd();
                //nonagon 9
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 1.0f, .0f);

                glVertex3f(0.0f,0.66f, 0.0f); //o
                glVertex3f(0.14f,   0.6f,0.0f);  //q
                glVertex3f(0.2f,   0.5f, 0.0f); //r
                glVertex3f(0.18f,   0.37f, 0.0f); //s
                glVertex3f(0.09f,   0.28f, 0.0f); //t
                glVertex3f(-0.09f, 0.28f, 0.0f); //u
                glVertex3f(-0.18f, 0.37f, 0.0f); //v
                glVertex3f(-0.2f, 0.5f, 0.0f); //w
                glVertex3f(-0.14f, 0.6f, 0.0f); //p

                glEnd();

                //Decagon 10
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f(-0.72f,0.8f, 0.0f); //a1
                glVertex3f(-0.52f,   0.8f,0.0f);  //z
                glVertex3f(-0.35f,   0.64f, 0.0f); //b1
                glVertex3f(-0.3f,   0.48f, 0.0f); //d1
                glVertex3f(-0.35f,   0.3f, 0.0f); //e1
                glVertex3f(-0.52f, 0.16f, 0.0f); //l1
                glVertex3f(-0.72f, 0.16f, 0.0f); //m1
                glVertex3f(-0.9f, 0.3f, 0.0f); //o1
                glVertex3f(-0.95f, 0.48f, 0.0f); //p1
                glVertex3f(-0.9f, 0.64f, 0.0f); //c1

                glEnd();


            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

