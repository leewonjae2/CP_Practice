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
		int mSize;
		int mMaxEntries;
		int* mTimeSheet;
		int mIndex;
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
	};
}