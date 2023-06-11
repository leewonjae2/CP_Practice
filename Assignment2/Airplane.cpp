#include <math.h>

#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle::Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}



	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int maxSpeed = GetFlySpeed();

		if (maxSpeed < GetDriveSpeed())
		{
			return GetDriveSpeed();
		}

		return maxSpeed;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double totalWeight = 0;


		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
		}

		return static_cast<unsigned int>((4.0 * exp((400.0 - totalWeight) / 70.0)) + 0.5);
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double totalWeight = 0;


		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += static_cast<double>(GetPassenger(i)->GetWeight());
		}

		return static_cast<unsigned int>((200.0 * exp((800.0 - totalWeight) / 500.0)) + 0.5);
	}

	void Airplane::Travel()
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

	Airplane Airplane::operator=(const Airplane& other)
	{
		Vehicle::operator=(other);

		return *this;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{

		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		if (GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < GetPassengersCount(); i++)
			{
				bp.AddPassenger(GetPassenger(i));
			}
			ResetPassenger();
		}

		if (boat.GetPassengersCount() > 0)
		{
			for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
			{
				bp.AddPassenger(boat.GetPassenger(i));
			}
			boat.ResetPassenger();
		}

		return bp;
	}

}