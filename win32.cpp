//
//  win32.cpp
//  BlindFate
//
//  Created by Robert Ruzbacky on 18/09/2016.
//  Copyright © 2016 Robert Ruzbacky. All rights reserved.
//
//  Some code adapted from Frank Luna (C) 2015 All Rights Reserved from book
//  Introduction to 3D Game Programming with DirectX 12
//

// Windows header file contains all Win32 APIs
#include <windows.h>

// Main window handle to identify the created Window
HWND ghMainWnd = 0;


// Initialise the Windows App
bool InitWindowsApp(HINSTANCE instanceHandle, int show);


// message loop
int Run();


//Handle events that our Window receives
LRESULT CALLBACK 
WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


// Microsoft Windows main() function

int WINAPI 
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd)

{
	// initiase main window
	if (!InitWindowsApp(hInstance, nShowCmd))

		return 0;

	//enter the message loop
	return Run();

}


// create a window
bool InitWindowsApp(HINSTANCE instanceHandle, int show)

{
	// fill in the properties of the Window that will be created
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = instanceHandle;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"BasicWndClass";

	// register the WNDCLASS instance with Windows
	if (!RegisterClass(&wc))
	{
		MessageBox(0, L"RegisterClass Failed", 0, 0);
		return false;
	}



	// create the Window
	ghMainWnd = CreateWindow(

		L"BasicWndClass",  // registered WNDCLASS instance
		L"BlindFate",      // window title
		WS_OVERLAPPEDWINDOW,   // window style
		CW_USEDEFAULT,      // x-coordinate
		CW_USEDEFAULT,      // y-coordinate
		CW_USEDEFAULT,      // width
		CW_USEDEFAULT,      // height
		0,                  // parent
		0,                  // menu handle
		instanceHandle,     // app instance
		0);                 // extra parameters

	if (ghMainWnd == 0)
	{
		MessageBox(0, L"CreateWindow Failed", 0, 0);
		return false;
	}


	// show and update the window to the screen
	ShowWindow(ghMainWnd, show);
	UpdateWindow(ghMainWnd);

	return true;
}


// Windows O/S message loop
// This also happens to be our game loop
int Run()
{
	MSG msg = { 0 };

	// *** initialise game code here ***


	// message loop
	while (msg.message != WM_QUIT)
	{
		// If there are Windows messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))

		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		// *** process game code here ***
		// update game logic for the frame
		// draw the frame
		else
		{



		}

	}

	// *** shutdown game code here ***

	return (int)msg.wParam;

}



LRESULT CALLBACK 
WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// message handler

	switch (msg)
	{

    // check if user clicks the left mouse button, then display a popup box
	case WM_LBUTTONDOWN:

		MessageBox(0, L"Hello, World", L"Hello", MB_OK);
		return 0;



	// exit if the ESC key is pressed
	case WM_KEYDOWN:

		if (wParam == VK_ESCAPE)

			DestroyWindow(ghMainWnd);

		return 0;

	// quit Windows

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;

	}

	// forward messages not processed

	return DefWindowProc(hWnd, msg, wParam, lParam);

}

