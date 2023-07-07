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
	private:
		std::queue<T> mQueue;
		std::stack<T> mMax;
		std::stack<T> mMin;
		T mSum;
		double mSum2;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSum2(0)
	{
		mMax.push(std::numeric_limits<T>::min());
		mMin.push(std::numeric_limits<T>::max());
	}


	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		if (mMax.top() < number)
		{
			mMax.push(number);
		}

		if (mMin.top() > number)
		{
			mMin.push(number);
		}

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
		if (result == mMin.top())
		{
			mMin.pop();
		}
		if (result == mMax.top())
		{
			mMax.pop();
		}
		mQueue.pop();
		mSum -= result;
		mSum2 -= result * result;

		return result;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		return mMax.top();
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		return mMin.top();
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
		return (mSum2 / mQueue.size()) - (pow((mSum / mQueue.size()), 2));
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
}