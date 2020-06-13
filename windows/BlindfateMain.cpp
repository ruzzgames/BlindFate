#include "pch.h"
#include "BlindfateMain.h"
#include "Common\DirectXHelper.h"
using namespace DirectX;

using namespace Blindfate;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

// The DirectX 12 Application template is documented at https://go.microsoft.com/fwlink/?LinkID=613670&clcid=0x409

// Loads and initializes application assets when the application is loaded.
BlindfateMain::BlindfateMain()
{
	// TODO: Change the timer settings if you want something other than the default variable timestep mode.
	// e.g. for 60 FPS fixed timestep update logic, call:
	/*
	m_timer.SetFixedTimeStep(true);
	m_timer.SetTargetElapsedSeconds(1.0 / 60);
	*/

	// initialise game variables

	// init keyboard states
	m_forward = false;
	m_backward = false;
	m_left = false;
	m_right = false;
	m_up = false;
	m_down = false;
	m_pause = false;
	m_menu = false;
	m_tracking = false;
	m_quit = false;


}

// Creates and initializes the renderers.
void BlindfateMain::CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources)
{
	// TODO: Replace this with your app's content initialization.
	m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(deviceResources));
	

	OnWindowSizeChanged();
}

// Updates the application state once per frame.
void BlindfateMain::Update()
{
	// Update scene objects.
	m_timer.Tick([&]()
	{
		// TODO: Replace this with your app's content update functions.

		if (m_tracking == true)
			m_sceneRenderer->StartTracking();
		else
			m_sceneRenderer->StopTracking();

		

		m_sceneRenderer->Update(m_timer);

		// shows FPS in Output window when debugging
		// OutputDebugStringA("FPS\n");

	});
}

// Renders the current frame according to the current application state.
// Returns true if the frame was rendered and is ready to be displayed.
bool BlindfateMain::Render()
{
	// Don't try to render anything before the first Update.
	if (m_timer.GetFrameCount() == 0)
	{
		return false;
	}

	// Render the scene objects.
	// TODO: Replace this with your app's content rendering functions.

	// check if user presses "1" to display wireframe, otherwise displays as solid
	if (m_IsWireframe == true)
		m_sceneRenderer->m_displayWireframe = true;
	else
		m_sceneRenderer->m_displayWireframe = false;


	return m_sceneRenderer->Render();
}


// detect what key is pressed on the keyboard
// take relevant action
void Blindfate::BlindfateMain::OnKeyPress(Windows::System::VirtualKey Key)
{

	if (Key == (Windows::System::VirtualKey::W))
	{
		m_forward = true;
		OutputDebugStringA("pressed W\n");  // show message to Output window while debugging - useful for testing
	}
	if (Key == (Windows::System::VirtualKey::S))
		m_backward = true;
	if (Key == (Windows::System::VirtualKey::Number1))
		m_IsWireframe = true;
	if (Key == (Windows::System::VirtualKey::A))
		m_left = true;
	if (Key == (Windows::System::VirtualKey::D))
		m_right = true;
	if (Key == (Windows::System::VirtualKey::Space))
		m_up = true;
	if (Key == (Windows::System::VirtualKey::X))
		m_down = true;
	if (Key == (Windows::System::VirtualKey::P))
		m_pause = true;
	if (Key == (Windows::System::VirtualKey::Escape))
		m_menu = true;
	if (Key == (Windows::System::VirtualKey::T))
		m_tracking = true;
	if (Key == (Windows::System::VirtualKey::Q))
		m_quit = true;

}

// detect what key is released on the keyboard
void Blindfate::BlindfateMain::OnKeyRelease(Windows::System::VirtualKey Key)
{

	if (Key == (Windows::System::VirtualKey::W))
		m_forward = false;
	if (Key == (Windows::System::VirtualKey::S))
		m_backward = false;
	if (Key == (Windows::System::VirtualKey::Number1))
		m_IsWireframe = false;
	if (Key == (Windows::System::VirtualKey::A))
		m_left = false;
	if (Key == (Windows::System::VirtualKey::D))
		m_right = false;
	if (Key == (Windows::System::VirtualKey::Space))
		m_up = false;
	if (Key == (Windows::System::VirtualKey::X))
		m_down = false;
	if (Key == (Windows::System::VirtualKey::P))
		m_pause = false;
	if (Key == (Windows::System::VirtualKey::Escape))
		m_menu = false;
	if (Key == (Windows::System::VirtualKey::T))
		m_tracking = false;
	if (Key == (Windows::System::VirtualKey::Q))
		m_quit = false;

}

// Updates application state when the window's size changes (e.g. device orientation change)
void BlindfateMain::OnWindowSizeChanged()
{
	// TODO: Replace this with the size-dependent initialization of your app's content.
	m_sceneRenderer->CreateWindowSizeDependentResources();
}

// Notifies the app that it is being suspended.
void BlindfateMain::OnSuspending()
{
	// TODO: Replace this with your app's suspending logic.

	// Process lifetime management may terminate suspended apps at any time, so it is
	// good practice to save any state that will allow the app to restart where it left off.

	m_sceneRenderer->SaveState();

	// If your application uses video memory allocations that are easy to re-create,
	// consider releasing that memory to make it available to other applications.
}

// Notifes the app that it is no longer suspended.
void BlindfateMain::OnResuming()
{
	// TODO: Replace this with your app's resuming logic.
}

// Notifies renderers that device resources need to be released.
void BlindfateMain::OnDeviceRemoved()
{
	// TODO: Save any necessary application or renderer state and release the renderer
	// and its resources which are no longer valid.
	m_sceneRenderer->SaveState();
	m_sceneRenderer = nullptr;
}
