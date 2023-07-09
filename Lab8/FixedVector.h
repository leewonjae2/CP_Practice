#pragma once

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




}
