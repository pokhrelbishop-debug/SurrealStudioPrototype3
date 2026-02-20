#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

namespace SurrealStudio {

	namespace SurrealEditor {

		class SurrealStudioMainWindow
		{
		public:

			SurrealStudioMainWindow() = default;
			~SurrealStudioMainWindow() = default;

			bool InitalizeMainEngineWindow();
			bool CreateMainEngineWindow(int width, int height, const char* title);
			bool RunMainEngineWindow();
			bool ShutdownMainEngineWindow();

		private:

			GLFWwindow* m_MainWindow = nullptr; 
		};
	}
}
