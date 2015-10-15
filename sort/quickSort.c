#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *the first method.
 */
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

void _quickSort_1(int data[],int begin,int end){
	if(begin >= end)
		return ;
	int middle = getMiddle(data,begin,end);
	_quickSort_1(data,begin,middle-1);
	_quickSort_1(data,middle+1,end);
}

void quickSort_1(int data[], int n){
	if(n <= 0 || NULL == data)
		return ;
	_quickSort_1(data,0,n-1);	
}

/*
 *the second method.
 */
void _quickSort_2(int nums[],int begin,int end){
	if(begin >= end)
		return ;
	int first = begin;
	int last = end;
	int key = nums[begin];
	while(first < last){
		while(first<last && nums[last]>key)
			last --;
		nums[first] = nums[last];
		while(first<last && nums[first]<key)
			first ++;
		nums[last] = nums[first];
	}
	nums[first] = key;
	_quickSort_2(nums,begin,first-1);
	_quickSort_2(nums,first+1,end);
}
void quickSort(int nums[],int n){
	if(n<=0 || NULL==nums)
		return ;
	_quickSort_2(nums,0,n-1);
}

/*
 * test.
 */
int main(){
	int data[10] = {1,9,6,5,8,7,4,3,2,0};
	quickSort(data,10);
	int i;
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
