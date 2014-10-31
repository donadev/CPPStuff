#include <iostream>
using namespace std;
//base2 logarithm
int log(int n)
{
	int c = 0;
	while(n >>= 1)
		c++;
	return c;
}
//get the nth bit of a integer
int nth_bit(int source, int pos)
{
	while(pos--)
		source >>= 1;
	return source & 1;
}
//get the divisor for the next crc operation. It considers the result of the last xor, too.
int divisor(int firstPart, int length, int source, int &pos)
{
	int offset;
	while(log(firstPart) < length)
	{
		firstPart <<= 1;
		offset = nth_bit(source, pos);
		firstPart |= offset;
		pos++;
	}
	return firstPart;
}
//this function converts integers in their bit rapresentation
string bits(int n)
{
	string result;
	do
	{
		char x = (n & 1) + '0';
		result = x + result;
	}
	while(n >>=1);
	return result;
}
//this function converts strings in integers
int integer(string data)
{
	int rs = 0;
	string::iterator it = data.begin() ;
	for(; it < data.end(); it++)
	{
		rs <<= 1;
		rs |= (*it - '0');
	}
	return rs;
}
//that function evaluates crc from a payload and a poly
string crc(string data, string p)
{
	int n = 0;
	int a = 0;
	int poly = integer(p);
	int payload = integer(data);
	int f = log(poly);
	//padding
	payload <<= f; 
	int g = log(payload);
	while(n < g)
	{
		a = divisor(a, f, payload, n);
		a ^= poly;
	}
	return bits(a);
}

int main()
{
	//should output 110
	cout << crc("101010101101", "1011");
}