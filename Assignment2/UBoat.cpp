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

		return 0;
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		double totalWeight = 0;
		unsigned int result = 20;

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
			}
		}
		result = static_cast<unsigned int>((double)500 - (totalWeight / (double)10) + 0.5);
		if (200 < result)
		{
			return result;
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

		result = static_cast<unsigned int>(((double)500 * log(((totalWeight + (double)150) / (double)150)) + 30) + 0.5);


		return 0;
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