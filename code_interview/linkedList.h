#pragma once
#include <iostream>


struct listNode
{
	listNode(int value, listNode* nxt)
		: v(value)
		, p_next(nxt)
	{}

	int v;
	listNode* p_next;
};

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