#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		virtual ~UBoat();
		UBoat operator=(const UBoat& other);

		// Vehicle을(를) 통해 상속됨
		unsigned int GetMaxSpeed() const;

		// ISailable을(를) 통해 상속됨
		unsigned int GetSailSpeed() const;

		// IDivable을(를) 통해 상속됨
		unsigned int GetDiveSpeed() const;
		void Travel();
	};
}