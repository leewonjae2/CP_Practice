#pragma once
#include <queue>
#include <stack>
#include <limits>

namespace assignment3
{
	template<typename T>

	class SmartQueue
	{
	public:
		SmartQueue();
		~SmartQueue();
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

		SmartQueue<T>& operator=(const SmartQueue<T>& other);
	private:
		std::queue<T> mQueue;
		T mSum;
		double mSum2;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSum2(0)
	{
	}


	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mSum += number;
		mSum2 += number * number;
		mQueue.push(number);
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T result = mQueue.front();
		mQueue.pop();
		mSum -= result;
		mSum2 -= result * result;

		return result;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		std::queue<T> temp;
		T max = std::numeric_limits<T>::lowest();
		while (mQueue.empty() != true)
		{
			temp.push(mQueue.front());
			if (max < mQueue.front())
			{
				max = mQueue.front();
			}
			mQueue.pop();
			
		}
		while (temp.empty() != true)
		{
			mQueue.push(temp.front());
			temp.pop();
		}

		return max;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		std::queue<T> temp;
		T min = std::numeric_limits<T>::max();

		while (mQueue.empty() != true)
		{
			temp.push(mQueue.front());
			if (min > mQueue.front())
			{
				min = mQueue.front();
			}
			mQueue.pop();

		}
		while (temp.empty() != true)
		{
			mQueue.push(temp.front());
			temp.pop();
		}

		return min;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		return static_cast<double>(mSum) / mQueue.size();
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		double result = (mSum2 / mQueue.size()) - (pow((static_cast<double>(mSum) / mQueue.size()), 2));
		return result;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}

	template<typename T>
	inline SmartQueue<T>& assignment3::SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		mQueue = other.mQueue;
		mSum = other.mSum;
		mSum2 = other.mSum2;
		// TODO: 여기에 return 문을 삽입합니다.
		return *this;
	}
}