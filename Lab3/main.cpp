#include <iostream>
#include "TimeSheet.h"

int main()
{
	using namespace std;
	lab3::TimeSheet p("Pope", 10);


	string a = p.GetName();


	cout << a << endl;

	return 0;
}