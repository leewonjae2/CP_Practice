#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);
		Boat operator=(const Boat& other);


		unsigned int GetSailSpeed() const;

		// Vehicle��(��) ���� ��ӵ�
		unsigned int GetMaxSpeed() const;
		void Travel();
	};
}