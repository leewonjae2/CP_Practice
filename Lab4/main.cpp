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

	cout << pl.RemovePoint(1) << endl; // pl�� [1.0f, 2.0f], [2.2f, 1.9f]. true�� ��ȯ.

	cout << pl.RemovePoint(2) << endl; // 4��° ���� �������� �ʱ� ������ pl�� ������ ����. false�� ��ȯ.

	return 0;
}
