#include <cmath>

#include "TimeSheet.h"

namespace lab3

	
{

	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mSize(strlen(name) + 1)
		, mMaxEntries(maxEntries)
		, mIndex(0)
		, mName(name)
	{
		

		mTimeSheet = new int[mMaxEntries];

		mDeviation = new float[mMaxEntries];
	}


	TimeSheet::TimeSheet(const TimeSheet& other)
		: mSize(other.mSize)
		, mMaxEntries(other.mMaxEntries)
		, mIndex(other.mIndex)
		, mName(other.GetName())
	{
		mTimeSheet = new int[other.mMaxEntries];
		memcpy(mTimeSheet, other.mTimeSheet, other.mMaxEntries * sizeof(int));

		mDeviation = new float[other.mMaxEntries];
		memcpy(mDeviation, other.mDeviation, other.mMaxEntries * sizeof(float));
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 10 && timeInHours >= 1 && mIndex < mMaxEntries)
		{
			mTimeSheet[mIndex] = timeInHours;
			mIndex++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < mIndex)
		{
			return mTimeSheet[index];
		}
		else
		{
			return -1;
		}
	}

	int TimeSheet::GetTotalTime() const
	{
		int result = 0;
		unsigned int index = 0;

		while (index < mIndex)
		{
			result += mTimeSheet[index];
			index++;
		}

		return result;
	}

	float TimeSheet::GetAverageTime() const
	{
		float result = 0;
		unsigned int index = 0;

		while (index < mIndex)
		{
			result += mTimeSheet[index];
			index++;
		}
		if (index == 0)
		{
			return 0.0f;
		}
		return result / mIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		unsigned int index = 0;
		float result = 0;

		while (index < mIndex)
		{
			mDeviation[index] = mTimeSheet[index] - average;
			index++;
		}

		index = 0;

		while (index < mIndex)
		{
			result += powf(mDeviation[index], 2);
			index++;
		}
		result = result / mIndex;

		if (index == 0)
		{
			return 0.0f;
		}

		return sqrt(result);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet TimeSheet::operator=(const TimeSheet& other)
	{
		TimeSheet result;
		result.mSize = other.mSize;
		mMaxEntries = other.mMaxEntries;
		mIndex = other.mIndex;
		mName = other.GetName();
		
		mTimeSheet = new int[other.mMaxEntries];
		memcpy(mTimeSheet, other.mTimeSheet, other.mMaxEntries * sizeof(int));

		mDeviation = new float[other.mMaxEntries];
		memcpy(mDeviation, other.mDeviation, other.mMaxEntries * sizeof(float));

		return result;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTimeSheet;
		delete[] mDeviation;
	}
}