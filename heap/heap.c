#include <vector>
#include <stdio.h>
using namespace std;
/* Big root heap.
 * 大根堆
 */
static void swap(int *a,int *b){
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
}
/* init the heap.*/
void sift_up(vector<int> &heap,int index){
	while((index+1)/2-1 >= 0){
		if(heap[(index+1)/2-1] < heap[index]){
			swap(&heap[(index+1)/2-1],&heap[index]);
			index = (index+1)/2-1;
		}else
			break;
	}
}

void heap_init(vector<int> &heap){
	if(heap.empty())
		return ;
	for(int i=1; i<heap.size(); i++){
		sift_up(heap,i);
	}
}

/* insert the element into the heap.*/
void heap_insert(vector<int> &heap,int element){
	heap.push_back(element);
	sift_up(heap,heap.size()-1);
}

/* get the top element.*/
void sift_down(vector<int> &heap,int index){
	while(index*2+2 < heap.size()){
		if(heap[index*2+1]>=heap[index*2+2] && heap[index]<heap[index*2+1]){
			swap(&heap[index],&heap[index*2+1]);
			index = index*2+1;
		}else if(heap[index*2+1]<heap[index*2+2] && heap[index]<heap[index*2+2]){
			swap(&heap[index],&heap[index*2+2]);
			index = index*2+2;
		}else
			break;
	}
}
bool heap_top(vector<int> &heap,int *res){
	if(heap.empty())
		return false;
	*res = heap[0];
	heap[0] = heap[heap.size()-1];
	heap.erase(heap.end()-1);
	sift_down(heap,0);
	return true;
}

void heap_sort(vector<int> &vec){
	heap_init(vec);
	for(int i=10;i<20;i++)
		heap_insert(vec,i);
	int len = vec.size();
	while(len--){
		int num;
		heap_top(vec,&num);
		printf("%d ",num);
	}
}

int main(){
	vector<int> vec;
	for(int i=0; i<10; i++){
		vec.push_back(i);
	}
	heap_sort(vec);
	return 0;
}