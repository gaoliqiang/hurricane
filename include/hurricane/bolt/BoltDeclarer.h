#pragma once

#include "hurricane/task/TaskDeclarer.h"
#include <memory>
#include <string>

namespace hurricane {
	namespace bolt {
		class IBolt;

		class BoltDeclarer : public hurricane::task::TaskDeclarer {
		public:
			BoltDeclarer() = default;
			BoltDeclarer(const std::string& boltName, IBolt* bolt);

			BoltDeclarer& ParallismHint(int parallismHint) {
				SetParallismHint(parallismHint);

				return *this;
			}
			
			BoltDeclarer& Global(const std::string& sourceTaskName) {
				SetSourceTaskName(sourceTaskName);
				SetGroupMethod(hurricane::task::TaskDeclarer::GroupMethod::Global);

				return *this;
			}

			BoltDeclarer& Random(const std::string& sourceTaskName) {
				SetSourceTaskName(sourceTaskName);
				SetGroupMethod(hurricane::task::TaskDeclarer::GroupMethod::Random);

				return *this;
			}

			BoltDeclarer& Group(const std::string& sourceTaskName, const std::string& groupField) {
				SetSourceTaskName(sourceTaskName);
				SetGroupMethod(hurricane::task::TaskDeclarer::GroupMethod::Field);
				SetGroupField(groupField);

				return *this;
			}

			const std::string& GetGroupField() const {
				return _groupField;
			}

			void SetGroupField(const std::string& groupField) {
				_groupField = groupField;
			}
		private:
			std::shared_ptr<IBolt> _bolt;
			std::string _groupField;
		};
	}
}