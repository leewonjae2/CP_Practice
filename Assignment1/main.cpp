#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>

#include "MyString.h"

using namespace assignment1;
using namespace std;

// 202109 ass1 test cases by seolbeen

int main()
{
	MyString p1("hello");
	MyString p2(p1);
	p1 = p1;
	
	cout << p1.GetCString() << endl;

	return 0;
}