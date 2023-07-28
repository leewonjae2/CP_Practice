#include <cassert>

#include "Storage.h"

using namespace lab11;

int main()
{
	Storage<int> storage1(8000);
	Storage<int> storage2(10000);

	storage1 = std::move(storage1);


	return 0;
}