#include <stdio.h>
//定义一个m阶B树
#define m 4

typedef struct BTreeNode{
	int n;//n个关键字
	int key[m];//key from 1 to m-1
	struct BTreeNode *child[m];//child from 0 to m-1
	struct BTreeNode *parent;
}BTNode;

//插入
void insertIntoBTtree(){
	
}

//查找
bool searchInBTtree(BTNode *pRoot,int key,BTNode **pRes,int *index){
	if(NULL == pRoot)
		return false;
	int i = 0;
	for(i=1; i<=n; i++){
		if(pRoot->key[i] == key){
			*pRes = pRoot;
			*index = i;
			return true;
		}
		else if(pRoot->key[i] > key){
			return searchInBTtree(pRoot->child[i-1],key,pRes,index);
		}
		else if(i == n){
			return searchInBTtree(pRoot->child[i],key,pRes,index);
		}
	}
}

//删除
bool deleteFromBTtree(){
	
}


int main(){
	
	return 0;
}