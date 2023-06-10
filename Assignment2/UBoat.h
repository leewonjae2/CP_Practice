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

		// Vehicle��(��) ���� ��ӵ�
		unsigned int GetMaxSpeed() const;

		// ISailable��(��) ���� ��ӵ�
		unsigned int GetSailSpeed() const;

		// IDivable��(��) ���� ��ӵ�
		unsigned int GetDiveSpeed() const;
		void Travel();
	};
}