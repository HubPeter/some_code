#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0
#define SIZE 1000000
#define MASK 10000000
int getrand(void);
int main(void)
{
    //init B A
    int B[SIZE];
    int A[500];
    _Bool r[500];
    int i = 0;
    srand(time(NULL));
    for(; i<SIZE; i++)
    {
	B[i] =getrand();
    }
    i = 0;
    for(; i<500; i++)
    {
	r[i] = false;
	A[i] = getrand();
    }
    //search
    i = 0;
    for(; i<500; i++)
    {
	int j = 0;
	for(; j<SIZE; j++)
	{
	    if( A[i]==B[j] )
		r[i] = true;
	}
    }
    //show resoule
    i = 0;
    for(; i<500; i++)
    {
	if( r[i]==true )
	    printf("%d	", i);
    }
    printf("\n");
    return 0;
}
int getrand(void)
{
    return rand()%MASK;
}
