#include <cassert>
#include <cmath>
#include <iostream>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	QueueStack<int> a(3);
	a.Enqueue(1);
	a.Enqueue(2);
	a.Enqueue(3);
	a.Enqueue(4);
	a.Enqueue(5);


	std::cout << a.Dequeue();
	std::cout << a.Peek();


	return 0;
}