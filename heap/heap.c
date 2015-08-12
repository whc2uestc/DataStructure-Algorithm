#include <vector>
#include <stdio.h>
using namespace std;
/* Big root heap.
 * 大根堆
 */
void swap(int *a,int *b){
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
}
/* init the heap.*/
void sift(vector<int> &heap,int index){
	int temp = heap[index];
	while((index+1)*2 <= heap.size()){
		if((index+1)*2==heap.size() && temp<heap[(index+1)*2-1]){
			heap[index] = heap[(index+1)*2-1]);
			break;
		}
		else if(index*2<heap.size()){
			int max = heap[(index+1)*2]>heap[(index+1)*2-1]?(index+1)*2:(index+1)*2-1;
			if(x < heap[max]){
				heap[index] = heap[max];
				index = max;
			}else
				break;
		}else{
			break ;
		}
	}
	heap[index] = temp; 
}
void init(vector<int> &heap,int index){
	if(heap.empty())
		return ;
	int i;
	for(i=heap.size()/2; i>=0; i--){
		sift(heap,i);
	}
}

/* insert the element into the heap.*/
void insert(vector<int> &heap,int element){
	heap.push_back(element);
	int len = heap.size();
	int i = len-1;
	while(i > 0){
		if(heap[(i-1)/2] > heap[i])
			return ;
		heap[(i-1)/2] = heap[(i-1)/2]^heap[i];
		heap[i] = heap[(i-1)/2]^heap[i];;
		heap[(i-1)/2] = heap[(i-1)/2]^heap[i];
		i = (i-1)/2;
	}
}

/* get the top element.*/
bool top(vector<int> &heap,int *res){
	if(heap.empty())
		return false;
	*res = heap[0];
	sift(heap,0);
	return true;
}


void sort(vector<int> &vec){
	init(vec);
	int len = vec.size();
	while(len--){
		int num;
		top(vec,&num);
		printf("%d ",num);
	}
}

int main(){
	vector<int> vec;
	int i = 10;
	while(i--){
		vec.push_back(i);
	}
	sort(vec);
	for(i=0; i<10; i++)
		printf("%d ",vec[i]);
	return 0;
}


