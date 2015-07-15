/* Include the create, insert, delete, search, free of the list.
	author:whc2uestc
	date:2015.7.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 	the Node of the double list.
	include the element of data and next point.*/
typedef struct DoubleListNode{
    int element;
    struct DoubleListNode *next;
	struct DoubleListNode *prev;
}ListNode;

/* alloc a new node of the double list.*/
ListNode* allocNode(int element){
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));
	if(NULL != pNode){
		pNode->element = element;
		pNode->prev = NULL;
		pNode->next = NULL;
	}
	return pNode;
}

/* find a node in the double list.*/
ListNode* findNodeInDoubleList(const ListNode *pList,int element){
	if(NULL == pList)
		return NULL;
	while(pList){
		if(element == pList->element)
			return pList;
		pList = pList->next;
	}
	return NULL;
}

/* insert a node into the double list.*/
bool insertNodeIntoDoubleList(ListNode **pList,int element){
	if(NULL == pList)
		return false;
	if(NULL == *pList){
		*pList = allocNode(element);
	}
	ListNode *pNode = *pList;
	while(pNode->next){
		pNode = pNode->next;
	}
	pNode->next = allocNode(element);
	pNode->next->prev = pNode;
	return true;
}

/* delete a node from the double list.*/
bool deleteNodeFromDoubleList(ListNode **pList,int element){
	if(NULL == pList || NULL == *pList)
		return false;
	ListNode *pNode ;
	if(element == *pList->element){
		pNode = *pList;
		*pList = *pList->next;
		*pList->prev = NULL;
		free(pNode);
		return true;
	}
	pNode = findNodeInDoubleList(*pList,element);
	if(NULL == pNode)
		return flase;
	ListNode *ppNode = pNode->prev;
	ppNode->next = pNode->next;
	if(NULL != pNode->next){
		pNode->next->prev = ppNode;
	}
	free(pNode);
	return true;
}

/* free the double list.*/
void freeDoubleList(ListNode **pList){
	if(NULL == pList || NULL == *pList)
		return NULL;
	ListNode *pNode = *pList;
	while(*pList->next){
		free(*pList);
		*pList = pNode;
		pNode = pNode->next;
	}
	free(*pList);
	*pList = NULL;
}




