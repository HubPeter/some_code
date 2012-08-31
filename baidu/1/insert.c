#include<stdio.h>


#define SIZE 10
int * insert( int [], const int );
void show( int * );
int main(void)
{
    int arr[SIZE] = {12, -9, 2, 30, -98, 20, -22, -23, 332, 10};
    int *p = NULL;
    show( arr );
    printf("12	2	30	20	332	10\n");
    printf("-9	-98	-22	-23\n");
    insert( arr, SIZE);
    show( arr );
    return 0;
}
int * insert( int p[], const int n)
{
    int i = -1;//<0
    int j = 0;//>=0
    int temp;
    for(; j<n; j++)
    {
	if( p[j]<0 )
	{
	    temp = p[j];
	    int k = j;
	    for(; k-1>i; k--)
	    {
		p[k] = p[k-1];
	    }
	    p[++i] = temp;
	}
    }
    
    return p;
}
void show( int * arr )
{
    int i = 0;
    while( i++<SIZE )
    {
    	printf("%d	", *arr);
	arr++;
    }
    printf("\n");
}
