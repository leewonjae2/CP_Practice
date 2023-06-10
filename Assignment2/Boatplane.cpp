#include <math.h>
#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}


	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int maxSpeed = GetFlySpeed();

		if (maxSpeed < GetSailSpeed())
		{
			maxSpeed = GetSailSpeed();
		}

		return maxSpeed;
	}


	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int result = 0;
		double totalWeight = 0;

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
			}
		}

		result = static_cast<unsigned int>(150.0 * exp((500.0 - totalWeight) / 300.0) + 0.5);

		return result;
	}


	unsigned int Boatplane::GetSailSpeed() const
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

		result = static_cast<unsigned int>((800.0 - totalWeight * 1.7) + 0.5);

		if (20 < result)
		{
			return result;
		}

		return 20;
	}
	inline void Boatplane::Travel()
	{
		unsigned int count = GetTravelCount();
		if (count == 0)
		{
			Vehicle::Travel();
		}
		else if (count < 3)
		{
			TravelCounting();
		}
		else if (count == 3)
		{
			ResetCounting();
		}
	}
}