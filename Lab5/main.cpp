#include <cassert>

#include "Lawn.h"
#include "IFenceable.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace lab5;

int main()
{
	Lawn* lawn = new RectangleLawn(10, 20);
	int area = lawn->GetArea();
	int grassPrice = lawn->GetGrassPrice(BERMUDA);
	int sodRollsCount = lawn->GetMinimumSodRollsCount();

	assert(area == 200);
	assert(grassPrice == 1600);
	assert(sodRollsCount == 667);

	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;

	int fencePrice = rectangleLawn->GetFencePrice(RED_CEDAR);
	int fencesCount = rectangleLawn->GetMinimumFencesCount();

	assert(fencePrice == 360);
	assert(fencesCount == 240);

	delete lawn;

	return 0;
}