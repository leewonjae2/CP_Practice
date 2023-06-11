#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();


		// Vehicle��(��) ���� ��ӵ�
		unsigned int GetMaxSpeed() const;


		// IDrivable��(��) ���� ��ӵ�
		unsigned int GetDriveSpeed() const;

		Sedan operator=(const Sedan& other);
		void Travel();

	private:
		const Trailer* mTrailer;
	};
}