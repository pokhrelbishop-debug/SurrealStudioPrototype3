#pragma once

#include <string>
#include <vector>

#include "Subscene.h"

namespace SurrealStudio {

	namespace SceneSystem {

		struct SceneData
		{
			std::string sceneName;
			std::vector<SubsceneData> subscenes; // A scene can have multiple subscenes.
		};

		class Scene
		{
		public:

			Scene() = default;
			~Scene() = default;

			bool AddScene() noexcept;
			bool RemoveScene() noexcept;
			std::string GetSceneName() const noexcept { return m_SceneData.sceneName; }
			
		private:

			SceneData m_SceneData;
			std::vector<SceneData> m_Scenes;
		};
	}
}