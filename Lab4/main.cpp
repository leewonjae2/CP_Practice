#include <iostream>

#include "Point.h"
#include "PolyLine.h"


using namespace lab4;
using namespace std;

int main()
{
	
	PolyLine pl;
	pl.AddPoint(1.7f, 2.4f);
	pl.AddPoint(3.9f, 2.1f);
	pl.AddPoint(5.3f, 5.5f);
	pl.AddPoint(-2.1f, 4.0f);


	cout << pl[0]->GetX() << " " << pl[0]->GetY() << endl;
	cout << pl[3]->GetX() << " " << pl[3]->GetY() << endl;

	return 0;
}
