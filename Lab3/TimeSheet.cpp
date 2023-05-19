#include <cmath>

#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		:mSize(strlen(name) + 1)
		, mMaxEntries(maxEntries)
		, mIndex(0)
	{
		mName = new char[mSize];
		memcpy(mName, name, mSize);

		mTimeSheet = new int[mMaxEntries];
	}


	TimeSheet::TimeSheet(const TimeSheet& other)
		: mMaxEntries(other.mMaxEntries)
		, mSize(other.mSize)
		, mIndex(0)
	{
		mName = new char[mSize];
		memcpy(mName, other.mName, mSize);

		mTimeSheet = new int[mMaxEntries];
		memcpy(mTimeSheet, other.mTimeSheet, mMaxEntries);
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 10 && timeInHours >= 1 && mIndex < mMaxEntries) {
			mTimeSheet[mIndex] = timeInHours;
			mIndex++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < mIndex) {
			return mTimeSheet[index];
		}
		else return -1;
	}

	int TimeSheet::GetTotalTime() const
	{
		int result = 0;
		int index = 0;

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
		int index = 0;

		while (index < mIndex)
		{
			result += mTimeSheet[index];
			index++;
		}

		return result / mIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		int index = 0;
		float* deviation = new float[mIndex];
		float result = 0;

		while (index < mIndex)
		{
			deviation[index] = mTimeSheet[index] - average;
			index++;
		}

		index = 0;

		while (index < mIndex)
		{
			result += powf(deviation[index], 2);
			index++;
		}
		result = result / mIndex;

		delete[] deviation;

		return sqrt(result);
	}

	const std::string& TimeSheet::GetName() const
	{
		std::string name = mName;
		return name;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mName;
		delete[] mTimeSheet;
	}
}