#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(NULL)
	{
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, mTrailer(NULL)
	{
		if (other.mTrailer != NULL)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
	}

	Sedan::~Sedan()
	{
		RemoveTrailer();
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != NULL)
		{
			return false;
		}

		mTrailer = trailer;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer != NULL)
		{
			delete mTrailer;
			mTrailer = NULL;
			return true;
		}

		return false;
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeight = 0;

		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			totalWeight += (GetPassenger(i)->GetWeight());
		}

		if (mTrailer != NULL)
		{
			totalWeight += mTrailer->GetWeight();
		}

		if (totalWeight > 350)
		{
			return 300;
		}
		else if (totalWeight > 260)
		{
			return 380;
		}
		else if (totalWeight > 160)
		{
			return 400;
		}
		else if (totalWeight > 80)
		{
			return 458;
		}
		else if (totalWeight <= 80)
		{
			return 480;
		}
		return 480;
	}

	Sedan Sedan::operator=(const Sedan& other)
	{
		Vehicle::operator=(other);


		const Trailer* temp = mTrailer;

		if (other.mTrailer != NULL && temp != NULL)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
			delete temp;
		}
		else if (other.mTrailer == NULL && temp != NULL)
		{
			delete temp;
			mTrailer = NULL;
		}
		else if (other.mTrailer != NULL && temp == NULL)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
		else if (other.mTrailer == NULL && temp == NULL)
		{
		}
		return *this;
	}

	void Sedan::Travel()
	{
		unsigned int count = GetTravelCount();
		if (mTrailer == NULL)
		{
			if (count < 5)
			{
				Vehicle::Travel();
			}
			else if (count == 5)
			{
				ResetCounting();
			}
		}
		else if (mTrailer != NULL)
		{
			if (count < 5)
			{
				Vehicle::Travel();
			}
			else if (count == 5)
			{
				TravelCounting();
			}
			else if (count == 6)
			{
				ResetCounting();
			}
		}
	}


}