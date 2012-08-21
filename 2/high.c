#include<stdio.h>

#define MASK 10
int main(void)
{
    int i = 0;
    int gen = 1;
    _Bool_Bs[10000];
    for(; i<10000; i++)
	s[i]=0;
    i = 1;
    for( ; i<10000 ; i++ )
    {
	int sum = 0;
	int j = i;
	int r = 0;
	while(j>0)
	{
	    r = j % MASK;
	    sum += r;
	    j -= r;
	    j /= MASK;
	}
	sum += i;
	if(sum < 10000)
	    s[sum] = 1;
    }
    i = 0;
    int count = 0;
    for(; i<10000; i++)
    {
	if(s[i]==1)
	{
	    printf("%d\n", i);
	    count ++;
	}
    }
    printf("count:%d\n", count);

}

