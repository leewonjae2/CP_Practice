#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"
#include <iostream>

using namespace assignment2;
using namespace std;
int main()
{
	Airplane airplane1 = Airplane(5);
	Airplane airplane2 = Airplane(5);

	airplane1.AddPassenger(new Person("ap1", 75));
	airplane1.AddPassenger(new Person("ap2", 75));

	airplane2.AddPassenger(new Person("ap3", 75));
	airplane2.AddPassenger(new Person("ap4", 75));

	Boat boat1 = Boat(5);
	Boat boat2 = Boat(5);

	boat1.AddPassenger(new Person("bp1", 75));
	boat1.AddPassenger(new Person("bp2", 75));

	boat2.AddPassenger(new Person("bp3", 75));
	boat2.AddPassenger(new Person("bp4", 75));


	Boat bp_b = Boat(5);

	bp_b.AddPassenger(new Person("bpp1", 75));
	bp_b.AddPassenger(new Person("bpp2", 75));

	Airplane bp_a = Airplane(5);

	bp_a.AddPassenger(new Person("bpp3", 75));
	bp_a.AddPassenger(new Person("bpp4", 75));

	Boatplane bp1 = bp_a + bp_b;
	

	DeusExMachina* deus = DeusExMachina::GetInstance();

	deus->AddVehicle(&boat1);
	deus->AddVehicle(&boat2);
	deus->AddVehicle(&airplane1);
	deus->AddVehicle(&airplane2);
	deus->AddVehicle(&bp1);


	cout << deus->GetFurthestTravelled()->GetPassenger(0)->GetName() << endl;

	deus->Travel();
	deus->Travel();
	deus->Travel();
	deus->Travel();
	deus->Travel();
	deus->Travel();

	cout << "boat1 : " << boat1.GetDistance() << endl;
	cout << "boat2 : " << boat2.GetDistance() << endl;
	cout << "airplane1 : " << airplane1.GetDistance() << endl;
	cout << "airplane2 : " << airplane2.GetDistance() << endl;
	cout << "bp1 : " << bp1.GetDistance() << endl;

	cout << deus->GetFurthestTravelled()->GetPassenger(0)->GetName() << endl;

	Boat* boat3 = new Boat(boat1);
	boat1 = boat1;
	cout << boat1.GetPassenger(0)->GetName();

	return 0;

}