#include <iostream>
#include "TimeSheet.h"

int main()
{
	using namespace std;
	lab3::TimeSheet p("Pope", 10);

	p.AddTime(4);
	p.AddTime(7);
	p.AddTime(6);
	p.AddTime(5);
	p.AddTime(1);
	p.AddTime(2);

	cout << p.GetStandardDeviation() << endl;

	return 0;
}