#include <stdio.h>
//定义一个m阶B树
#define m 4

typedef struct BTreeNode{
	int n;//n个关键字
	int *key;//key from 1 to m-1
	struct BTreeNode **child;//child from 0 to m-1
	struct BTreeNode *parent;
}BTNode;



//查找
bool searchInBTtree(BTNode *pRoot,int key,BTNode **pRes,int *index){
	if(NULL == pRoot){
		return false;
	}
	int i = 0;
	for(i=1; i<=pRoot->n; i++){
		*pRes = pRoot;
		*index = i;
		if(pRoot->key[i] == key){
			return true;
		}
		else if(pRoot->key[i] > key){
			return searchInBTtree(pRoot->child[i-1],key,pRes,index);
		}
		else if(i == pRoot->n){
			return searchInBTtree(pRoot->child[i],key,pRes,index);
		}
	}
}

//插入
bool insertIntoBTtree(BTNode *pRoot,int key){
	BTNode **pNode = NULL;
	int index;
	if(searchInBTtree(pRoot,key,pNode,index))
		return false;
	if(pNode->n < m-1){//该结点还有空位
		int i;
		for(i=n+1; i>index; i--){
			pNode->key[i] = pNode->key[i-1];
		}
		pNode->key[i] = key;
	}
	else{//该结点没有空位，需要拆分
		
	}
}


//删除
bool deleteFromBTtree(){
	
}


int main(){
	
	return 0;
}