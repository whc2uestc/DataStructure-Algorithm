/* linked queue
 * author:whc
 * 2015.7.12*/

#include <stdio.h>

/* the struct of the linked queue.*/
typedef struct ListNode{
    int element;
    int *next;
}ListNode;
typedef struct LinkedQueue{
    int size;
    ListNode *front;
    ListNode *back;
}LinkedQueue;


/* alloc a node.*/
ListNode* allocNode(int element){
    ListNode *pNode = (ListNode*)malloc(sizeof(ListNode));
    if(pNode){
        pNode->element = elemnt;
        pNode->next = NULL;
    }
    return pNode;
}


/* alloc a queue.*/
LinkedQueue* allocLinkedQueue(){
    LinkedQueue *pQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if(pQueue){
        pQueue->size = 0;
        pQueue->front = NULL;
        pQueue->back = NULL;
    }
    return pQueue;
}

/* pop a node out of the queue.*/
bool pop(LinkedQueue *pQueue){
    if(NULL == pQueue)
       return false;
    LinkedQueue *pNode = pQueue->front;
    if(pQueue->front == pQueue->back)
        pQueue->back = NULL;
    pQueue->front = pQueue->front->next;
    free(pNode);
    pQueue->size --;
    return true;
}

/* push a node into the queue.*/
bool push(LinkedQueue *pQueue,int element){
    if(NULL == pQueue)
        return false;
    pQueue->size ++;
    if(NULL == pQueue->front){
        pQueue->front = pQueue->back = allocNode(element);
    }
    else
        pQueue->back = allocNode(element);
    return true;
}


/* get the element from the queue.*/
bool front(LinkedQueue *pQueue,int *element){
    if(pQueue->size){
        *element = pQueue->front->element;
        return true;
    }
    else
        return false;
}

