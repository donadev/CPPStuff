#include <cstdio>
#include <cmath>
long double e(int n)
{
	long double val = 1 + (long double)1/n;
	return pow(val, n);
}
int main()
{
	long double n = 1000000000000000000;
	printf("%.50Lf", e(n));
}
