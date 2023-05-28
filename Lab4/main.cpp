#include <iostream>

#include "Point.h"
#include "PolyLine.h"


using namespace lab4;
using namespace std;

int main()
{
	
	
	PolyLine pl;
	pl.AddPoint(1.0f, 2.0f);
	pl.AddPoint(new Point(2.0f, 3.0f));
	pl.AddPoint(2.2f, 1.9f);

	cout << pl.RemovePoint(1) << endl; // pl은 [1.0f, 2.0f], [2.2f, 1.9f]. true를 반환.

	cout << pl.RemovePoint(2) << endl; // 4번째 점이 존재하지 않기 때문에 pl은 변하지 않음. false를 반환.

	return 0;
}
