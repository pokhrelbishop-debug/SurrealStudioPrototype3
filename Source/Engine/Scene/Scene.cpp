#include "Scene.h"

namespace SurrealStudio {

	namespace SceneSystem {

		bool Scene::AddScene() noexcept
		{
			if (!m_Scenes.empty())
				return false; // There will be only one scene in scene system. Another scene cannot be added.

			m_SceneData.sceneName = "Main Scene";
			m_Scenes.push_back(m_SceneData);

			return true;
		}

		bool Scene::RemoveScene() noexcept
		{
			if (m_Scenes.empty())
				return false; // There is no scene to remove.

			m_Scenes.clear(); // There will be only 1 scene.
			return true;
		}
	}
}