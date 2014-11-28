//swap two integers with XOR power
inline void swap(int &a, int &b)
{
	a ^= (b ^= (a ^= b));
}
//perform base2 logarithm with right-shift power
inline int log2(int a)
{
	int c = 0;
	while (a >>= 1) c++; 
	return c;
}
//get number of 1 bits in a number with both AND and right shift power
inline int num1(int a)
{
	int c = 0;
	do c += a & 1; while(a >>= 1);
	return c;
}
//raise 2 to the parameter with left-shift power
inline int pow2(int b)
{
	return 1 << b;
}
//returns the opposite of the number (2 and 1 complement)
inline int opposite(int b)
{
	return ~b + 1;
}
//return the value of the MSB of the number in input (log2)
inline int MSB(int a)
{
	return log2(a);
}
//sum of two numbers with carry bit
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
//difference of two numbers (sum from a and opposite of b)
inline int diff(int a, int b)
{
	return sum(a, opposite(b));
}
//product of two numbers
inline int prod(int x, int y)
{
	int s = 0;
	int i;
	do
	{
		i = MSB(y);
		s += x << i;
	} while(y ^= (1 << i));
	return s;
}
//division of two numbers, can be otptimized a lot
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
//absolute value of a number, with the power of complements
inline int abs(int i)
{
	return i < 0 ? opposite(i) : i;
}
	/*
	 *	Welcome!
	 *  -----  TODOs ------ 
	 *	optimize divix(int, int)
	 *  mcd function
	 *  mcm function
	 */
