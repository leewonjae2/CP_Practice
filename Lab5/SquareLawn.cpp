#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int x)
		: mX(x)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mX * mX;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return mX * 4 * 4;;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return GetMinimumFencesCount() / 4 * 6;
			break;
		case lab5::SPRUCE:
			return GetMinimumFencesCount() / 4 * 7;
			break;
		default:
			break;
		}
		return 0;
	}


}