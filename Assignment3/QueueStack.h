#pragma once
#include <queue>
#include <stack>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		~QueueStack();
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<std::stack<T>> mQueue;
		unsigned int mMaxStackSize;
		std::stack<T> mMin;
		std::stack<T> mMax;
		T mSum;
		unsigned int mSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0)
		, mSize(0)
	{
		mQueue.push(std::stack<T>());
		mMax.push(std::numeric_limits<T>::min());
		mMin.push(std::numeric_limits<T>::max());
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		while (mQueue.empty() == false)
		{
			mQueue.pop();
		}
	}

	template<typename T>
	void assignment3::QueueStack<T>::Enqueue(T number)
	{

		if (mQueue.back().size() == mMaxStackSize)
		{
			mQueue.push(std::stack<T>());
		}



		if (mMax.top() < number)
		{
			mMax.push(number);
		}

		if (mMin.top() > number)
		{
			mMin.push(number);
		}
		mSum += number;
		mSize++;

		if (mQueue.front().size() != mMaxStackSize)
		{
			mQueue.front().push(number);
			return;
		}

		mQueue.back().push(number);

	}
	
	template<typename T>
	T assignment3::QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T assignment3::QueueStack<T>::Dequeue()
	{
		T temp = mQueue.front().top();
		mQueue.front().pop();
		if (mQueue.front().empty() == true)
		{
			mQueue.pop();
		}
		mSum -= temp;
		mSize--;
		return temp;
	}

	template<typename T>
	T assignment3::QueueStack<T>::GetMax()
	{
		return mMax.top();
	}

	template<typename T>
	T assignment3::QueueStack<T>::GetMin()
	{
		return mMin.top();
	}

	template<typename T>
	double assignment3::QueueStack<T>::GetAverage()
	{
		return static_cast<double>(mSum) / mSize;
	}

	template<typename T>
	T assignment3::QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	unsigned int assignment3::QueueStack<T>::GetCount()
	{
		return mSize;
	}


	template<typename T>
	unsigned int assignment3::QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}
}