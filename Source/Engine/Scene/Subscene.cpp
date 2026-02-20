#include "Subscene.h"

namespace SurrealStudio {

	namespace SceneSystem {

		bool Subscene::AddSubscene(const std::string& name) noexcept
		{
			auto newSubscene = std::make_unique<SubsceneData>();
			newSubscene->subsceneName = name;
			newSubscene->id = static_cast<int>(m_Subscenes.size()) + 1; // Assign a unqiue ID
			m_Subscenes.push_back(std::move(newSubscene));
			return true;
		}

		bool Subscene::RemoveSubscene(const std::string& name) noexcept
		{
			if (m_Subscenes.empty())
				return false; // there is no subscene to remove.

			for (auto it = m_Subscenes.begin(); it != m_Subscenes.end(); it++)
			{
				if ((*it)->subsceneName == name)
				{
					m_Subscenes.erase(it);
					return true;
				}
			}
			
			return false; // could not find subscene with the given name.
		}

		std::string Subscene::GetSubsceneNameByID(int id) const noexcept
		{
			for (const auto& i : m_Subscenes)
			{
				if (i->id == id)
				{
					return i->subsceneName;
				}
			}

			return ""; // could not find subscene with the given id.
			// returning empty string to indicate failure.
		}

		int Subscene::GetSubsceneIDByName(const std::string& name) const noexcept
		{
			for (const auto& i : m_Subscenes)
			{
				if (i->subsceneName == name)
				{
					return i->id;
				}
			}
			return 0; // could not find subscene with the given name.
			// returning 0 to indicate failure. (assuming id starts from 1)
		}
	}
}