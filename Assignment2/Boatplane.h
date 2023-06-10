#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		virtual ~Boatplane();
		unsigned int GetMaxSpeed() const;


		// IFlyable을(를) 통해 상속됨
		unsigned int GetFlySpeed() const;


		// ISailable을(를) 통해 상속됨
		unsigned int GetSailSpeed() const;
		void Travel();

	};
}