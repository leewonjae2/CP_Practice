#include "DeusExMachina.h"

namespace assignment2
{
	bool DeusExMachina::mExist = false;
	DeusExMachina* DeusExMachina::mInstance = NULL;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mExist == false)
		{
			mInstance = new DeusExMachina();
			mInstance->mVehicleCount = 0;
			mExist = true;

			return mInstance;
		}
		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mVehicleCount; i++)
		{
			mVehicle[i]->Travel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{

		if (mVehicleCount < 10)
		{
			mVehicle[mVehicleCount] = vehicle;
			mVehicleCount++;
			return true;
		}
		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{

		if (mVehicleCount == 0)
		{
			return false;
		}

		if (i < mVehicleCount)
		{
			delete mVehicle[i];
			for (unsigned int j = i; j < mVehicleCount - 1; j++)
			{
				mVehicle[j] = mVehicle[j + 1];
			}
			mVehicleCount--;
			return true;
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return NULL;
		}

		if (mVehicle[0]->GetDistance() == 0)
		{
			return mVehicle[0];
		}
		unsigned int maxDistance = 0;
		unsigned int index = 0;
		for (unsigned int i = 0; i < mVehicleCount; i++)
		{
			if (maxDistance < mVehicle[i]->GetDistance())
			{
				maxDistance = mVehicle[i]->GetDistance();
				index = i;
			}
		}

		return mVehicle[index];
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i)
	{
		return mVehicle[i];
	}

}