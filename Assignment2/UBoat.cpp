#include "UBoat.h"
#include <math.h>

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}
	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int maxSpeed = GetSailSpeed();

		if (maxSpeed < GetDiveSpeed())
		{
			maxSpeed = GetDiveSpeed();
		}
		return maxSpeed;
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		double totalWeight = 0;
		int result = 20;

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
			}
		}
		result = static_cast<int>(550.0 - (totalWeight / 10.0) + 0.5);
		if (200 < result)
		{
			return static_cast<unsigned int>(result);
		}

		return 200;
	}
	unsigned int UBoat::GetDiveSpeed() const
	{
		double totalWeight = 0;
		unsigned int result = 0;

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
			}
		}

		result = static_cast<unsigned int>((500.0 * log(((totalWeight + 150.0) / 150.0)) + 30.0) + 0.5);


		return result;
	}
	void UBoat::Travel()
	{
		unsigned int count = GetTravelCount();
		if (count < 2)
		{
			Vehicle::Travel();
		}
		else if (count < 5)
		{
			TravelCounting();
		}
		else
		{
			ResetCounting();
		}
	}
}