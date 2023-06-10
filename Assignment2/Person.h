#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person();
		Person(const char* name, unsigned int weight);
		virtual ~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;

	private:
		const std::string mName;
		unsigned int mWeight;
	};
}