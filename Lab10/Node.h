#pragma once

#include <memory>

namespace lab10
{
	using namespace std;
	template<typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data)
		: Data(std::move(data))
		, Next(nullptr)
	{
	
	}

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
		: Data(std::move(data))
		, Previous(std::move(prev))
		, Next(nullptr)
	{
	}
}