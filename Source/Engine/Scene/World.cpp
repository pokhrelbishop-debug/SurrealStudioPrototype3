#include "World.h"

namespace SurrealStudio {

	namespace SceneSystem {

		bool World::AddWorld(const std::string& name) noexcept
		{
			auto newWorld = std::make_unique<WorldData>();
			newWorld->worldName = name;
			newWorld->id = static_cast<int>(m_Worlds.size()) + 1; // Assign a unqiue ID
			m_Worlds.push_back(std::move(newWorld));
			return true;
		}

		bool World::RemoveWorld(const std::string& name) noexcept
		{
			if (m_Worlds.empty())
				return false; // there is no world to remove.

			for (auto it = m_Worlds.begin(); it != m_Worlds.end(); it++)
			{
				if ((*it)->worldName == name)
				{
					m_Worlds.erase(it);
					return true;
				}
			}

			return false; // could not find the world with the given name.
						 // returning false to indicate failure.
						 // Exception will not be thrown here as a noexcept keyword is given. We can also throw an exception here if we want to handle it differently. To do that, the noexcept keyword needs to be removed from the function declaration.
		}

		std::string World::GetWorldNameByID(int id) const noexcept
		{
			for (const auto& i : m_Worlds)
			{
				if (i->id == id)
				{
					return i->worldName;
				}
			}

			return ""; // could not find world with the given id.
			// returning an empty string to indicate failure. Exception will not be thrown here as a noexcept keyword is given. We can also throw an exception here if we want to handle it differently.
					  // but we need to remove the noexcept keyword from the function declaration in that case.
		}

		int World::GetWorldIDByName(const std::string& name) const noexcept
		{
			for (const auto& i : m_Worlds)
			{
				if (i->worldName == name)
				{
					return i->id;
				}
			}
			return 0;
		}
	}
}