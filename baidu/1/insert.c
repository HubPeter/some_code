#include<stdio.h>


#define SIZE 10
void insert( int [], const int );
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
void insert(int*A ,int size)//copy from the answer from url in readme
{ 
    int minus=-1,plus=-1;
    int tmp=0;
    int i = 0;
    for(;i<size;i++)//travelsal the int array
    {
        if(minus==-1)
        {
            if(A[i]<0&& plus>=0)
            {
                minus=i;
            }
            if(A[i]>0&& plus<0)
            {
                plus=i;
            }
        }

        if(minus>=0&& plus>=0)
        {
            tmp=A[plus];
            A[plus++] = A[minus];
	    int k = minus;
            for (; k> plus; k--) 
            {
                 A[k] = A[k -1];
            }
            A[plus]=tmp;
            minus=-1;
        }
    }
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
