#include<stdio.h>

typedef struct TreeNode  
{  
    char c;  
    struct TreeNode *leftchild;  
    struct TreeNode *rightchild;  
}TreeNode; 

int CompTree(TreeNode* tree1,TreeNode* tree2);
struct TreeNode* createTree( TreeNode * );
void showTree( TreeNode * );
int main(void)
{
    TreeNode *tree1, *tree2;
    tree1 = createTree( tree1 );
    tree2 = createTree( tree2 );
    _Bool equal;
    equal = CompTree( tree1, tree2 );   
    printf("equal = %d\n", equal );
    showTree( tree1 );
    showTree( tree2 );
    return 0;
}
int CompTree( TreeNode* tree1,TreeNode* tree2 )
{
    if( tree1==NULL && tree2==NULL )
	return 1;
    if( tree1!=NULL && tree2!=NULL )
    {
	if( tree1->c==tree2->c )
	    return ( CompTree( tree1->leftchild, tree2->leftchild ) &&
		CompTree( tree1->rightchild, tree2->rightchild ) ) ||
		( CompTree( tree1->leftchild, tree2->rightchild ) && 
		CompTree( tree1->rightchild, tree2->leftchild ) ) ;
	return 0;
    }
}
struct TreeNode* createTree( TreeNode * root )
{
    
    return root;
}
void showTree( TreeNode * tree  )
{
    return ;
}
