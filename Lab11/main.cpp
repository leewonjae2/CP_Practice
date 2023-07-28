#include <cassert>

#include "Storage.h"

using namespace lab11;

int main()
{
	Storage<int> storage1(8000, 100);
	Storage<int> storage2(10000);

	storage1 = storage1;

	return 0;
}