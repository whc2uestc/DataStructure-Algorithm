/* author:whc
 * date:2015.7.7
 * binarySearchTree
 * */
#include <stdio.h>

typedef struct binSrcTreeNode{
    int element;
    struct binSrcTreeNode *pLeft;
    struct binSrcTreeNode *pRight;
}BSTNode;

/* alloc a binarySearchTree node.
 * if alloc sucess,return the node;
 * else return NULL.*/
BSTNode* allocNode(int element){
    BATNode *pNode = (BSTNode*)malloc(sizeof(BSTNode));
    if(NULL != pNode){
        pNode->element = element;
        pNode->pLeft = NULL;
        pNode->pRight = NULL;
    }
    return pNode;
}

/* find a element in binarySearchTree.
 * if the element exist,return true,node return in pNode;
 * else return false,the pNode is the last node.*/
bool searchInBSTree(const BSTNode *pRoot,int element,BSTNode **pNode){
    if(NULL == pRoot)
        return false;
    *pNode = pRoot;
    if(pRoot->element == element){
        return true;
    }
    else if(pRoot->element > element)
        return searchInBSTree(pRoot->pLeft,element,pNode);
    else
        return searchInBSTree(pRoot->pRight,element,pNode);
}

/*insert a element into the binarySearchTree.
 * if insert success,return true;
 * else return false.*/
bool insertIntoBSTree(BSTNode **pRoot,int element){
    if(NULL == pRoot)
        return false;
    if(NULL == *pRoot){
        *pRoot = allocNode(element);
        return NULL==*pRoot?false:true;
    }
    BSTNode **pSrc = NULL;
    if(searchInBSTree(pRoot,element,pSrc))
        return false;
    BSTNode *pNode = allocNode(element);
    if(element < *pSrc->element)
        *pSrc->pLeft = pNode;
    else
        *pSrc->pRight = pNode;
    return true;
}


/* find a element in binarySearchTree.
 * if the element exist,return true,node return in pNode,it's parent return in pParent;
 * else return false,the pParent is the last node.*/
bool _searchBSTree(const BSTNode *pRoot,int element,BSTNode **pParent,BSTNode **pNode){
    *pParent = pRoot;
    if(pRoot->element > element){
        if(NULL == pRoot->pLeft)
			return false;
		if(pRoot->pLeft->element == element){
			pNode = pRoot->pLeft;
			return true;
		}
		return _searchBSTree(pRoot->pLeft,element,pNode);
	}
    else{
        if(NULL == pRoot->pRight)
			return false;
		if(pRoot->pRight->element == element){
			pNode = pRoot->pRight;
			return true;
		}
		return _searchBSTree(pRoot->pRight,element,pNode);
	}
}
bool searchBSTree(const BSTNode *pRoot,int element,BSTNode **pParent,BSTNode **pNode){
    if(NULL == pRoot)
        return false;
	if(pRoot->element == element){
		*pParent = NULL;
		*pNode = pRoot;
		return true;
	}
    return _searchBSTree(pRoot,element,pParent,pNode);
}

/* delete a node from binarySearchTree.
 * if the node exist,delete it and return true;
 * else return false.*/
bool deleteFromBSTree(BSTNode **pRoot,int element){
    if(NULL == pRoot || NULL == *pRoot)
        return false;
    BSTNode **pSrc = NULL;
	BSTNode **pParent = NULL;
	if(searchInBSTree(*pRoot,element,pParent,pSrc)){
		if(NULL == *pSrc->pLeft && NULL == *pSrc->pRight){
			free(*pSrc);
			*pSrc = NULL;
			return true;
		}
		else if(NULL == *pSrc->pLeft){
			if(*pSrc == *pParent->pLeft)
				*pParent->pLeft = *pSrc->pRight;
			else if(*pSrc == *pParent->pRight)
				*pParent->pRight = *pSrc->pRight;
			free(*pSrc);
			return true;
		}
		else if(NULL == *pSrc->pRight){
			if(*pSrc == *pParent->pLeft)
				*pParent->pLeft = *pSrc->pLeft;
			else if(*pSrc == *pParent->pRight)
				*pParent->pRight = *pSrc->pLeft;
			free(*pSrc);
			return true;
		}
		else{
			BSTNode *pNode = *pSrc;
			BSTNode *pChild = *pSrc->pLeft;
			while(pChild->pRight){
				pNode = pChild;
				pChild = pChild->pRight;
			}
			if(pNode == *pSrc) pNode->pLeft = pChild->pLeft;
			else pNode->pRight = pChild->pLeft;
			
			if(*pSrc == *pParent->pLeft) *pParent->pLeft = pChild;
			else *pParent->pRight = pChild;
			
			pChild->pLeft = *pSrc->pLeft;
			pChild->pRight = *pSrc->pRight;
			
			return true;
		}
	}
	
    return false;
}

/* preOrder to traverse the binarySearchTree.*/
void preOrderBinarySearchTree(const BSTNode *pRoot){
	if(NULL == pRoot)
		return ;
	printf("%d ",pRoot->element);
	preOrderBinarySearchTree(pRoot->pLeft);
	preOrderBinarySearchTree(pRoot->pRight);
}

/* inOrder to traverse the binarySearchTree.*/
void inOrderBinarySearchTree(const BSTNode *pRoot){
	if(NULL == pRoot)
		return ;
	inOrderBinarySearchTree(pRoot->pLeft);
	printf("%d ",pRoot->element);
	inOrderBinarySearchTree(pRoot->pRight);
}

/* posOrder to traverse the binarySearchTree.*/
void posOrderBinarySearchTree(const BSTNode *pRoot){
	if(NULL == pRoot)
		return ;
	posOrderBinarySearchTree(pRoot->pLeft);
	posOrderBinarySearchTree(pRoot->pRight);
	printf("%d ",pRoot->element);
}

/* free the memory of the binarySearchTree after uesd.*/
void freeBinarySearchTree(BSTNode *pRoot){
	if(NULL == pRoot)
		return ;
	freeBinarySearchTree(pRoot->pLeft);
	freeBinarySearchTree(pRoot->pRight);
	free(pRoot);
}


int main(){

}
