#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

template<class T>
class matrix
{
	T* data;
	int rowCount;
	int columnCount;

public:
	matrix(int row, int column)
		: rowCount(row)
		, columnCount(column)
	{
		data = new T[row * column];
	}

	T at(int row, int column) const
	{
		assert(data);
		return data[row * stride() + column];
	}

	int row() const
	{
		return rowCount;
	}

	int column() const
	{
		return columnCount;
	}

	T& at(int row, int column)
	{
		assert(data);
		return data[row * stride() + column];
	}

	void setRow(int row, const std::vector<T>& r)
	{
		assert(columnCount == r.size());
		for (int i = 0; i < columnCount; ++i)
		{
			at(row, i) = r[i];
		}
	}

	void setColumn(int column, const std::vector<T>& c)
	{
		assert(rowCount == c.size());
		for (int i = 0; i < rowCount; ++i)
		{
			at(i, column) = c[i];
		}
	}

	int stride() const
	{
		return columnCount;
	}

	void PrintMatrix() const
	{
		for (int i = 0; i < rowCount; ++i)
		{
			for (int j = 0; j < columnCount; ++j)
			{
				std::cout << at(i, j) << ", ";
			}
			std::cout << std::endl;
		}
	}
};

template<class T>
void zigzagMatrixPrint(matrix<T> mat)
{
	int r = 0;
	int c = 0;

	enum walkPolice
	{
		zig,
		zag
	};
	walkPolice curPolice = zig;
	bool hitEdge = true;

	while (!(r == mat.row() - 1 && c == mat.column() - 1))
	{
		auto cur = mat.at(r, c);
		std::cout << cur << ", ";

		if (hitEdge)
		{
			hitEdge = false;
			if (r == 0)
			{
				if (c != mat.column() - 1)
				{
					++c;
				}
				else
				{
					++r;
				}

				curPolice = zig;
			}
			else if (c == 0)
			{
				if (r != mat.row() - 1)
				{
					++r;
				}
				else
				{
					++c;
				}

				curPolice = zag;
			}
			else if (r == mat.row() - 1)
			{
				++c;
				curPolice = zag;
			}
			else if (c == mat.column() - 1)
			{
				++r;
				curPolice = zig;
			}
		}
		else
		{
			if (curPolice == zig)
			{
				++r;
				--c;
			}
			else if (curPolice == zag)
			{
				--r;
				++c;
			}

			if (r == 0 || c == 0 || r == mat.row() - 1 || c == mat.column() - 1)
			{
				hitEdge = true;
			}
		}
	}

	std::cout << mat.at(r, c) << std::endl;
}