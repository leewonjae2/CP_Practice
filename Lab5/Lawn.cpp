#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		int price;
		double d_price;
		switch (grassType)
		{
		case lab5::BERMUDA:
			return static_cast<unsigned int>(8 * GetArea());
			break;
		case lab5::BAHIA:
			return static_cast<unsigned int>(5 * GetArea());
			break;
		case lab5::BENTGRASS:
			return static_cast<unsigned int>(3 * GetArea());
			break;
		case lab5::PERENNIAL_RYEGRASS:
			return static_cast<unsigned int>(2.5 * GetArea() + 0.5);
			break;
		case lab5::ST_AUGUSTINE:
			return static_cast<unsigned int>(4.5 * GetArea() + 0.5);
			break;
		default:
			break;
		}

		return 0;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double d_result;
		unsigned int result;

		d_result = GetArea() / 0.3;
		result = static_cast<int>(d_result);
		if (static_cast<double>(result) == d_result)
		{
			return result;
		}

		return result + 1;
	}
}