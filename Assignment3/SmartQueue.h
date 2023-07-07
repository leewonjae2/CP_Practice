#pragma once
#include <queue>
#include <limits>

namespace assignment3
{
	template<typename T>

	class SmartQueue
	{
	public:
		SmartQueue();
		~SmartQueue();
		void Enqueue();
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
		unsigned int mSize;
		std::queue<T> mMax;
		std::queue<T> mMin;
		T mSum;
		double mPoweredDeviation;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSize(0)
		, mSum(0)
		, mPoweredDeviation(0)
	{
		mMax.push(std::numeric_limits<T>::min());
		mMin.push(std::numeric_limits<T>::max());
	}


	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue()
	{
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return T();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		return T();
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		return T();
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		return T();
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		return 0.0;
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		return T();
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		return 0.0;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return 0.0;
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return 0;
	}
}