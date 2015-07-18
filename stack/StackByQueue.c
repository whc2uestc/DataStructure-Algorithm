#include <queue>
using namespace std;

struct Stack{
	queue<int> queue1;
	queue<int> queue2;
}pStack;

void push(int element){
	pStack.queue1.push(element);
}

bool pop(){
	if(!pStack.queue1.size() && !pStack.queue2.size())
		return false;
	
	if(pStack.queue1.size())	{
		while(pStack.queue1.size() != 1){
			pStack.queue2.push(pStack.queue1.front());
			pStack.queue1.pop();
		}
		pStack.queue1.pop();
		return true;
	}
	else{
		while(pStack.queue2.size() != 1){
			pStack.queue1.push(pStack.queue2.front());
			pStack.queue2.pop();
		}
		pStack.queue2.pop();
		return true;
	}
}

int top(){
	if(pStack.queue1.size())	{
		while(pStack.queue1.size() != 1){
			pStack.queue2.push(pStack.queue1.front());
			pStack.queue1.pop();
		}
		return pStack.queue1.front();
	}
	else{
		while(pStack.queue2.size() != 1){
			pStack.queue1.push(pStack.queue2.front());
			pStack.queue2.pop();
		}
		int top = pStack.queue2.front();
		pStack.queue2.pop()
		pStack.queue1.push(top);
		return top;
	}
}