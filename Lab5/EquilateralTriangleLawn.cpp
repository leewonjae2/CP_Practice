#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: mLength(length)
	{
	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}
	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(mLength * mLength * sqrt(3)) / 4;
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return mLength * 4 * 3;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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