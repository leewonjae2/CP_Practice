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
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();


		// Vehicle을(를) 통해 상속됨
		unsigned int GetMaxSpeed() const;


		// IDrivable을(를) 통해 상속됨
		unsigned int GetDriveSpeed() const;

		void operator=(const Sedan& other);
		void Travel();

	private:
		const Trailer* mTrailer;
	};
}