#include "dynamicProgramming.h"
#include "bitOperation.h"
#include "LinkedList.h"
#include "stackQueue.h"
#include "tree.h"
#include "utility.h"
#include "matrix.h"



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

	auto treeRoot = new treeNode<int>(1);
	auto rn2 = treeRoot->addLeft(2);
	auto rn3 = treeRoot->addRight(3);
	auto rn4 = rn2->addRight(4);
	rn2->addLeft(24);
	auto rn5 = rn3->addLeft(5);
	auto rn6 = rn3->addRight(6);
	rn6->addLeft(100);
	rn6->addRight(160);
	auto rn7 = rn4->addLeft(7);
	rn7->addLeft(78);
	rn7->addRight(87);
	auto rn8 = rn4->addRight(8);
	auto rn9 = rn5->addLeft(9);
	auto rn10 = rn5->addRight(10);
	rn10->addRight(120);
	auto rn11 = rn8->addRight(11);
	auto rn12 = rn9->addLeft(12);
	auto rn13 = rn11->addLeft(13);
	auto rn14 = rn11->addRight(14);
	auto rn15 = rn12->addLeft(15);
	auto rn16 = rn12->addRight(16);
	
	PrintTreeRecursive(treeRoot);
	std::cout << std::endl;
	PrintTreePreorder(treeRoot);
	PrintTreeNoRecur(treeRoot);

	PrintTreeBorder(treeRoot);

	std::vector<int> vv = { 0, 1, 2 };
	auto listRoot = ConstructList(vv);
	//PrintList(revertListWithStack(listRoot));
	PrintList(revertList(listRoot));


	std::vector<int> r0 = { 1, 2, 3, 4 };
	std::vector<int> r1 = { 5, 6, 7, 8 };
	std::vector<int> r2 = { 9, 10, 11, 12 };
	std::vector<int> r3 = { 13, 14, 15, 16 };

	matrix<int> mat(4, 4);
	mat.setRow(0, r0);
	mat.setRow(1, r1);
	mat.setRow(2, r2);
	mat.setRow(3, r3);
	mat.PrintMatrix();
	zigzagMatrixPrint(mat);
}