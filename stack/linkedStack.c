#include <stdio.h>

typedef struct ListNode{
    int element;
    struct ListNode *next;
}ListNode;
typedef struct LinkedStack{
    ListNode *topNode;
    ListNode *downNode;
    int stackLength;
}LinkedStack;

/* get the top node from the stack.*/
int top(LinkedStack *pStack){
   return pStack->topNode->element; 
}

/* pop the top node from the stack.*/
void pop(LinkedStack **pStack){
    ListNode *pNode = (*pStack)->topNode->next;
    free(*pStack);
    *pStack = pNode;
}

ListNode* allocNode(int element){
    ListNode *pNode = (ListNode*)malloc(sizeof(ListNode));
    if(NULL != pNode){
        pNode->element = element;
        pNode->next = NULL;
    }
    return pNode;
}

/* push a node into the stack.*/
void push(LinkedStack **pStack,int element){
    ListNode *pNode = allocNode(element);
    pNode->next = (*pStack)->topNode;
    (*pStack)->topNode = pNode;
}

int size(const LinkedStack *pStack){
    return pStack->stackLength;
}
void print(const LinkedStack *pStack){
    while(pStack->topNode != pStack->downNode){}
        printf("%d ",pStack->topNode->element);
        pStack->topNode = pStack->topNode->next;
    }
    printf("%d\n",pStack->downNode->element);
}






