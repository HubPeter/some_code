#include<stdio.h>

int func(int);
int main(void)
{
    int n;
    while(1)
    {
	int source;
	scanf("%d", &n);
	source = func(n);
	if (source == 0)
	    printf("Not found.\n");
	else
	{
	    printf("Entered:%d source:%d\n", n, source);
	}
    }
}
int func(int n)
{
    int i = 0;
    for( ; i<=n; i++ )
    {
	int sum = 0;
	int mask = 10;
	int j = i;
	for( ; j>0 ; )
	{
	    int r = j%mask;
	    sum += r;
	    j -= r;
	    j /= mask;
	}
	sum += i;
	if( sum == n )
	    return i;
    }
}
