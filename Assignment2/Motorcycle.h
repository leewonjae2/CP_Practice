#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();
		Motorcycle operator=(const Motorcycle& other);

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const;


		// IDrivable��(��) ���� ��ӵ�
		virtual unsigned int GetDriveSpeed() const;
		void Travel();
	};
}