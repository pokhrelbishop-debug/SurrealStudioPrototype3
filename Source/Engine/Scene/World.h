#pragma once

#include <string>
#include <vector>
#include <memory>

namespace SurrealStudio {

	namespace SceneSystem {
		
		struct WorldData
		{
			std::string worldName;
			int id;
			// later store a vector of objects in the world (Objects = entities)
		};

		class World
		{
		public:

			World() = default;
			~World() = default;

			bool AddWorld(const std::string& name) noexcept;
			bool RemoveWorld(const std::string& name) noexcept;
			
			std::string GetWorldNameByID(int id) const noexcept;
			int GetWorldIDByName(const std::string& name) const noexcept;

		private:

			WorldData m_WorldData;
			std::vector<std::unique_ptr<WorldData>> m_Worlds;
		};
	}
}