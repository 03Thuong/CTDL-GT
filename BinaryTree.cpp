#include<conio.h>
#include<stdio.h>
//Khai bao cau truc cay nhi phan 
typedef struct TNode
{
	int key;
	TNode *pLeft, *pRight;	
}TNode;

typedef TNode* TREE;

//Tao node moi
TNode* createNewNode(int data)
{
	TNode* node = new TNode; 	
	node->key = data;	
	node->pLeft = NULL;
	node->pRight = NULL;		
	return node;
}
// Chen cay nhi phan
TNode* insert(TNode  *Root, int data)
{
	if(Root==NULL)
	{		
		
		printf("Add %d as root \n", data);
		TNode* node = createNewNode(data);	
		
		return node;
	}
	else
	{
		if (data < Root->key)
		{
				printf("Add %d as left child of %d\n", data, Root->key);
				Root->pLeft = insert(Root->pLeft, data);			
		}		
		else
		{
				printf("Add %d as right child of %d\n", data, Root->key);
				Root->pRight = insert(Root->pRight, data);							
		}
		
	}
	return Root;	
}

int main()
{
	TREE myTree =NULL;
	myTree = insert(myTree, 10);
	myTree =insert(myTree, 7);
	myTree =insert(myTree, 12);
	myTree =insert(myTree, 8);
	myTree =insert(myTree, 9);
	myTree =insert(myTree, 11);
	myTree =insert(myTree, 14);
	myTree =insert(myTree, 4);
	myTree =insert(myTree, 6);
	return 0;

}