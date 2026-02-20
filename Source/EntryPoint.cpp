#include <Engine/Application.h>
#include <Engine/Logging.h>
#include <Engine/EngineDefines.h>

#include <stdexcept>
#include <memory>

using namespace SurrealStudio;

#ifdef _WIN64
	
int main(int argc, char** argv)
{
	try
	{
		std::unique_ptr<Application> app(Application::CreateApplication());
		if (app == nullptr)
		{
			std::cerr << "app variable is a null pointer! Entry Point.cpp at line " << __LINE__ << "in function " << __FUNCTION__ << " in file " << __FILE__ << "\n" << std::endl;
			return ENGINE_FAILURE;
		}

		app->InitializeEngine();
		app->RunEngine(800, 600, "Surreal Studio");
		app->ShutdownEngine();
		return ENGINE_SUCCESS;
	}
	catch (const std::exception& e) {
		std::cerr << "An exception occurred: " << e.what() << "\n" << std::endl;
		return ENGINE_FAILURE;
	}
	catch (...) {
		std::cerr << "An unknown exception occurred.\n" << std::endl;
		return ENGINE_FAILURE;
	}
}

#else
	#error "Unsupported platform! Surreal Studio currently only supports Windows 64-bit."
#endif