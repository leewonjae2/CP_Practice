#pragma once
#include <queue>


namespace lab9 
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(ObjectPool& other) = delete;
		ObjectPool operator=(ObjectPool& other) = delete;
		T* Get();
		void Return(T* other);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		std::queue<T*> mQueue;
		size_t mMaxSize;
	};

	template<typename T>
	inline lab9::ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxSize(maxPoolSize)
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			delete mQueue.front();
			mQueue.pop();
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mQueue.empty() == true)
		{
			return (new T());
		}

		T* temp = mQueue.front();
		mQueue.pop();
		return temp;
	}


	template<typename T>
	void ObjectPool<T>::Return(T* other)
	{
		if (mQueue.size() < mMaxSize)
		{
			mQueue.push(other);
			return;
		}
		delete other;
	}
	template<typename T> 
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mQueue.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxSize;
	}

}