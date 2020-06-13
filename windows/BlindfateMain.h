#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"


// Renders Direct3D content on the screen.
namespace Blindfate
{
	// main game class
	// m_main in App.cpp points to this class
	class BlindfateMain
	{
	public:
		BlindfateMain();
		void CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources);	// init DirectX graphics and create resources
		void Update();		// update game per frame
		bool Render();		// render drawn graphics per frame

		void OnKeyPress(Windows::System::VirtualKey Key);    // user pressed a key from keyboard
		void OnKeyRelease(Windows::System::VirtualKey Key);  // user released a key from keyboard

		void OnWindowSizeChanged();		// handle changing the window size
		void OnSuspending();			// handle app is suspended (eg: window minimised)
		void OnResuming();				// handle app is resuming (eg: from window minimised to active)
		void OnDeviceRemoved();			// handle device being removed


	private:
		// TODO: Replace with your own content renderers.
		std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;

		// game variables
		bool game_state;	// game states
		
		// keyboard
		bool m_forward;		// check if player is moving forward (W key)
		bool m_backward;	// check if player is moving backward (S key)
		bool m_left;		// check if player is moving left (A key)
		bool m_right;		// check if player is moving right(D key)
		bool m_up;			// check if player is moving up (Space key)
		bool m_down;		// check if player is moving down (X key)
		bool m_pause;		// check if player wants to pause the game (P key)
		bool m_menu;		// check if player wants the show the menu (ESC key)
		bool m_IsWireframe; // user presses the "1" key to show wireframe rendering
		bool m_tracking;	// turn on cube tracking (stops rotating cube) when user presses T
		bool m_quit;		// user presses Q to quit


	};
}