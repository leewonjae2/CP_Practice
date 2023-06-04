#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int x, unsigned int y)
		: mX(x)
		, mY(y)
	{
	}
	RectangleLawn::~RectangleLawn()
	{
	}



	unsigned int RectangleLawn::GetArea() const
	{
		return mX * mY;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return (mX + mY) * 2 * 4;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return (GetMinimumFencesCount() / 4) * 6;
			break;
		case lab5::SPRUCE:
			return (GetMinimumFencesCount() / 4) * 7;
			break;
		default:
			break;
		}
		return 0;
	}
}