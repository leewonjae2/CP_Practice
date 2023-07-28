#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);

		Storage(Storage& other);

		Storage<T>& operator=(Storage& other);

		Storage(Storage&& other);

		Storage<T>& operator=(Storage&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private:
		std::unique_ptr<T[]> mArray;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
		, mArray(new T[length])
	{
		memset(mArray.get(), NULL, length * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
		, mArray(new T[length])
	{
		for (unsigned int i = 0; i < length; i++)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage& other)
		: mLength(other.mLength)
	{
		mArray = nullptr;
		mArray = std::make_unique<T[]>(mLength);

		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage& other)
	{

		mLength = other.mLength;
		if (this == &other)
		{
			std::unique_ptr<T[]> temp = move(other.mArray);
			mArray = std::make_unique<T[]>(mLength);
			for (unsigned int i = 0; i < mLength; i++)
			{
				mArray[i] = temp[i];
			}
		}
		else 
		{
			mArray = nullptr;
			mArray = std::make_unique<T[]>(mLength);

			for (unsigned int i = 0; i < mLength; i++)
			{
				mArray[i] = other.mArray[i];
			}
		}
		return *this;
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mArray(move(other.mArray))
		, mLength(other.mLength)
	{
		other.mArray = nullptr;
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& lab11::Storage<T>::operator=(Storage&& other)
	{
		if (this != &other)
		{
			mArray = nullptr;

			mArray = move(other.mArray);
			mLength = other.mLength;

			other.mArray = nullptr;
			other.mLength = 0;
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mLength)
		{
			mArray[index] = data;
			return true;
		}
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}