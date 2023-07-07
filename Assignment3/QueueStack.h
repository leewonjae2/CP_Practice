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
		void Enqueue();
		T Peek();
	private:
		std::queue<std::stack<T>*> mQueue;
	};

}