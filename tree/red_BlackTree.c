#include <stdio.h>
#define RB_RED 0
#define RB_BLACK 1
typedef struct RedBlackTreeNode{
	int element;
	int color;
	struct RedBlackTreeNode *pLeft;
	struct RedBlackTreeNode *pRight;
	struct RedBlackTreeNode *pParent;
}RBNode;

RBNode* allocNode(int element){
	RBNode *pNode = (RBNode*)malloc(sizeof(RBNode));
	if(pNode){
		memset(pNode,0,sizeof(RBNode));
		pNode->element = element;
		pNode->color = RB_RED;
	}
	return pNode;
}

int rightRotate(){
	
}

int leftRotate(){
	
}



bool insertIntoRedBlackTree(RBNode **pRoot,int element){
	if(pRoot == NULL)
		return false;
	RBNode *pNode = allocNode(element);
	/* the inserted node is the root node.*/
	if(NULL == *pRoot){
		*pRoot = pNode;
		*pRoot->color = RB_BLACK;
		return true;
	}
	RBNode *pTemp = *pRoot;
	while(1){
		if(pTemp->element > element){
			if(NULL == pTemp->pLeft){
				pTemp->pLeft = pNode;
				pNode->pParent = pTemp;
				break;
			}
			pTemp = pTemp->pLeft;
		}
		else{
			if(NULL == pTemp->pRight){
				pTemp->pRight = pNode;
				pNode->pParent = pTemp;
				break;
			}
			pTemp = pTemp->pRight;
		}
	}
	/* the parent node of the inserted node is black.*/
	if(RB_BLACK == pTemp->color)
		return true;
	/* the parent node of the inserted node is red.*/
	while(pTemp->pParent){
		pTemp = pTemp->pParent;
		if(pTemp->pLeft == pTemp && NULL != pTemp->pRight){
			if(pTemp->pRight->color == RB_RED)
				pTemp->pLeft->color = pTemp->pRight->color = RB_BLACK;
			else{
				
			}
		}
		else if(NULL == pTemp->pRight){
			pTemp->pLeft->color = RB_BLACK;
		}
		else if(pTemp->pRight == pTemp && NULL != pTemp->pLeft){
			if(pTemp->pLeft->color == RB_RED)
				pTemp->pLeft->color = pTemp->pRight->color = RB_BLACK;
			else{
				
			}
		}
		else if(NULL == pTemp->pLeft){
			pTemp->pRight->color = RB_BLACK;
		}
	}
}

void deleteFromRedBlackTree(){
	
}