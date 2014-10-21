#include <cstdio>
#include <ctime>
#include <stack>
#include <cmath>
using namespace std;

long double pw(int a)
{
	return a * a;
}
long double pi(int i, int n)
{
	if(i == n)
		return 6;
	int offset = 6;
	if(i == 0)
		offset = 3;
	return offset + 
		   (4 * pw(i) + 1 + 4 * i)/ 
		   pi(i+1, n);
}
long double pi(int d)
{
	long double offset = 6;
	stack<long double> stack;
	long double c, v;
	for(int i = d - 1; i >= 0; i--)
	{

		if(i == 0)
			offset = 3;
		if(stack.empty())
			v = 6;
		else
		{
			v = stack.top(); 
			stack.pop();
		}
		c = offset + (4 * pw(i) + 1 + 4 * i) / v;
		stack.push(c);
	}
	return stack.top();
}
long double fatt(long double n)
{
	long double x = 1;
	for(long i = 1; i <= n; i++)
	{
		x *= i;
	}
	return x;
}
long double pw(long double a, int b)
{
	long double i = 1;
	for(long n = 0; n < b; n++)
	{
		i *= a;
	}
	return i;
}
long double chud(int s)
{
	long double v = 0;
	for(int k = 0; k < s; k++)
	{
		v += (pow(-1, k) * fatt(6 * k) * (163 * 3344418 * k + 13591409))/
			 (fatt(3 * k) * pow(fatt(k), 3) * pow(640320, 3 * k + 1.5));
	}
	return 1/(12*v);
}
int main()
{
	int s = 1000;
	long a = clock();
	printf("%.50Lf\n", pi(0, s));
	printf("Continue fractional recursive function takes %ld clock cicles\n", clock() - a);
	a = clock();
	printf("\n%.50Lf\n", pi(s));
	printf("Continue fractional iterative function takes %ld clock cicles\n", clock() - a);
	a = clock();
	printf("\n%.50Lf\n", chud(s));
	printf("Chudnovsky function takes %ld clock cicles\n", clock() - a);
}
