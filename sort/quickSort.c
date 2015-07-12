#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getMiddle(int data[],int begin,int end){
	int front = 0;
	int tail = end - begin;
	int value = data[begin];
	int length = end - begin + 1;
	int loop = begin + 1;
	int *gQuickSort = (int*)malloc(length*sizeof(int));
	
	while(loop <= end){
		if(data[loop] < value){
			gQuickSort[front] = data[loop];
			front ++;
		}else{
			gQuickSort[tail] = data[loop];
			tail --;
		}
		loop ++;
	}
	gQuickSort[front] = value;
	memmove(&data[begin],gQuickSort,length*sizeof(int));
	
	free(gQuickSort);
	return begin + front;
}

void _quickSort(int data[],int begin,int end){
	if(begin >= end)
		return ;
	int middle = getMiddle(data,begin,end);
	_quickSort(data,begin,middle-1);
	_quickSort(data,middle+1,end);
}

void quickSort(int data[], int n){
	if(n < 0 || NULL == data)
		return ;
	_quickSort(data,0,n-1);	
}


int main(){
	int data[10] = {1,9,6,5,8,7,4,3,2,0};
	quickSort(data,10);
	int i;
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
