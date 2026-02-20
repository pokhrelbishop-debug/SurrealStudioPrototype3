#pragma once

#include <string>
#include <vector>
#include <memory>

namespace SurrealStudio {

	namespace SceneSystem {
		
		struct SubsceneData
		{
			std::string subsceneName;
			int id;
			// add vector of Worlds later
		};

		class Subscene
		{
		public:

			Subscene() = default;
			~Subscene() = default;

			bool AddSubscene(const std::string& name) noexcept;
			bool RemoveSubscene(const std::string& name) noexcept;
			
			std::string GetSubsceneNameByID(int id) const noexcept;
			int GetSubsceneIDByName(const std::string& name) const noexcept;

		private:

			std::vector<std::unique_ptr<SubsceneData>> m_Subscenes;
			SubsceneData m_SubsceneData;
		};
	}
}