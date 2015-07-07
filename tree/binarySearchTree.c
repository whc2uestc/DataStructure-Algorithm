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
        return searchBSTree(pRoot,element,pNode);
    else
        return searchBSTree(pRoot,element,pNode);
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

/* delete a node from binarySearchTree.
 * if the node exist,delete it and return true;
 * else return false.*/
bool deleteFromBSTree(BSTNode **pRoot,int element){
    if(NULL == pRoot || NULL == *pRoot)
        return false;
    BSTNode **pSrc = NULL;

    return false;
}


int main(){

}
