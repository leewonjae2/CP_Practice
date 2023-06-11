#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		if (v.size() > 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				sum += v[i];
			}
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int min = _I32_MAX;
		if (v.size() > 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				if (min > v[i])
				{
					min = v[i];
				}
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = _I32_MIN;
		if (v.size() > 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				if (max < v[i])
				{
					max = v[i];
				}
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		float sum = 0.0f;

		if (v.size() > 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				sum += static_cast<float>(v[i]);
			}
			return sum / v.size();
		}

		return 0.0f;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		std::vector<int>temp = v;
		SortDescending(temp);

		int* ptr1 = &temp[0];
		int* ptr2 = &temp[0];
		int ptr1Count = 0;
		int ptr2Count = 0;

		size_t index;

		for (index = 0; index < temp.size(); index++)
		{
			if (*ptr1 != temp[index])
			{
				break;
			}
			ptr1Count++;
		}

		for (; index < temp.size(); index++)
		{
			ptr2 = &temp[index];
			for (; index < temp.size(); index++)
			{
				if (*ptr2 != temp[index])
				{
					break;
				}
				ptr2Count++;
			}

			if (ptr2Count > ptr1Count)
			{
				ptr1 = ptr2;
				ptr1Count = ptr2Count;
			}
		}
		

		return *ptr1;
	}

	void SortDescending(std::vector<int>& v)
	{
		std::vector<int> sort;
		sort.reserve(v.size());

		unsigned int index = 0;

		if (v.size() > 0)
		{
			sort.push_back(v[0]);
		}

		if (v.size() > 1)
		{
			for (unsigned int i = 1; i < v.size(); i++)
			{
				for (index = 0; index < sort.size(); index++)
				{
					if (v[i] > sort[index])
					{
						break;
					}
				}

				if (index == sort.size())
				{
					sort.push_back(v[i]);
				}
				else
				{
					sort.push_back(v[i]);
					for (unsigned int j = 0; j < sort.size() - index - 1; j++)
					{
						sort.push_back(sort[index]);
						sort.erase(sort.begin() + index);
					}
				}



			}			
		}

		v = sort;

	}

}