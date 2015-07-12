#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int rank[1000];
void _boxSort(int data[],int rank[], int n){
	int i,j; 
	for(i = 1; i < n; i ++){
		for(j = 0; j < i; j ++){
			if(data[i] > data[j])
				rank[i] ++;
			else
				rank[j] ++;
		}	
	}
}

void boxSort(int data[],int n){
	int *rank = (int*)malloc(n*sizeof(int));
	_boxSort(data,rank,n);
	int *temp = (int*)malloc(n*sizeof(int)); 
	int i;
	for(i = 0; i < n; i ++)
		temp[rank[i]] = data[i];
	memcpy(data,temp,n*sizeof(int));

	free(rank);
	free(temp);
}

int main(){
	int data[10] = {1,9,6,5,8,7,4,3,2,0};
	boxSort(data,10);
	int i;
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
