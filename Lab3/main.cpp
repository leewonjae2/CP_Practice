#include <iostream>
#include "TimeSheet.h"

int main()
{
	using namespace std;
	lab3::TimeSheet p("Pope", 10);
	

	cout << p.GetName()  << endl;

	return 0;
}