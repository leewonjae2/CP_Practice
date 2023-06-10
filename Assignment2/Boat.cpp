#include "Boat.h"
#include "Airplane.h"



namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}


	unsigned int Boat::GetSailSpeed() const
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
		result = static_cast<int>(800.0 - (totalWeight * 10.0) + 0.5);
		if (20 < result)
		{
			return static_cast<unsigned int>(result);
		}

		return 20;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	inline void Boat::Travel()
	{
		unsigned int count = GetTravelCount();
		if (count < 2)
		{
			Vehicle::Travel();
		}
		else if (count == 2)
		{
			ResetCounting();
		}
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		if (plane.GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
			{
				bp.AddPassenger(plane.GetPassenger(i));
			}
			plane.ResetPassenger();
		}

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				bp.AddPassenger(GetPassenger(i));
			}
			ResetPassenger();
		}

		return bp;
	}


}