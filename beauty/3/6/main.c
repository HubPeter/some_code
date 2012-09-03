#include<stdio.h>
#include<stdlib.h>

#define false 0
#define true 1
struct NODE{
    int data;
    struct NODE* next;
};
typedef struct NODE* LINK;

void MakeLink( LINK l1, LINK l2 );
_Bool isIntersect1( LINK l1, LINK l2 );
void InsertNode( LINK link, struct NODE* pNode );
void fFree( LINK link );
int main(void)
{
    LINK l1,l2;
    MakeLink( l1, l2 );
    _Bool bIsIntersect = isIntersect1( l1, l2 );
    printf("isTntersect:%d\n", bIsIntersect);
    return 0;
}
/*
*make two links with intersection
*/
void MakeLink( LINK l1, LINK l2 )
{
    int i = 0;
    for( ; i<10; i++ )
    {
	struct NODE* pNode = (struct NODE*)malloc( sizeof(struct NODE) );
	pNode->data = 0;
	pNode->next = NULL;
	InsertNode( l1, pNode );
    }
    for( ; i<100; i++ )
    {
	struct NODE* pNode = (struct NODE*)malloc( sizeof(struct NODE) );
	pNode->data = 0;
	pNode->next = NULL;
	InsertNode( l1, pNode );
    }
    for( ; i<5; i++ )
    {
	struct NODE* pNode = (struct NODE*)malloc( sizeof(struct NODE) );
	pNode->data = 0;
	pNode->next = NULL;
	InsertNode( l1, pNode );
	InsertNode( l2, pNode );
    }
    //free nodes
    fFree( l1 );
    fFree( l2 );
    return ;
}
/*
*is two links is intersected
*is so, return true:1
*else, return false:0
*/
_Bool isIntersect1( LINK l1, LINK l2 )
{
    struct NODE* p;
    p = l1;
    //to get last node
    while( p->next!=NULL )
    {
	p = p->next;
    }
    //link l2 to l1
    p->next = l2;
    //search l2 in l2
    struct NODE* q;
    q = l2;
    while( q!=NULL )
    {
	//if find l2's head when travelsal l2
	if( q==l2 )
	    return true;
	q = q->next;
    }
    //unlink l2 from l1
    p->next = NULL;
    return false;
}
/*insert pNode into link
 *no return value
**/
InsertNode( LINK link, struct NODE* pNode )
{
    struct NODE* p = link->next;
    link->next = pNode;
    pNode->next = p;
    return ;
}
/*
* free memory from link
*/
void fFree( LINK link )
{
    struct NODE* p;
    p = link;
    p->next = NULL;
    link = link->next;
    while( p!=NULL )
    {
	//free p
	free( p );
	//prepare pointer for next free operation
	p = link;
	p->next = NULL;
	link = link->next;
    }
    return NULL;
}
