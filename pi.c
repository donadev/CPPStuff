#include <cstdio>
using namespace std;

long double pow(int a)
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
		   (4 * pow(i) + 1 + 4 * i)/ 
		   pi(i+1, n);
}
int main()
{
	printf("%.50Lf", pi(0, 4110));
}
