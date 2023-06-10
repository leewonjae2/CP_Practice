#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int result = 0;
		double totalWeight = 0;

		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
		}


		result = static_cast<unsigned int>(totalWeight * (double)2 + 400 - pow(totalWeight / 15, 3) + 0.5);


		if (0 < result)
		{
			return result;
		}

		return 0;
	}
	void Motorcycle::Travel()
	{
		unsigned int count = GetTravelCount();
		if (count < 5)
		{
			Vehicle::Travel();
		}
		else if (count == 5)
		{
			ResetCounting();
		}
	}
}