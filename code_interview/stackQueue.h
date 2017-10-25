#pragma once
#include <vector>
#include <deque>
#include <iostream>

void PrintMaxValueInWindow(std::vector<int> v, int windowSize)
{
	std::deque<int*> deque;
	auto ptr = &v[0];
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		auto cur = &*it;

		while (cur - ptr > windowSize - 1)
			++ptr;
		while (!deque.empty() && deque.front() < ptr)
			deque.pop_front();

		while (!deque.empty())
		{
			if (*deque.back() > *it)
			{
				deque.push_back(cur);
				break;
			}
			else
			{
				deque.pop_back();
			}
		}
		if (deque.empty())
			deque.push_back(cur);

		if (cur - ptr == windowSize - 1)
			std::cout << *deque.front() << ", ";

	}

	std::cout << std::endl;
}