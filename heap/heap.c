#include <vector>

vector<int> heap;

/* init the heap.*/
void init(){
	if(heap.empty())
		return ;
	int i,len = heap.size();
	
}

/* insert the element into the heap.*/
void insert(int element){
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
bool top(int *res){
	if(heap.empty())
		return false;
	*res = heap[0];
	int len = heap.size()-1;
	heap[0] = heap[len];
	int i = 0;
	while(2*(i+1) < len){
		int max = heap[2*(i+1)-1]<heap[2*(i+1)]?2*(i+1):(2*(i+1)-1);
		if(heap[i] > heap[max])
			return true;
		heap[i] = heap[i]^heap[max];
		heap[max] = heap[i]^heap[max];
		heap[i] = heap[i]^heap[max];
		i = max;
	}
	if(2*(i+1)== len && heap[i]<heap[2*(i+1)-1]){
		heap[i] = heap[i]^heap[2*(i+1)-1];
		heap[2*(i+1)-1] = heap[i]^heap[2*(i+1)-1];
		heap[i] = heap[i]^heap[2*(i+1)-1];
	}
	return true;
}


