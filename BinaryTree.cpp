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

int main()
{
	TREE myTree =NULL;
}