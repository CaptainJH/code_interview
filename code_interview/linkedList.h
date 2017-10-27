#pragma once
#include <iostream>
#include <stack>


struct listNode
{
	listNode(int value, listNode* nxt)
		: v(value)
		, p_next(nxt)
	{}

	int v;
	listNode* p_next;
};

int GetListLength(listNode* node)
{
	int ret = 0;
	auto ptr = node;
	while (ptr)
	{
		++ret;
		ptr = ptr->p_next;
	}

	return ret;
}

listNode* ConstructList(std::vector<int> v)
{
	listNode* ret = nullptr;
	listNode* prev = nullptr;
	for (auto i : v)
	{
		if (prev)
		{
			auto newNode = new listNode(i, nullptr);
			prev->p_next = newNode;
			prev = newNode;
		}
		else if (!ret)
		{
			ret = new listNode(i, nullptr);
			prev = ret;
		}
	}

	return ret;
}

void PrintList(listNode* p)
{
	while (p)
	{
		std::cout << p->v << " -> ";
		p = p->p_next;
	}

	std::cout << std::endl;
}

listNode* CombineListSorted(listNode* list0, listNode* list1)
{
	auto ptr0 = list0;
	auto ptr1 = list1;
	listNode* ptr = nullptr;
	listNode* ptr_other = nullptr;
	if (ptr0->v > ptr1->v)
	{
		ptr = ptr1;
		ptr_other = ptr0;
	}
	else
	{
		ptr = ptr0;
		ptr_other = ptr1;
	}

	auto result = ptr;
	while (ptr)
	{
		if (ptr_other)
		{
			auto ptr_other_next = ptr_other->p_next;
			auto ptr_next = ptr->p_next;
			if (!ptr_next)
			{
				ptr->p_next = ptr_other;
				break;
			}
			else if (ptr_other->v <= ptr_next->v)
			{
				auto temp = ptr_other;
				ptr_other = ptr_other_next;
				temp->p_next = ptr_next;
				ptr->p_next = temp;
			}
		}

		ptr = ptr->p_next;
	}

	return result;
}

bool isPalindrome(listNode* node)
{
	auto length = GetListLength(node);
	if (length < 2)
	{
		return true;
	}
	if (length == 2)
	{
		return node->v == node->p_next->v;
	}
	auto mid = length % 2 ? length / 2 : length / 2 - 1;

	listNode* ptr_prev = nullptr;
	auto ptr = node;
	listNode* ptr_next = ptr->p_next;
	// revert first half
	for (int i = 0; i < mid; ++i)
	{
		auto ptr_next_next = ptr_next->p_next;
		ptr_next->p_next = ptr;
		ptr->p_next = ptr_prev;

		ptr_prev = ptr;
		ptr = ptr_next;
		ptr_next = ptr_next_next;
	}

	auto start_left = length % 2 ? ptr_prev : ptr;
	auto start_right = ptr_next;

	bool ret = true;
	for (int i = 0; i < mid; ++i)
	{
		if (start_left->v != start_right->v)
		{
			ret = false;
			break;
		}

		start_left = start_left->p_next;
		start_right = start_right->p_next;
	}

	// revert back
	ptr_prev = ptr_next;
	ptr_next = ptr->p_next;
	for (int i = 0; i < mid; ++i)
	{
		auto ptr_next_next = ptr_next->p_next;
		ptr_next->p_next = ptr;
		ptr->p_next = ptr_prev;

		ptr_prev = ptr;
		ptr = ptr_next;
		ptr_next = ptr_next_next;
	}

	return ret;
}

listNode* revertListWithStack(listNode* node)
{
	std::stack<listNode*> stack;
	auto ptr = node;
	while (ptr->p_next)
	{
		stack.push(ptr);
		ptr = ptr->p_next;
	}

	auto ret = ptr;
	while (!stack.empty())
	{
		ptr->p_next = stack.top();
		stack.pop();
		ptr = ptr->p_next;
		ptr->p_next = nullptr;
	}

	return ret;
}

listNode* revertList(listNode* node)
{
	listNode* ptr_prev = nullptr;
	auto ptr = node;
	listNode* ptr_next = ptr->p_next;
	listNode* ret = nullptr;
	while (ptr)
	{
		auto ptr_next_next = ptr_next ? ptr_next->p_next : nullptr;
		ptr_next->p_next = ptr;
		ptr->p_next = ptr_prev;

		ptr_prev = ptr;
		ptr = ptr_next;
		ptr_next = ptr_next_next;

		if (!ptr_next)
		{
			ret = ptr;
			break;
		}
	}

	return ret;
}