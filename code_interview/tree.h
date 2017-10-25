#pragma once
#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <list>
#include <assert.h>

template<class T>
struct treeNode
{
	treeNode()
		: left(nullptr)
		, right(nullptr)
	{}

	treeNode(T v)
		: value(v)
		, left(nullptr)
		, right(nullptr)
	{}

	T value;
	treeNode* left;
	treeNode* right;

	treeNode* addLeft(T v)
	{
		auto newNode = new treeNode;
		newNode->value = v;
		this->left = newNode;
		return newNode;
	}

	treeNode* addRight(T v)
	{
		auto newNode = new treeNode;
		newNode->value = v;
		this->right = newNode;
		return newNode;
	}
};

template<class T>
void PrintTreeRecursive(treeNode<T>* node)
{
	if (node->left)
	{
		PrintTreeRecursive(node->left);
	}
	if (node->right)
	{
		PrintTreeRecursive(node->right);
	}
	std::cout << node->value << ", ";
}

template<class T>
void PrintTreePreorder(treeNode<T>* node)
{
	std::stack<treeNode<T>*> stack;
	stack.push(node);

	while (!stack.empty())
	{
		auto n = stack.top();
		stack.pop();

		std::cout << n->value << ", ";
		if (n->right)
		{
			stack.push(n->right);
		}

		if (n->left)
		{
			stack.push(n->left);
		}
		
	}

	std::cout << std::endl;
}

template<class T>
void PrintTreeNoRecur(treeNode<T>* node)
{
	std::list<treeNode<T>*> nodeList;
	std::set<treeNode<T>*> nodeSet;
	nodeList.emplace_back(node);
	nodeSet.emplace(node);
	bool newNodeAdded = true;

	while (newNodeAdded)
	{
		std::list<treeNode<T>*> newNodeList;
		for (auto n : nodeList)
		{

			if (n->left && nodeSet.find(n->left) == nodeSet.end())
			{
				newNodeList.emplace_back(n->left);
				nodeSet.emplace(n->left);
			}
			if (n->right && nodeSet.find(n->right) == nodeSet.end())
			{
				newNodeList.emplace_back(n->right);
				nodeSet.emplace(n->right);
			}
			newNodeList.emplace_back(n);

		}

		newNodeAdded = newNodeList.size() != nodeList.size();
		nodeList = newNodeList;
	}

	for (auto n : nodeList)
	{
		std::cout << n->value << ", ";
	}

	std::cout << std::endl;
}

template<class T>
void PrintTreeBorder_PrintPreoder(treeNode<T>* node, std::vector<T>& bookKeeping, int currentLevel)
{
	if (bookKeeping.size() <= currentLevel || bookKeeping[currentLevel] == 0)
	{
		std::cout << node->value << ", ";
		bookKeeping.push_back(1);
	}
	else if (!node->left && !node->right)
	{
		std::cout << node->value << ", ";
	}

	if (node->left)
	{
		PrintTreeBorder_PrintPreoder(node->left, bookKeeping, currentLevel + 1);
	}

	if (node->right)
	{
		PrintTreeBorder_PrintPreoder(node->right, bookKeeping, currentLevel + 1);
	}
}
template<class T>
void PrintTreeBorder_PrintPreoder2(treeNode<T>* node, std::vector<T>& bookKeeping, int currentLevel, std::vector<T>& ret)
{
	if (bookKeeping.size() <= currentLevel || bookKeeping[currentLevel] == 0)
	{
		ret.push_back(node->value);
		bookKeeping.push_back(1);
	}
	else if (!node->left && !node->right)
	{
		ret.push_back(node->value);
	}

	if (node->left)
	{
		PrintTreeBorder_PrintPreoder2(node->left, bookKeeping, currentLevel + 1, ret);
	}

	if (node->right)
	{
		PrintTreeBorder_PrintPreoder2(node->right, bookKeeping, currentLevel + 1, ret);
	}
}
template<class T>
void revertTreeNode(treeNode<T>* node)
{
	auto temp = node->left;
	node->left = node->right;
	node->right = temp;

	if (node->left)
	{
		revertTreeNode(node->left);
	}

	if (node->right)
	{
		revertTreeNode(node->right);
	}
}
template<class T>
void PrintTreeBorder(treeNode<T>* node)
{
	std::cout << node->value << ", ";

	auto leftTree = node->left;
	auto rightTree = node->right;
	std::vector<T> bookKeeping;

	if (leftTree)
	{
		PrintTreeBorder_PrintPreoder(leftTree, bookKeeping, 0);
	}

	if (rightTree)
	{
		revertTreeNode(rightTree);
		bookKeeping.clear();
		std::vector<T> ret;
		PrintTreeBorder_PrintPreoder2(rightTree, bookKeeping, 0, ret);

		for (auto it = ret.rbegin(); it != ret.rend(); ++it)
		{
			std::cout << *it << ", ";
		}
	}

	std::cout << std::endl;
}
