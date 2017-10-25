#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <assert.h>

struct CommonNode
{
	CommonNode()
		: s("")
		, s0_indeies(0)
		, s1_indeies(0)
	{}

	void swap()
	{
		auto temp = s1_indeies;
		s1_indeies = s0_indeies;
		s0_indeies = temp;
	}

	std::string s;
	std::vector<size_t> s0_indeies;
	std::vector<size_t> s1_indeies;
};
CommonNode GetCommonStringV(std::string s0, std::string s1, CommonNode* n)
{
	CommonNode ret;

	if (n)
	{
		assert(n->s0_indeies.size() == n->s1_indeies.size());
		char newChar = s0.back();
		if (n->s1_indeies.size() == 0)
		{
			auto index = s1.find_first_of(newChar);
			if (index == std::string::npos)
				return ret;
			else
			{
				ret.s += newChar;
				ret.s1_indeies.push_back(index);
				ret.s0_indeies.push_back(s0.length() - 1);
				return ret;
			}
		}
		else
		{
			if (n->s1_indeies.back() == s1.length() - 1)
			{
				ret = *n;
				return ret;
			}
			else
			{
				std::string sub = s1.substr(n->s1_indeies.back() + 1, s1.length() - n->s1_indeies.back());
				auto index = sub.find_first_of(newChar);
				if (index == std::string::npos)
				{
					ret = *n;
					return ret;
				}
				else
				{
					ret = *n;
					ret.s += newChar;
					ret.s1_indeies.push_back(index + n->s1_indeies.back() + 1);
					ret.s0_indeies.push_back(s0.length() - 1);
					return ret;
				}
			}
		}
	}
	else
	{
		assert(s0.length() == 1);
		auto index = s1.find_first_of(s0[0]);
		if (index == std::string::npos)
		{
			return ret;
		}
		else
		{
			ret.s = s0;
			ret.s1_indeies.push_back(index);
			ret.s0_indeies.push_back(0);
			return ret;
		}
	}
}
CommonNode GetCommonStringH(std::string s0, std::string s1, CommonNode* n)
{
	CommonNode ret;

	if (n)
	{
		assert(n->s0_indeies.size() == n->s1_indeies.size());
		char newChar = s1.back();
		if (n->s0_indeies.size() == 0)
		{
			auto index = s0.find_first_of(newChar);
			if (index == std::string::npos)
				return ret;
			else
			{
				ret.s += newChar;
				ret.s0_indeies.push_back(index);
				ret.s1_indeies.push_back(s1.length() - 1);
				return ret;
			}
		}
		else
		{
			if (n->s0_indeies.back() == s0.length() - 1)
			{
				ret = *n;
				return ret;
			}
			else
			{
				std::string sub = s0.substr(n->s0_indeies.back() + 1, s0.length() - n->s0_indeies.back());
				auto index = sub.find_first_of(newChar);
				if (index == std::string::npos)
				{
					ret = *n;
					return ret;
				}
				else
				{
					ret = *n;
					ret.s += newChar;

					ret.s0_indeies.push_back(index + n->s0_indeies.back() + 1);
					ret.s1_indeies.push_back(s1.length() - 1);

					return ret;
				}
			}
		}
	}
	else
	{
		assert(s1.length() == 1);
		auto index = s0.find_first_of(s1[0]);
		if (index == std::string::npos)
		{
			return ret;
		}
		else
		{
			ret.s = s1;
			ret.s0_indeies.push_back(index);
			ret.s1_indeies.push_back(0);
			return ret;
		}
	}
}
CommonNode GetLongestCommon(std::string s0, std::string s1)
{
	CommonNode ret;
	std::vector<std::vector<CommonNode>> M;
	M.push_back(std::vector<CommonNode>(0));
	for (auto i = 1U; i <= s0.length(); ++i)
	{
		M.push_back(std::vector<CommonNode>(s1.length() + 1));
		std::string s0_temp = s0.substr(0, i);
		std::cout << "s0: " << s0_temp << " : ";
		for (auto j = 1U; j <= s1.length(); ++j)
		{
			std::string s1_temp = s1.substr(0, j);

			auto n_h = GetCommonStringH(s0_temp, s1_temp, j == 1 ? nullptr : &M[i][j - 1]);
			auto n_v = GetCommonStringV(s0_temp, s1_temp, i == 1 ? nullptr : &M[i - 1][j]);
			auto n = n_h;
			if (n_v.s.length() > n_h.s.length())
			{
				n = n_v;
			}
			M[i][j] = n;

			std::cout << n.s << "  ";
		}
		std::cout << "\n";
	}

	ret = M[s0.length()][s1.length()];
	return ret;
}

struct CommonConsecutiveNode
{
	CommonConsecutiveNode()
		: s("")
		, length(0)
	{}

	std::string s;
	int length;
};
CommonConsecutiveNode GetLongestConsecutiveNode(std::string s0, std::string s1)
{
	CommonConsecutiveNode* maxNode = nullptr;
	std::vector<std::vector<CommonConsecutiveNode>> M;

	for (auto i = 0U; i < s0.length(); ++i)
	{
		char s0_char = s0[i];
		M.push_back(std::vector<CommonConsecutiveNode>(s1.length()));
		for (auto j = 0U; j < s1.length(); ++j)
		{
			char s1_char = s1[j];
			CommonConsecutiveNode* pre = nullptr;

			if (i > 0)
			{
				pre = &M[i - 1][j];
			}
			if (j > 0)
			{
				int temp = M[i][j - 1].length;
				if (!pre || temp > pre->length)
				{
					pre = &M[i][j - 1];
				}
			}
			if (i > 0 && j > 0)
			{
				int temp = M[i - 1][j - 1].length;
				if (!pre || temp > pre->length)
				{
					pre = &M[i - 1][j - 1];
				}
			}

			bool match = s0[i] == s1[j];
			CommonConsecutiveNode newNode;
			if (match)
			{
				if (pre)
				{
					newNode = *pre;
				}
				++newNode.length;
				newNode.s += s1[j];
			}
			M[i][j] = newNode;
			std::cout << newNode.length << ", ";

			if (!maxNode || newNode.length > maxNode->length)
				maxNode = &M[i][j];
		}

		std::cout << "\n";
	}

	return maxNode ? *maxNode : CommonConsecutiveNode();
}