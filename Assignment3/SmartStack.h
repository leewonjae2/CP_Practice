#pragma once
#include <stack>
#include <limits>


namespace assignment3
{
	template<typename T>

	class SmartStack
	{
	public:
		SmartStack();
		~SmartStack();
		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

		SmartStack<T>& operator=(const SmartStack<T>& other);

	private:
		std::stack<T> mStack;
		std::stack<T> mMax;
		std::stack<T> mMin;
		T mSum;
		double mSum2;

	};


	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0)
		, mSum2(0)
	{
		mMax.push(std::numeric_limits<T>::min());
		mMin.push(std::numeric_limits<T>::max());
	}


	template<typename T>
	SmartStack<T>::~SmartStack()
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
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
		mStack.push(number);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{

		T result = mStack.top();
		if (result == mMin.top())
		{
			mMin.pop();
		}
		if (result == mMax.top())
		{
			mMax.pop();
		}
		mStack.pop();
		mSum -= result;
		mSum2 -= result * result;

		return result;

	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mMax.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMin.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		return static_cast<double>(mSum) / mStack.size();
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{

		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		return (mSum2 / mStack.size()) - (pow((mSum / mStack.size()), 2));
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		mStack = other.mStack;
		mMax = other.mMax;
		mMin = other.mMin;
	}
}