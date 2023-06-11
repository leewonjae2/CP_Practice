#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person();
		Person(const char* name, unsigned int weight);
		Person(const Person& other);
		virtual ~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
		Person& operator=(const Person& other);

	private:
		std::string mName;
		unsigned int mWeight;
	};
}