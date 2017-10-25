#include "dynamicProgramming.h"
#include "bitOperation.h"
#include "LinkedList.h"
#include "stackQueue.h"



int main()
{
	std::cout << "cpp Test" << std::endl;

	std::vector<int> v0 = { 0, 2, 3, 7 };
	auto list0 = ConstructList(v0);
	std::vector<int> v1 = { 1, 3, 5, 7, 9 };
	auto list1 = ConstructList(v1);
	PrintList(CombineListSorted(list0, list1));

	std::vector<int> v = { 4, 3, 5, 4, 3, 3, 6, 7, 12, 0 };
	PrintMaxValueInWindow(v, 3);

	float a = 1.12f, b = 10.21f;
	swapNumber((int&)a, (int&)b);

	{
		std::string s0("1A2C3D4B5609");
		std::string s1("B1D23CA45B6A0AC9");
		auto i = s0.length();
		auto s = GetLongestCommon(s0, s1);
		std::cout << "Longest common: " << s.s << std::endl;
	}

	{
		std::string s0("1AB2345CD");
		std::string s1("12345EF");
		auto ret = GetLongestConsecutiveNode(s0, s1);
		std::cout << "Longest consecutive common: " << ret.s << std::endl;
	}
}