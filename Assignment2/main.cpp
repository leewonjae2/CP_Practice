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
	Person* p1 = new Person("P1",85 );
	Person* p2 = new Person("P2", 70);

	Boat boat = Boat(5);
	
	boat.AddPassenger(p1);
	boat.AddPassenger(p2);

	cout << boat.GetSailSpeed();

	return 0;

}