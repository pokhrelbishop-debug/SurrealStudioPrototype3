#include "Application.h"

#include <iostream>

namespace SurrealStudio {

	bool Application::InitializeEngine()
	{
		std::cout << "Initializing Surreal Studio Engine..." << std::endl;
		return true; 
	}

	bool Application::RunEngine(int width, int height, const char* title)
	{
		m_MainWindow.InitalizeMainEngineWindow();
		m_MainWindow.CreateMainEngineWindow(width, height, title);
		m_MainWindow.RunMainEngineWindow();

		std::cout << "Running Surreal Studio Engine..." << std::endl;

		m_MainWindow.ShutdownMainEngineWindow();
		return true;
	}

	bool Application::ShutdownEngine()
	{
		std::cout << "Shutting down Surreal Studio Engine..." << std::endl;
		return true; 
	}

	Application* Application::CreateApplication()
	{
		return new Application();
	}
}