#include <stdio.h>

void selectSort(int data[], int n){
	int outer,inner;
	
	for(outer = n-1; outer > 0; outer -- ){
		int max = data[outer];
		int index = outer;
		for(inner = 0; inner < outer; inner ++){
			if(data[inner] > max){
				max = data[inner];
				index = inner;
			}
		}
		data[index] = data[outer];
		data[outer] = max;
	}

}

int main(){
	int data[10] = {9,6,3,2,5,8,4,7,1,0};
	int i;
	
	selectSort(data,10);
	for(i = 0; i < 10; i ++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
