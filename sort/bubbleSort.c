#include <stdio.h>

void bubbleSort(int data[], int n){
	int outer,inner;
	for(outer = n-1; outer > 0; outer --){
		for(inner = 0; inner < outer; inner ++){
			if(data[inner] > data[inner+1]){
				int temp = data[inner];
				data[inner] = data[inner+1];
				data[inner+1] = temp;
			}
		}
	}	
}


int main(){
	int data[10] = {1,9,6,5,8,7,4,3,2,0};
	bubbleSort(data,10);
	int i;
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
