#include<stdio.h>

#define FILENAME 'final'
#define SIZE 300000000
typedef int URL;
struct NODE{
    URL url;//key of url
    int hotValue;//hot value
    struct NODE *next;
};
URL getUrl(void);//get random number
int getHash(URL url);//hash url to int
int insert(struct NODE* table, int hashValue, struct NODE* node);
void insertTopTen( struct NODE* topTen, struct NODE* node );//copy node
int getMin( struct NODE* topTen );
// to top 10 and set the correct order
//with min-heap

int main(void)
{
    //nenerate 300,000,000 url and put it to hash map
    int i = 0;
    URL url;
    int hashValue;
    struct NODE* node;
    struct NODE* table;
    table = (struct NODE*) malloc( SIZE*sizeof(struct NODE) );
    //init table
    i = 0;
    for(; i<SIZE; i++)
    {
	table[i].url = -1;//if !=-1 then existed hotValue++
	table[i].hotValue = 0;
	table[i].next = NULL;
    }
    i = 0;
    for(; i<SIZE; i++)
    {
	url = rand();
	//get hash value
	hashValue = getHash( url );
	//create new node and set value
	node = ( struct NODE * ) malloc( sizeof( struct NODE ) );
	node->url = url;
	node->hotValue = hashValue;
	//put it to hash table
	insert( table, hashValue,  node );
    }
    //create top 10 array 
    struct NODE* topTen = (struct NODE*) malloc( 10*sizeof(struct NODE) );
    //get top 10
    i = 0;
    for(; i<SIZE; i++)
    {
	node =&table[i];
	while(node != NULL)
	{
	//travelsal the link pointed by table+i
	    if( node->hotValue>getMin( topTen ) )
	    {//if hotValue > min-heap 
	        //increase min-heap to hotvalue and maximum-heap
		insertTopTen( topTen, node );
	    }
	    node = node->next;
	}
    }
    //free table
    free( table );
    //free topTen
    free( topTen );
    return 0;
}

URL getUrl(void)//get random numbe
{
    int url = rand();
    return url;
}
int getHash(URL url)//hash url to int
{
    int hashValue;
    hashValue = url%SIZE;
    return hashValue;
}
int insert(struct NODE* table, int hashValue, struct NODE* node)//insert node into 
//tbale
{
    struct NODE * p, * q;
    p = table[hashValue];
    if( p->url==-1 )
    {
	*p = *node;
    }
    else
    {
	while( p->next!=NULL )	
	    p = p->next;
	p->next = node;
    }
    return 1;
}
void initTopTen( struct NODE* topTen )
{
    return 0;
}
void insertTopTen( struct NODE* topTen, struct NODE* node )//copy node
{
    return ;
}

int getMin( struct NODE* topTen )
{
    return 0;
}
