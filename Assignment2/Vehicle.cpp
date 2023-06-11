#include "Vehicle.h"
#include "DeusExMachina.h"

namespace assignment2
{

	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengerCount(maxPassengersCount)
		, mPassengerCount(0)
		, mDistance(0)
		, mTravelCount(0)
	{
		mPassenger = new const Person * [mMaxPassengerCount];
		for (unsigned int i = 0; i < mMaxPassengerCount; i++)
		{
			mPassenger[i] = NULL;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengerCount(other.mMaxPassengerCount)
		, mPassengerCount(other.mPassengerCount)
		, mDistance(other.mDistance)
		, mTravelCount(other.mTravelCount)
	{
		mPassenger = new const Person * [mMaxPassengerCount];

		if (mPassengerCount <= mMaxPassengerCount)
		{
			for (unsigned int i = 0; i < mPassengerCount; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mPassengerCount; i++)
		{
			delete mPassenger[i];
		}
		delete[] mPassenger;
	}

	void Vehicle::Travel()
	{
		mDistance += GetMaxSpeed();
		mTravelCount++;
	}

	void Vehicle::TravelCounting()
	{
		mTravelCount++;
	}

	void Vehicle::ResetCounting()
	{
		mTravelCount = 0;
	}

	unsigned int Vehicle::GetTravelCount()
	{
		return mTravelCount;
	}

	unsigned int Vehicle::GetDistance()
	{
		return mDistance;
	}


	bool Vehicle::ResetPassenger()
	{
		for (unsigned int i = 0; i < mPassengerCount; i++)
		{
			mPassenger[i] = NULL;
		}
		mPassengerCount = 0;

		return true;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengerCount < mMaxPassengerCount)
		{
			mPassenger[mPassengerCount] = person;
			mPassengerCount++;

			return true;
		}
		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengerCount)
		{
			return false;
		}

		delete mPassenger[i];

		for (; i < mPassengerCount; i++)
		{
			mPassenger[i] = mPassenger[i + 1];
		}

		mPassengerCount--;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPassengerCount)
		{
			return NULL;
		}
		return mPassenger[i];
	}


	void Vehicle::operator=(const Vehicle& other)
	{

		if (this == &other)
		{
			return;
		}
		for (unsigned int i = 0; i < mPassengerCount; i++)
		{
			delete mPassenger[i];
		}

		delete[] mPassenger;

		mMaxPassengerCount = other.mMaxPassengerCount;
		mPassengerCount = other.mPassengerCount;
		mPassenger = new const Person * [mMaxPassengerCount];

		if (mPassengerCount <= mMaxPassengerCount)
		{
			for (unsigned int i = 0; i < mPassengerCount; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}
		}
	}
}