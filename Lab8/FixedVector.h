#pragma once
#include "FixedBoolVector.h"



namespace lab8
{
	template<class T, size_t N>

	class FixedVector
	{
	public:
		FixedVector();
		~FixedVector();
		bool Add(T& t);
		bool Remove(const T t);
		const T Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(T t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		size_t mSize;
		T* mVector[N];
	};

	template<class T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
		mVector[0];
	}

	template<class T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
	}



	template<class T, size_t N>
	bool FixedVector<T, N>::Add(T& t)
	{
		if (mSize < N)
		{
			mVector[mSize] = &t;
			mSize++;
			return true;
		}

		return false;
	}

	template<class T, size_t N>
	bool FixedVector<T, N>::Remove(const T t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (*mVector[i] == t)
			{
				for (; i < mSize - 1; i++)
				{
					mVector[i] = mVector[i + 1];
				}
				mSize--;
				return true;
			}
		}
		return false;
	}

	template<class T, size_t N>
	inline const T lab8::FixedVector<T, N>::Get(unsigned int index)
	{
		return *mVector[index];
	}

	template<class T, size_t N>
	inline T& lab8::FixedVector<T, N>::operator[](unsigned int index)
	{
		return *mVector[index];
		// TODO: 여기에 return 문을 삽입합니다.
	}

	template<class T, size_t N>
	inline int lab8::FixedVector<T, N>::GetIndex(T t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (*mVector[i] == t)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template<class T, size_t N>
	inline size_t lab8::FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template<class T, size_t N>
	inline size_t lab8::FixedVector<T, N>::GetCapacity()
	{
		return N;
	}




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
