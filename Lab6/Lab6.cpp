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
		if (v.size() == 0)
		{
			return 0;
		}

		std::vector<int> temp = v;
		SortDescending(temp);
		int numberCount = 1;
		
		if (v.size() > 1)
		{
			for (unsigned int i = 0; i < temp.size() - 1; i++)
			{
				if (temp[i] != temp[i + 1])
				{
					numberCount++;
				}
			}
		}

		if (numberCount > 1)
		{
			int** numbers = new int* [numberCount];
			
			for (unsigned int i = 0; i < numberCount; i++)
			{
				numbers[i] = new int[2];
			}


			int index = 0;

			numbers[0][0] = temp[0];
			numbers[0][1] = 1;
			index++;


			for (unsigned int i = 0; i < temp.size() - 1; i++)
			{
				if (temp[i] != temp[i + 1])
				{
					if (index < numberCount)
					{
						numbers[index][0] = temp[i + 1];
						numbers[index][1] = 1;
						index++;
					}
				}
				else
				{
					numbers[index - 1][1]++;
				}
			}

			int maxCount = 0;
			int countedNumber = 0;

			for (index = 0; index < numberCount; index++)
			{
				if (maxCount < numbers[index][1])
				{
					countedNumber = numbers[index][0];
					maxCount = numbers[index][1];
				}
			}

			for (unsigned int i = 0; i < numberCount; i++)
			{
				delete[] numbers[i];
			}
			delete[] numbers;

			return countedNumber;
		}



		return 0;
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