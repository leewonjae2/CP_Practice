#pragma once

#include "Vehicle.h"

namespace assignment2
{


	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		~DeusExMachina();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicle(unsigned int i);

	private:
		static bool mExist;
		static DeusExMachina* mInstance;
		Vehicle* mVehicle[10];
		unsigned int mVehicleCount;
	};
}