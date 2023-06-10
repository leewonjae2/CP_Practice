#pragma once

#include "Vehicle.h"

namespace assignment2
{


	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private:
		static bool mExist;
		static DeusExMachina* mInstance;
		Vehicle* mVehicle[10];
		unsigned int mVehicleCount;
	};
}