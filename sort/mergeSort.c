#include <stdio.h>
#include <stdlib.h>
void merge(int nums,int s,int m,int t){
	int *arr = (int*)malloc((t-s+1)*sizeof(int));
	int b1 = s,b2 = mid+1,i = 0;
	while(b1<=m && b2<=t){
		if(nums[b1] < nums[b2]){
			arr[i++] = nums[b1++];
		}else{
			arr[i++] = nums[b2++];
		}
	}
	if(b1 == m+1){
		while(b2<=t){
			arr[i++] = nums[b2++];
		}
	}else{
		while(b1<=m)
			arr[i++] = nums[b1++];
	}
	memcpy(&nums[s],arr,(t-s+1)*sizeof(int));
	free(arr);
}


void _mergeSort(int nums[],int s,int t){
	if(s == t)
		return ;
	int mid = (s+t)/2;
	_mergeSort(nums,s,mid);
	_mergeSort(nums,mid+1,t);
	merge(nums,s,mid,t);
}
void mergeSort(int nums[],int n){
	if(0 == n || 1 == n)
		return;
	_mergeSort(nums,0,n-1);
}



