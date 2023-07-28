#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		void ShiftNodes(std::shared_ptr<TreeNode<T>> target, std::shared_ptr<TreeNode<T>> child);

		std::shared_ptr<TreeNode<T>> Succesor(std::shared_ptr<TreeNode<T>> target);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		std::shared_ptr<TreeNode<T>> mHead;
	};


	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr)
		{
			mHead = std::make_shared<TreeNode<T>>(move(data));
			return;
		}

		std::shared_ptr<TreeNode<T>> search = mHead;
		std::shared_ptr<TreeNode<T>> parent;

		while (search != nullptr)
		{
			parent = search;
			if (*(search->Data) >= *(data))
			{
				search = search->Left;
			}
			else
			{
				search = search->Right;
			}
		}

		if (*data <= *(parent->Data))
		{
			parent->Left = std::make_shared<TreeNode<T>>(parent, move(data));
		}
		else
		{
			parent->Right = std::make_shared<TreeNode<T>>(parent, move(data));
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mHead;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> search = mHead;

		while (search != nullptr)
		{
			if (*(search->Data) == data)
			{
				return true;
			}
			if (*(search->Data) >= data)
			{
				search = search->Left;
			}
			else
			{
				search = search->Right;
			}
		}
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> search = mHead;
		std::shared_ptr<TreeNode<T>> parent;

		while (search != nullptr)
		{
			if (*(search->Data) == data)
			{
				if (search->Left == nullptr)
				{
					ShiftNodes(search, search->Right);
					return true;
				}
				else if (search->Right == nullptr)
				{
					ShiftNodes(search, search->Left);
					return true;
				}
				else
				{
					std::shared_ptr<TreeNode<T>> succesor = Succesor(search);
					std::shared_ptr<TreeNode<T>> scParent = succesor->Parent.lock();
					if (scParent != search)
					{
						ShiftNodes(succesor, succesor->Right);
						succesor->Right = search->Right;
						succesor->Right->Parent = succesor;
					}
					ShiftNodes(search, succesor);
					succesor->Left = search->Left;
					succesor->Left->Parent = succesor;
					return true;
				}
			}
			if (*(search->Data) >= data)
			{
				parent = search;
				search = search->Left;
			}
			else
			{
				parent = search;
				search = search->Right;
			}
		}
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		std::vector<T> v1;
		if (startNode == nullptr)
		{
			return v;
		}
		if (startNode->Left != nullptr)
		{
			v1 = TraverseInOrder(startNode->Left);
			v.insert(v.end(), v1.begin(), v1.end());
		}

		v.push_back(*(startNode->Data));

		if (startNode->Right != nullptr)
		{
			v1 = TraverseInOrder(startNode->Right);
			v.insert(v.end(), v1.begin(), v1.end());
		}

		return v;
	}

	template<typename T>
	inline void assignment4::BinarySearchTree<T>::ShiftNodes(std::shared_ptr<TreeNode<T>> target, std::shared_ptr<TreeNode<T>> child)
	{
		std::shared_ptr<TreeNode<T>> parent = target->Parent.lock();
		if (parent == nullptr)
		{
			mHead = child;
		}
		else if (target == parent->Left)
		{
			parent->Left = child;
		}
		else
		{
			parent->Right = child;
		}

		if (child != nullptr)
		{
			child->Parent = target->Parent;
		}
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>> assignment4::BinarySearchTree<T>::Succesor(std::shared_ptr<TreeNode<T>> target)
	{
		std::shared_ptr<TreeNode<T>> temp;
		if (target->Right != nullptr)
		{
			temp = target->Right;
			while (temp->Left != nullptr)
			{
				temp = temp->Left;
			}
			return temp;
		}
		temp = target->Parent.lock();
		while (temp != nullptr && target == temp->Right)
		{
			target = temp;
			temp = temp->Parent.lock();
		}
		return temp;
	}
}