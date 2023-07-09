#pragma once
#include <stdint.h>
#include "FixedVector.h"


namespace lab8
{
	template<size_t N>

	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector();
		bool Add(const bool t);
		bool Remove(const bool t);
		const bool Get(unsigned int index);
		const bool operator[](unsigned int index);
		int GetIndex(bool t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		size_t mSize;
		uint32_t mVector;
	};


	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mVector(0)
	{
	}

	template<size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool t)
	{
		if (mSize >= N)
		{
			return false;
		}
		if (t == true)
		{
			mVector += 1 << mSize++;
		}
		else
		{
			mSize++;
		}
		return true;
	}
	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool t)
	{
		if (t)
		{
			size_t i;
			for (i = 0; i < mSize - 1; i++)
			{
				if (mVector & (1 << i))
				{
					break;
				}
			}
			i++;
			if (i < mSize)
			{
				mVector = (((mVector >> i) << (i - 1)) | (mVector & ((1 << (i + 1)) - 1)));
				mSize--;
				return true;
			}
		}
		else
		{
			size_t i;
			for (i = 0; i < mSize - 1; i++)
			{
				if (~(mVector) & (1 << i))
				{
					break;
				}
			}
			i++;
			if (i < mSize)
			{
				mVector = ((mVector >> i) << (i - 1)) | (mVector & ((1 << (i)) - 1));
				mSize--;
				return true;
			}
		}
		return false;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return (mVector & (1 << index));
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return (mVector & (1 << index));
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool t)
	{
		if (t)
		{
			size_t i;
			for (i = 0; i < mSize; i++)
			{
				if (mVector & (1 << i))
				{
					return i;
				}
			}
		}
		else
		{
			size_t i;
			for (i = 0; i < mSize; i++)
			{
				if (~(mVector) & (1 << i))
				{
					return i;
				}
			}
		}
		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}
	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

}