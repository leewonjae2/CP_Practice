#include "Lab2.h"
#include <fstream>

int main()
{
	using namespace std;
	ifstream fin;
	fin.open("C://case2.txt");

	lab2::PrintMaxFloat(fin, cout);

	return 0;
}