#include "CircleLawn.h"
#include <math.h>

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}
	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mRadius * mRadius * 3.14 / 4);
	}
}
