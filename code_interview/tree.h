#pragma once
#include <iostream>
#include <stack>
#include <set>
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
