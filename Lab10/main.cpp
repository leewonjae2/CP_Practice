#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

int main()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));


	list.Delete(1);
	list.Delete(7);
	list.Delete(3);

	
	return 0;
}