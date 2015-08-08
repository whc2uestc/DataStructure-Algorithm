#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * insert sort.
 */
void insertSort(int nums[],int n){
	if(n <= 1)
		return ;
	int i,j;
	for(i=1; i<n; i++){
		int temp = nums[i];
		for(j=i; j>0 && nums[j-1]>temp; j--){
			nums[j] = nums[j-1];
		}
		nums[j] = temp;
	}
}

/*
 * select sort.
 */
void selectSort(int nums[],int n){
	if(n <= 1)
		return ;
	int i,j;
	for(i=0; i<n-1; i++){
		int min = i;
		for(j=i+1; j<n; j++){
			if(nums[j] < nums[min]){
				min = j;
			}
		}
		if(min != i){
			nums[i] = nums[i]^nums[min];
			nums[min] = nums[i]^nums[min];
			nums[i] = nums[i]^nums[min];
		}
	}
}

/*
 * bubble sort.
 */
void bubbleSort(int nums[],int n){
	if(n <= 1)
		return ;
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=1; j<n-i; j++){
			if(nums[j] < nums[j-1]){
				nums[j] = nums[j]^nums[j-1];
				nums[j-1] = nums[j]^nums[j-1];
				nums[j] = nums[j]^nums[j-1];
			}
		}
	}
}

/*
 * quick sort.
 */
int _quickSort(int nums[],int s,int t){
	int node = nums[s];
	int index = s;
	while(s < t){
		while(nums[t] > node && s < t)
			t --;
		if(s == t)
			break;
		nums[index] = nums[t];
		index = t;
		s ++;
		while(nums[s] < node && s < t)
			s ++;
		if(s == t)
			break;
		nums[index] = nums[s];
		index = s;
		t --;
	}
	nums[s] = node;
	return s;
}
void quickSort(int nums[],int s,int t){
	if(t-s < 1)
		return ;
	int mid = _quickSort(nums,s,t);
	quickSort(nums,s,mid-1);
	quickSort(nums,mid+1,t);
}

/*
 * merge sort.
 */
void merge(int nums[],int s,int mid,int t){
	int i=s,j=mid+1;
	int *temp = (int*)malloc((t-s+1)*sizeof(int));
	int index = 0;
	while(i<=mid && j <= t){
		if(nums[i] < nums[j]){
			temp[index++] = nums[i++];
		}else{
			temp[index++] = nums[j++];
		}
	}
	while(i <= mid)
		temp[index++] = nums[i++];
	while(j <= t)
		temp[index++] = nums[j++];
	memcpy(nums+s,temp,(t-s+1)*sizeof(int));
	free(temp);
}
void mergeSort(int nums[],int s,int t){
	if(t-s < 1)
		return ;
	int mid = (s+t)/2;
	mergeSort(nums,s,mid);
	mergeSort(nums,mid+1,t);
	merge(nums,s,mid,t);
}



/*
 * heap sort.
 */
 
 
 
/*
 * base sort.
 */
 
 
 



int main(){
	int nums[10] = {10,5,4,7,6,8,3,9,2,1};
	mergeSort(nums,0,9);
	int i;
	for(i=0; i<10; i++){
		printf("%d ",nums[i]);
	}
	
	return 0;
}


















