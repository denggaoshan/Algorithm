#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		printf("%d\n", n ^ (n & (n - 1)));
	}
	return 0;
}