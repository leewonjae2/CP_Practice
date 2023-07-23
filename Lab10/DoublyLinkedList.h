#pragma once

#include <memory>

namespace lab10
{
	using namespace std;
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		unsigned int mLength;
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mLength == 0)
		{
			
			mHead = make_shared<Node<T>>(move(data));
			mTail = mHead;
			mLength++;
			
			return;
		}
		
		mTail->Next = make_shared<Node<T>>(move(data), mTail);
		mTail = mTail->Next;
		mLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		
		if (index > mLength)
		{
			mTail->Next = make_shared<Node<T>>(move(data));
			mTail = mTail->Next;
			mLength++;

			return;
		}
		if (index == 0)
		{
			shared_ptr<Node<T>> temp = make_shared<Node<T>>(move(data));
			temp->Next = mHead;
			mHead = temp;
			return;
		}

		shared_ptr<Node<T>> temp = mHead;
		for (unsigned int i = 0; i < index - 1; i++)
		{
			temp = temp->Next;
		}
		shared_ptr<Node<T>> temp2 = temp->Next;
		temp->Next = make_shared<Node<T>>(move(data),temp);
		temp->Next->Next = temp2;
		temp->Next->Next->Previous = temp->Next;
		mLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		shared_ptr<Node<T>> i = mHead;
		for (; i->Next != nullptr; i = i->Next)
		{
			if (*(i->Data) == data)
			{
				i->Previous.lock()->Next = i->Next;
				i->Next->Previous = i->Previous;
				mLength--;
				return true;
			}
			
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		shared_ptr<Node<T>> i = mHead;
		for (; i != nullptr; i = i->Next)
		{
			if (*(i->Data) == data)
			{
				return true;
			}

		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{

		std::shared_ptr<Node<T>> temp = mHead;

		if (index >= mLength)
		{
			return nullptr;
		}

		for (unsigned int i = 0; i < index; i++)
		{
			temp = temp->Next;
		}

		return temp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}