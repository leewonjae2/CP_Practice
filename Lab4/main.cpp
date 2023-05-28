#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace std;
using namespace lab4;

void doSomething()
{
	PolyLine pl1;
	PolyLine pl2;

	pl1.AddPoint(1.0f, 2.0f);
	pl1.AddPoint(3.0f, 2.0f);

	pl2.AddPoint(5.1f, 1.0f);
	pl2.AddPoint(1.0f, 5.0f);

	pl1 = pl2;
}

void doNothing()
{
	PolyLine pl1;

	pl1.AddPoint(1.0f, 2.0f);
	pl1.AddPoint(3.0f, 2.0f);

	pl1 = pl1;
}

int main()
{
	doSomething();
	doNothing();

	return 0;

}