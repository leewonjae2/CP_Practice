#include <iostream>
#include "TimeSheet.h"

int main()
{
	using namespace std;
	lab3::TimeSheet p("Pope", 2);

	p.AddTime(1);
	p.AddTime(2);
	p.AddTime(3);

	lab3::TimeSheet p2(p);
	
	p2.AddTime(4);
	p2.AddTime(5);
	p2.AddTime(6);

	cout << p.GetName() << endl;
	cout << p.GetName() << endl << endl;

	cout << p.GetTotalTime() << endl;
	cout << p2.GetTotalTime() << endl << endl;

	cout << p.GetAverageTime() << endl;
	cout << p2.GetAverageTime() << endl << endl;

	cout << p.GetStandardDeviation() << endl;
	cout << p2.GetStandardDeviation() << endl << endl;


	return 0;
}