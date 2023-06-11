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
		const Person** temp = other.mPassenger;
		unsigned int nameSize;
		char* tempName;

		mPassenger = new const Person * [mMaxPassengerCount];

		if (mPassengerCount > 0 && mPassengerCount <= mMaxPassengerCount)
		{
			for (unsigned int i = 0; i < mPassengerCount; i++)
			{
				nameSize = temp[i]->GetName().length();
				tempName = new char[nameSize + 1];

				for (unsigned int j = 0; j <= nameSize; j++)
				{
					tempName[j] = temp[i]->GetName()[j];
				}
				mPassenger[i] = new Person(tempName, temp[i]->GetWeight());
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
		unsigned int tempPassengerCount = mPassengerCount;
		mMaxPassengerCount = other.mMaxPassengerCount;
		mPassengerCount = other.mPassengerCount;

		const Person** temp = other.mPassenger;
		const Person** temp1 = mPassenger;
		unsigned int nameSize;


		mPassenger = new const Person * [mMaxPassengerCount];

		if (mPassengerCount > 0 && mPassengerCount <= mMaxPassengerCount)
		{
			for (unsigned int i = 0; i < mPassengerCount; i++)
			{
				nameSize = temp[i]->GetName().length();
				char* tempName = new char[nameSize + 1];

				for (unsigned int j = 0; j <= nameSize; j++)
				{
					tempName[j] = temp[i]->GetName()[j];
				}
				mPassenger[i] = new Person(tempName, temp[i]->GetWeight());
			}
		}
		for (unsigned int i = 0; i < tempPassengerCount; i++)
		{
			delete temp1[i];
		}
		delete[] temp1;
	}
}