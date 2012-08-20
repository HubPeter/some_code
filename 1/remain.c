#include<stdio.h>

int func(unsigned int );
int main(void)
{
    int n ;
    while( 1 )
    {
	scanf( "%d", &n );
	printf("n:%d, count: %d\n", n, func( n ) );
    }
    return 0;
}
int func(unsigned int n)
{
    if( n==1 )
	return 0;
    if( n%2==0 )
    {
	return func(n/2) + 1;
    }
    if( n==3 )
	return 2;
    if( n&2 ) //2 or 3 is equal : the power of 1 must be 1
	return func( n+1 ) + 1;
    else
	return func( n-1 ) + 1;
}
