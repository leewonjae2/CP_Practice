#include <iostream>

#include "Point.h"
#include "PolyLine.h"


using namespace std;
using namespace lab4;
int main()
{
	PolyLine pl;

	pl.AddPoint(1, 2);
	pl.AddPoint(-4, 3);
	pl.AddPoint(5, 5);
	pl.AddPoint(3, -1);

	pl = pl;

	cout << pl[0]->GetX() << ", " << pl[0]->GetY() << endl;
	cout << pl[1]->GetX() << ", " << pl[1]->GetY() << endl;
	cout << pl[2]->GetX() << ", " << pl[2]->GetY() << endl;
	cout << pl[3]->GetX() << ", " << pl[3]->GetY() << endl;

	return 0;

}