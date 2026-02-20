#include "SurrealStudioMainWindow.h"
#include <Engine/Logging.h>

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>

namespace SurrealStudio {

	namespace SurrealEditor {

		bool SurrealStudioMainWindow::InitalizeMainEngineWindow()
		{
			if (!glfwInit())
			{
				std::cerr << "Failed to initalize GLFW at file " << __FILE__  << " in function " << __FUNCTION__ << " at line " << __LINE__ << "\n" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			return true;
		}
		bool SurrealStudioMainWindow::CreateMainEngineWindow(int width, int height, const char* title)
		{
			m_MainWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
			if (!m_MainWindow)
			{
				std::cerr << "Failed to create GLFW window at file " << __FILE__ << " in function " << __FUNCTION__ << " at line " << __LINE__ << "\n" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_MainWindow);
			
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cerr << "Failed to initialize GLAD at file " << __FILE__ << " in function " << __FUNCTION__ << " at line " << __LINE__ << "\n" << std::endl;
				glfwDestroyWindow(m_MainWindow);
				glfwTerminate();
				return false;
			}

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			return true;
		}
		bool SurrealStudioMainWindow::RunMainEngineWindow()
		{
			if (!m_MainWindow) return false;

			while (!glfwWindowShouldClose(m_MainWindow))
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glfwSwapBuffers(m_MainWindow);
				glfwPollEvents();
			}

			return true;
		}
		bool SurrealStudioMainWindow::ShutdownMainEngineWindow()
		{
			if (!m_MainWindow) return false;

			glfwDestroyWindow(m_MainWindow);
			glfwTerminate();
			return true;
		}
	}
}