#pragma once

template<class T>
void swapNumber(T& a, T& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}