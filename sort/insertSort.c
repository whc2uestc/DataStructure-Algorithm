#include <stdio.h>

void insertSort(int data[],int n){
	int outer,inner;
	for(outer = 1; outer < n; outer ++){
		int temp = data[outer];
		for(inner = outer; inner > 0 && temp < data[inner-1]; inner --){
			data[inner] = data[inner-1];	
		}
		data[inner] = temp;
	}
}

int main(){
	int data[10] = {9,6,3,2,5,8,4,7,1,0};
	int i;
	insertSort(data,10);
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
