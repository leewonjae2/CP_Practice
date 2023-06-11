#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		unsigned int GetFlySpeed() const;
		void Travel();
		Airplane operator=(const Airplane& other);

		Boatplane operator+(Boat& boat);


	};
}