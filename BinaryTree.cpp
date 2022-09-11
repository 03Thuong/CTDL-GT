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

// Duyet cay theo thu tu giua
void NLR(TNode* Root)
{
	if (Root !=NULL)
	{
		
		printf("%d ", Root->key);
		
		NLR(Root->pLeft);		
		NLR(Root->pRight);
	}
	
}

// Dem so node tren cay
int countNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		count ++;
		
		count+= countNode(Root->pLeft);		
		count+= countNode(Root->pRight);
	}
	return count;
}

// Dem so node la tren cay
int countLeafNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		if ((Root->pLeft==NULL)&&(Root->pRight==NULL))
			count++;
			
		count+= countNode(Root->pLeft);		
		count+= countNode(Root->pRight);	
	}
}

// dem so nut có dung 1 cay con
int CountNodeOneChild(TNode *Root)
{
    if (Root!=NULL)
    {
        int a = CountNodeOneChild(Root->pLeft);
        int b = CountNodeOneChild(Root->pRight);
        if ((Root->pLeft != NULL && Root->pRight == NULL) || (Root->pLeft == NULL && Root->pRight != NULL))
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

// dem so nut co dung 2 cay con
int CountNodeTwoChild(TNode *Root)
{
    if (Root!=NULL)
    {
        int a = CountNodeOneChild(Root->pLeft);
        int b = CountNodeOneChild(Root->pRight);
        if ((Root->pLeft != NULL) && (Root->pRight != NULL)) 
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

// Chieu cao cua cay
int getTreeHeight(TNode *Root)
{
	if (Root ==NULL)
		return 0;		
	    		
	int maxLeft = getTreeHeight(Root->pLeft);
			
	int maxRight = getTreeHeight(Root->pRight);	
	
	if (maxLeft> maxRight)
		return maxLeft+1;
	else
		return maxRight+1;
}

//So node co khoa nho hon X
int countNodeNHX(TNode *Root, int x)
{
	int count=0;
	if (Root == NULL) 
		return 0;
	if (Root->key < x) 
		count++;
	count+= countNodeNHX(Root->pLeft, x);		
	count+= countNodeNHX(Root->pRight, x);
	return count;
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
    printf("\n\n============================\n");
	printf("Duyet cay theo thu tu giua\n");
	NLR(myTree);
    printf("\n\nSo node tren cay la %d\n", countNode(myTree));
	printf("\n\nSo leafnode tren cay la %d", countLeafNode(myTree));
    printf("\n\nSo Node co dung 1 cay con la %d", CountNodeOneChild(myTree));
	printf("\n\nSo Node co dung 2 cay con la %d", CountNodeTwoChild(myTree));
	printf("\n\nChieu cao cua cay la %d", getTreeHeight(myTree));
	
	int x = 8;
	printf("\n\nSo node co khoa nho hon x la %d", countNodeNHX(myTree, x));
	return 0;

}