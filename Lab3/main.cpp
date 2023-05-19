#include <iostream>
#include "TimeSheet.h"


using namespace std;
void test()
{
	lab3::TimeSheet p1;
	lab3::TimeSheet p2("pope", 3);


	p1 = p2;

	cout << p1.GetName() << endl;
	cout << p2.GetName() << endl;

}

int main()
{
	test();


	return 0;
}

