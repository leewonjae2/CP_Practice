#include <iostream>

#include "MyString.h"


int main()
{
	using namespace assignment1;

	MyString s("Hello");
	MyString s1("World");

	std::cout << s.GetCString() << std::endl;

	s = s1;

	std::cout << s.GetCString() << std::endl;

	return 0;

}