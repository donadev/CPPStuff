#include <iostream>
using namespace std;

inline void swap(int &a, int &b)
{
	a ^= (b ^= (a ^= b));
}
inline int log2(int a)
{
	int c = 0;
	while (a >>= 1) c++; 
	return c;
}
inline int num1(int a)
{
	int c = 0;
	do c += a & 1; while(a >>= 1);
	return c;
}
inline int pow2(int b)
{
	return 1 << b;
}
inline int opposite(int b)
{
	return ~b + 1;
}
inline int MB(int a)
{
	int i;
	do i = a & 1; while(a >>= 1);
	return i;
}
inline int MSB(int a)
{
	return log2(a);
}
inline int sum(int x, int y)
{
	int a, b;
	do
	{
		a = x & y;
		b = x ^ y;
		x = a << 1;
		y = b;
	} while(a);
	return y;
}
inline int diff(int a, int b)
{
	return sum(a, opposite(b));
}
inline int prod(int x, int y)
{
	int s = 0;
	int i;
	do
	{
		i = MSB(y);
		s += x << i;
	} while(y &= ~(1 << i));
	return s;
}
inline int divix(int x, int y)
{
	int i;
	while(x >= y)
	{
		x = diff(x, y);
		i++;
	}
	return i;
}
int main()
{
}
