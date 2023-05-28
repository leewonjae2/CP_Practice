#include <cassert>
#include <cmath>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;

int main()
{
	PolyLine pl;
	pl.AddPoint(1.4f, 2.8f);
	pl.AddPoint(1.4f, 2.5f);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl.TryGetMinBoundingRectangle(&minP, &maxP); // min: [-2.9f, -1.0f], max: [6.2f, 5.5f]

	cout << minP.GetX()<< ", " << minP.GetY() << endl;
	cout << maxP.GetX() << ", " << maxP.GetY() << endl;

	return 0;
}