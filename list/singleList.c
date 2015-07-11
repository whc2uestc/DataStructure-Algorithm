/* Include the create, insert, delete, search, free and some related algorithm of the list.
	author:whc2uestc
	date:2015.7.11
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 	the Node of the single list.
	include the element of data and next point.*/
typedef struct SingleListNode{
    int data;
    struct SingleListNode *next;
}ListNode;

/* alloc a new node.
   if success,return the node.
   else return NULL.	*/
ListNode* allocNode(int data){
    ListNode *pNode;
    pNode = (ListNode*)malloc(sizeof(ListNode));

    if(NULL != pNode){
        memset(pNode,0,sizeof(ListNode));
        pNode->data = data;
    }
    return pNode;
}
/* search a node whose element is the data in the list.
	if the element exist,return the node;
	else return NULL.*/
ListNode* findDataInSingleList(const ListNode *pListNode,int data){
    ListNode *pNode;
    if(NULL == pListNode)
        return NULL;
    if(data == pListNode->data)
        return (ListNode*)pListNode;
    pNode = pListNode->next;
    while(pNode){
        if(data == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return NULL;
}

/* insert a node into the end of list.
   if insert success,return true;
   else return false.
*/
bool insertNodeIntoSingleList(ListNode **pListNode,int data){
    ListNode *pNode,*ppListNode;
    if(NULL == pListNode)
        return false;
    pNode = createSingleListNode(data);
    if(NULL == pNode)
        return false;
    if(NULL == *pListNode)
        *pListNode = pNode;
    else{
        ppListNode = *pListNode;
        while(ppListNode->next)
            ppListNode = ppListNode->next;
        ppListNode->next = pNode;
    }
    return true;
}
/* delete a node from the list.
   if delete success,return true;
   else false. */
bool deleteFromSingleList(ListNode **pListNode,int data){
	if(NULL == pListNode || NULL == *pListNode)
		return false;
	ListNode *pNode = *pListNode->next;
	if(*pListNode->data == data){
		free(*pListNode)£»
		*pListNode = pNode;
		return true;
	}
	ListNode *pPre = *pListNode;
	while(pNode){
		if(pNode->data == data){
			pPre = pNode->next;
			free(pNode);
			return true;
		}
		pPre = pNode;
		pNode = pNode->next;
	}
	return false;
}

void printList(const ListNode *pListNode){
	while(pListNode){
		printf("%d ",pListNode->data);
		pListNode = pListNode->next;
	}
}


/* free the list*/
void freeSingleList(ListNode *pListNode){
	if(NULL == pListNode)
		return ;
	ListNode *pNode = NULL;
	while(pListNode){
		pNode = pListNode->next;
		free(pListNode);
		pListNode = pNode;
	}
}

/* find the middle position of the list.
	use the quick point and the slow quick.
	the pQuick do two step every time,the pSlow do one step every time.
	when the pQuick goto the end,the pSlow is the middle node.
*/
ListNode* findMidPositionOfList(const ListNode *pListNode){
	ListNode *pQuick = pListNode,*pSlow = pListNode:
	if(NULL == pListNode)
		return NULL;
	while(pQuick){
		pSlow = pSlow->next;
		pQuick = pQuick->next;
		if(NULL == pQuick)
			break;
		pQuick = pQuick->next;
	}
	return pSlow;
}

/* find the kth node which count backwards.*/
ListNode* findNodeCountBackwards(const ListNode *pListNode,int k){
	if(NULL == pListNode)
		return NULL;
	ListNode *pQuick = pListNode,*pSlow = pListNode:
	while(k--){
		if(NULL == pQuick)
			return NULL;
		pQuick = pQuick->next;
	}
	while(pQuick){
		pQuick = pQuick->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

/* judge whether a circle exist in the list.*/
bool judgeCircleInList(const ListNode *pListNode){
	if(NULL == pListNode)
		return false;
	ListNode *pQuick = pListNode,*pSlow = pListNode:
	while(pQuick){
		pQuick = pQuick->next;
		if(NULL == pQuick)
			return false;
		pQuick = pQuick->next;
		pSlow = pSlow->next;
		if(pQuick == pSlow)
			return true;
	}
}
/* judge whether a common node exist in the two lists.*/
bool judgeCommonNode(const ListNode *pList1,const ListNode *pList2){
	if(NULL == pList1 || NULL == pList2)
		return false;
	while(pList1->next)
		pList1 = pList1->next;
	while(pList2->next)
		pList2 = pList2->next;
	
	return pList1==pList2;
}

/* find the first common node in the two lists.*/
int countSizeOfList(const ListNode *pListNode){
	if(NULL == pListNode)
		return 0;
	int count = 0;
	while(pListNode){
		count ++;
		pListNode = pListNode->next;
	}
	return count;
}
ListNode* findFirstCommonNode(const ListNode *pList1,const ListNode *pList2){
	if(NULL == pList1 || NULL == pList2)
		return NULL;
	int size1 = countSizeOfList(pList1);
	int size2 = countSizeOfList(pList2);
	if(size1 > size2){
		int index = size1 - size2;
		while(index--)
			pList1 = pList1->next;
	}
	else if(size1 < size2){
		int index = size2 - size1;
		while(index--)
			pList2 = pList2->next;
	}
	while(pList1){
		if(pList1 == pList2)
			return pList1;
		pList1 = pList1->next;
		pList2 = pList2->next;
	}
}

/* reverse the list.
   return the first node of the reversed list.
*/
ListNode* reverseList(ListNode *pListNode){
	ListNode *pGuard = NULL,*pNode = pListNode;
	if(NULL == pListNode)
		return NULL;
	pGuard = pListNode->next;
	pListNode->next = NULL;
	pListNode = pGuard;
	while(pListNode->next){
		pGuard = pListNode->next;
		pListNode->next = pNode;
		pNode = pListNode;
	}
	return pListNode;
}
