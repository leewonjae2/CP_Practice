#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

void TestTravel()
{
	Airplane* airplane = new Airplane(0);
	Boat* boat = new Boat(0);
	DeusExMachina* deus = DeusExMachina::GetInstance();

	deus->AddVehicle(airplane);
	deus->AddVehicle(boat);

	deus->Travel();

	assert(deus->GetFurthestTravelled() == airplane);
}

void Test()
{
	DeusExMachina* d = DeusExMachina::GetInstance();

	uint32_t traveledDistanceArr[7][13] =
	{
		{1213,1213,1213,1213,2426,2426,2426,2426,3639,3639,3639,3639,4852},
		{ 800, 1600, 1600, 2400, 3200, 3200, 4000, 4800, 4800, 5600, 6400, 6400, 7200},
		{800, 800, 800, 800, 1600, 1600, 1600, 1600,  2400, 2400, 2400, 2400, 3200 },
		{400,800,1200,1600,2000,2000,2400,2800,3200,3600,4000,4000,4400 },
		{480,960,1440,1920,2400,2400,2880,3360,3840,4320,4800,4800,5280},
		{480,960,1440,1920,2400,2400,2400,2880,3360,3840,4320,4800,4800},
		{550,1100,1100,1100,1100,1100,1650,2200,2200,2200,2200,2200,2750}
	};

	Airplane* t1 = new Airplane(2);
	Boat* t2 = new Boat(2);
	Boatplane* t3 = new Boatplane(2);
	Motorcycle* t4 = new Motorcycle();
	Sedan* t5 = new Sedan();
	Sedan* t6 = new Sedan();
	t6->AddTrailer(new Trailer(1));
	UBoat* t7 = new UBoat();

	Vehicle* vArr[7] = { t1,t2,t3,t4,t5,t6,t7 };

	for (size_t j = 0; j < 7; ++j)
	{
		d->AddVehicle(vArr[j]);
		for (size_t i = 0; i < 13; ++i)
		{
			d->Travel();
			assert(traveledDistanceArr[j][i] == d->GetVehicle(0)->GetDistance());
		}
		d->RemoveVehicle(0);
	}
	delete d;
	
}


int main()
{
	Test();

	return 0;
}