#pragma once
#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;
		~TimeSheet();

	private:
		char* mName;
		unsigned int mSize;
		unsigned int mMaxEntries;
		unsigned int mMaxEntries;
		int* mTimeSheet;
		unsigned int mIndex;
		// 필요에 따라 private 변수와 메서드를 추가하세요.
	};
}