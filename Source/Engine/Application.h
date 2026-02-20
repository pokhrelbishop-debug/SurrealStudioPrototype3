#pragma once

#include <SurrealEditor/SurrealStudioMainWindow.h>

namespace SurrealStudio {

	class Application
	{
	public:

		Application() = default;
		~Application() = default;

		bool InitializeEngine();
		bool RunEngine(int width, int height, const char* title);
		bool ShutdownEngine();

		static Application* CreateApplication();

	private:

		bool m_Running = true;
		SurrealEditor::SurrealStudioMainWindow m_MainWindow;
	};
}