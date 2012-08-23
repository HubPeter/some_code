#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0
#define SIZE 5000000
#define SIZEA 500
#define MASK 10000

typedef int hash;

void gethash(int*, int[]);
int getrand(void);
int gethashone(int);
int main(void)
{
    //init B A
    int *B;
    B = (int *)malloc( SIZE*sizeof(int) );
    int A[SIZEA];
    int *hasht;
    hasht = (int *)malloc( MASK*sizeof(int) );
    int i = 0;
    srand(time(NULL));
    for(; i<SIZE; i++)
    {
	B[i] =getrand();
    }
    i = 0;
    for(; i<MASK; i++ )
    {
	hasht[i] = false;
    }
    i = 0;
    for(; i<SIZEA; i++)
    {
	A[i] = getrand();
    }
    //search
    gethash( hasht, A );
    i = 0;
    for(; i<SIZE; i++)
    {
	if( hasht[ gethashone( B[i] ) ] == 1 )
	    hasht[ gethashone( B[i] ) ] ++;
    }
    i = 0;
    for(; i<MASK; i++)
    {
	if(hasht[i]>1)
	    printf("%d ", i);
    }
    printf("\n");
    free( B );
    free( hasht );
    return 0;
}
int getrand(void)
{
    return rand()%MASK;
}
void gethash(int *hasht, int *A)
{
    
    int i = 0;
    for(; i<SIZEA; i++)
    {
	hasht[ gethashone(A[i]) ] = true;
    }
    return ;
}
int gethashone(int n )
{
    return n;
}
