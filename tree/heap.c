/*
 * the data structure of heap.
 */
 #define MAX_SIZE 20
 int heap[MAX_SIZE+1];
 int size = 0;
 void push(int element){
	 size ++;
	 int i = size;
	 while(i > 1){
		if(heap[i/2] >= element)
			break;
		heap[i] = heap[i/2];
		i = i/2;	 
	 }
	 heap[i] = element;
 }
 
 int top(){
	 return heap[1];
 }
 
 void pop(){
	 int i = 1;
	 size --;
	 while(i*2+1 <= size){
		 if(heap[i*2] >= heap[i*2+1]){
			 heap[i] = heap[i*2];
			 i = i*2;
		 }
		 else{
			 heap[i] = heap[i*2+1];
			 i = i*2 + 1;
		 }
	 }
	 if(i*2 <= size){
		heap[i] = heap[i*2];
		heap[i*2] = heap[size+1];
	 }		
	 else{
		heap[i] = heap[size+1];
	 }
 }