#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(Vehicle& other);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void Travel();
		void TravelCounting();
		void ResetCounting();
		unsigned int GetTravelCount();
		unsigned int GetDistance();
		const Vehicle* GetFurthestTravelled();
		void SetFurthestTravelled();
		
		bool ResetPassenger();
		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		virtual void operator=(const Vehicle& other);

	private:
		unsigned int mMaxPassengerCount;
		unsigned int mPassengerCount;
		const Person** mPassenger;
		unsigned int mDistance;
		unsigned int mTravelCount;
	};
}