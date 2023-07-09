#pragma once
#include <stdint.h>


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
		uint32_t mVector[(N / 32) + 1];
	};


	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mVector()
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
			mVector[mSize / 32] = mVector[mSize / 32] + (1 << (mSize - (32 * (mSize / 32))));
			mSize++;
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
				if (mVector[i / 32] & (1 << i - (32 * (i / 32))))
				{
					break;
				}
			}
			i++;
			if (i < mSize - 1)
			{
				mVector[i / 32] = (((mVector[i / 32] >> (i - (32 * (i / 32)))) << (i - (32 * (i / 32)) - 1)) | (mVector[i / 32] & ((1 << ((i - (32 * (i / 32))) + 1)) - 1)));
				mSize--;
				return true;
			}
		}
		else
		{
			size_t i;
			for (i = 0; i < mSize - 1; i++)
			{
				if (~(mVector[i / 32]) & (1 << (i - (32 * (i / 32)))))
				{
					break;
				}
			}
			i++;
			if (i < mSize)
			{
				mVector[i / 32] = ((mVector[i / 32] >> i) << (i - 1)) | (mVector[mSize / 32] & ((1 << (i)) - 1));
				for (i = i / 32; i < mSize / 32; i++)
				{
					if (mVector[i + 1] & 1)
					{
						mVector[i] += (1 << 31);
						mVector[i + 1] = (mVector[i + 1] << 1);
					}
				}
				mSize--;
				return true;
			}
		}
		return false;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return (mVector[index / 32] & (1 << (index - (32 * (index / 32)))));
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return (mVector[index / 32] & (1 << (index - (32 * (index / 32)))));
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool t)
	{
		if (t)
		{
			size_t i;
			for (i = 0; i < mSize; i++)
			{
				if (mVector[i / 32] & (1 << i - (32 * (i / 32))))
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
				if (~(mVector[i / 32]) & (1 << i - (32 * (i / 32))))
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