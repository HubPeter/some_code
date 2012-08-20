#include<stdio.h>
int main(void)
{
    int n=1;
    while(n!=0)
    {
    	printf("Enter a integer:(quit with 0)");
    	scanf("%d", &n);
	if(n<2)
        {
	    printf("Bigger then 1 please\n");
	    continue ;
	}
	int count = 0;
	while(n>1)
	{
	    if(n%2==0)
	    {
	        n = n/2;
	    }
	    else
		n = n-1 ;
	    count ++;
	}
	printf("Input:%d count:%d\n", n, count);
    }
    return 0;
}
