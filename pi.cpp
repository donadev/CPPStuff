#include <cstdio>
#include <ctime>
#include <stack>
#include <cmath>
#include <iostream>
using namespace std;

long double pw(int a)
{
	return a * a;
}
long double pi(int i, int n)
{
	if(i == n)
		return 6;
	return (long double)(i == 0 ? 3 : 6) + 
		   (4 * pw(i) + 1 + 4 * i)/ 
		   pi(i + 1, n);
}
long double pi(int d)
{
	long double back = 6;
	for(int i = d - 1; i >= 0; i--)
	{
		back = (long double)((i == 0) ? 3 : 6) + (4 * pw(i) + 1 + 4 * i) / back;
	}
	return back;
}
long double fatt(long double s)
{
	long double r = 1;
	for(long n = 1; n < s; n++)
		r *= n;
	return r;
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
	return 1 / 12 * v;
}
int main()
{
	int s = 11;
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