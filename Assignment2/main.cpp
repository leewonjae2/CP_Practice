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

void Test1()
{
	DeusExMachina* d = DeusExMachina::GetInstance();

	Airplane a = Airplane(5);
	a.AddPassenger(new Person("aP", 75));

	a = a;

	cout << a.GetPassenger(0)->GetName() << endl;

	a = Airplane(a);

	cout << a.GetPassenger(0)->GetName() << endl;

	Airplane a1 = Airplane(a);

	cout << a1.GetPassenger(0)->GetName() << endl;

	a1 = a;

	cout << a1.GetPassenger(0)->GetName() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////


	Boat b = Boat(5);
	b.AddPassenger(new Person("bP", 75));

	b = b;

	cout << b.GetPassenger(0)->GetName() << endl;

	b = Boat(b);

	cout << b.GetPassenger(0)->GetName() << endl;

	Boat b1 = Boat(b);

	cout << b1.GetPassenger(0)->GetName() << endl;

	b1 = b;

	cout << b1.GetPassenger(0)->GetName() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////
	
	Boatplane bp = Boatplane(5);
	bp.AddPassenger(new Person("bPP", 75));

	bp = bp;

	cout << bp.GetPassenger(0)->GetName() << endl;

	bp = Boatplane(bp);

	cout << bp.GetPassenger(0)->GetName() << endl;

	Boatplane bp1 = Boatplane(bp);

	cout << bp1.GetPassenger(0)->GetName() << endl;

	bp1 = bp;

	cout << bp1.GetPassenger(0)->GetName() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////

	Motorcycle mt = Motorcycle();
	mt.AddPassenger(new Person("mtP", 75));

	mt = mt;

	cout << mt.GetPassenger(0)->GetName() << endl;

	mt = Motorcycle(mt);

	cout << mt.GetPassenger(0)->GetName() << endl;

	Motorcycle mt1 = Motorcycle(mt);

	cout << mt1.GetPassenger(0)->GetName() << endl;

	mt1 = mt;

	cout << mt1.GetPassenger(0)->GetName() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////

	Sedan sd = Sedan();
	sd.AddPassenger(new Person("sdP", 75));
	Sedan sd2 = Sedan();
	sd2.AddPassenger(new Person("sdP1", 75));

	sd = sd2;

	cout << sd.GetPassenger(0)->GetName() << endl;
	cout << sd.GetMaxSpeed() << endl;

	sd = Sedan(sd);

	cout << sd.GetPassenger(0)->GetName() << endl;
	cout << sd.GetMaxSpeed() << endl;

	Sedan sd1 = Sedan(sd);

	cout << sd1.GetPassenger(0)->GetName() << endl;
	cout << sd1.GetMaxSpeed() << endl;

	sd1 = sd;

	cout << sd1.GetPassenger(0)->GetName() << endl;
	cout << sd1.GetMaxSpeed() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////

	Sedan sdt = Sedan();
	sdt.AddPassenger(new Person("sdtP", 75));
	sdt.AddTrailer(new Trailer(100));

	sdt = sdt;

	cout << sdt.GetPassenger(0)->GetName() << endl;
	cout << sdt.GetMaxSpeed() << endl;

	sdt = Sedan(sdt);

	cout << sdt.GetPassenger(0)->GetName() << endl;
	cout << sdt.GetMaxSpeed() << endl;

	Sedan sdt1 = Sedan(sdt);

	cout << sdt1.GetPassenger(0)->GetName() << endl;
	cout << sdt1.GetMaxSpeed() << endl;

	sdt1 = sdt;

	cout << sdt1.GetPassenger(0)->GetName() << endl;
	cout << sdt1.GetMaxSpeed() << endl;

	cout << "////////////////////////////////////////" << endl;

	/////////////////////////////////////////////

	UBoat ub = UBoat();
	ub.AddPassenger(new Person("ubP", 75));

	ub = ub;

	cout << ub.GetPassenger(0)->GetName() << endl;

	ub = UBoat(ub);

	cout << ub.GetPassenger(0)->GetName() << endl;

	UBoat ub1 = UBoat(ub);

	cout << ub1.GetPassenger(0)->GetName() << endl;

	ub1 = ub;

	cout << ub1.GetPassenger(0)->GetName() << endl;


}

void DeusTest()
{
	DeusExMachina* d = DeusExMachina::GetInstance();
	

	for (int i = 0; i < 10; i++)
	{
		d->AddVehicle(new Airplane(5));
	}

	cout << d->RemoveVehicle(9) << endl;

	delete d;
}

int main(void)
{
	Boat bt(5);
	
	bt.AddPassenger(new Person("btP1", 75));
	bt.AddPassenger(new Person("btP2", 75));
	bt.AddPassenger(new Person("btP3", 75));
	bt.AddPassenger(new Person("btP4", 75));
	bt.AddPassenger(new Person("btP5", 75));

	bt = bt;

	cout << bt.GetPassenger(0)->GetName() << ", ";
	cout << bt.GetPassenger(1)->GetName() << ", ";
	cout << bt.GetPassenger(2)->GetName() << ", ";
	cout << bt.GetPassenger(3)->GetName() << ", ";
	cout << bt.GetPassenger(4)->GetName() << endl;

	Airplane ap(5);
	ap.AddPassenger(new Person("apP1", 75));
	ap.AddPassenger(new Person("apP2", 75));
	ap.AddPassenger(new Person("apP3", 75));
	ap.AddPassenger(new Person("apP4", 75));
	ap.AddPassenger(new Person("apP5", 75));


	ap = ap;

	cout << ap.GetPassenger(0)->GetName() << endl;

	Boatplane bp(5);
	bp.AddPassenger(new Person("bpP1", 75));
	bp.AddPassenger(new Person("bpP2", 75));
	bp.AddPassenger(new Person("bpP3", 75));
	bp.AddPassenger(new Person("bpP4", 75));
	bp.AddPassenger(new Person("bpP5", 75));


	bp = bp;

	cout << bp.GetPassenger(0)->GetName() << endl;

	Motorcycle mt;
	mt.AddPassenger(new Person("mtP1", 75));
	mt.AddPassenger(new Person("mtP2", 75));
	mt.AddPassenger(new Person("mtP3", 75));


	mt = mt;

	cout << mt.GetPassenger(0)->GetName() << endl;


	Sedan sd;
	Person sdP("sdP1", 75);
	
	sd.AddPassenger(&sdP);
	sd.AddPassenger(new Person("sdP2", 75));
	sd.AddPassenger(new Person("sdP3", 75));
	sd.AddPassenger(new Person("sdP4", 75));

	sd = sd;

	cout << sd.GetPassenger(0)->GetName() << endl;
	cout << sd.GetMaxSpeed()<< endl;

	Sedan sdt;
	sdt.AddPassenger(new Person("sdtP1", 75));
	sdt.AddPassenger(new Person("sdtP2", 75));
	sdt.AddPassenger(new Person("sdtP3", 75));
	sdt.AddPassenger(new Person("sdtP4", 75));

	sdt.AddTrailer(new Trailer(100));

	sdt = sdt;

	cout << sdt.GetPassenger(0)->GetName() << endl;
	cout << sdt.GetMaxSpeed() << endl;

	UBoat ub = UBoat();
	ub.AddPassenger(new Person("ubP1", 75));
	ub.AddPassenger(new Person("ubP2", 75));
	ub.AddPassenger(new Person("ubP3", 75));
	ub.AddPassenger(new Person("ubP4", 75));
	ub.AddPassenger(new Person("ubP5", 75));

	ub = ub;

	cout << ub.GetPassenger(0)->GetName() << endl;


	return 0;
}