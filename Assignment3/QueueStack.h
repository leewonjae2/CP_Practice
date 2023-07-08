#pragma once
#include <queue>
#include <stack>
#include "SmartStack.h"

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack<T>& operator=(QueueStack<T> other);
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack<T>& other);
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
		T mSum;
		unsigned int mSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0)
		, mSize(0)
	{
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
		, mSum(other.mSum)
		, mSize(other.mSize)
	{
		mQueue = other.mQueue;
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
	void QueueStack<T>::Enqueue(T number)
	{
		if (mQueue.size() == 0)
		{
			mQueue.push(std::stack<T>());
		}

		if (mQueue.back().size() == mMaxStackSize)
		{
			mQueue.push(std::stack<T>());
		}

		mSum += number;
		mSize++;


		mQueue.back().push(number);

	}
	
	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
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
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<std::stack<T>> temp;
		temp = mQueue;

		while (temp.empty() != true)
		{
			if (max < temp.front().top())
			{
				max = temp.front().top();
			}
			temp.front().pop();
			if (temp.front().empty() == true)
			{
				temp.pop();
			}
		}
		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<std::stack<T>> temp;
		temp = mQueue;

		while (temp.empty() != true)
		{
			if (min > temp.front().top())
			{
				min = temp.front().top();
			}
			temp.front().pop();
			if (temp.front().empty() == true)
			{
				temp.pop();
			}
		}
		return min;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(mSum) / mSize;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mSize;
	}


	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T> other)
	{
		std::queue<std::stack<T>> temp;
		mQueue = other.mQueue;
		mMaxStackSize = other.mMaxStackSize;
		mSum = other.mSum;
		mSize = other.mSize;

		return *this;
	}
}