#include <stack>
using namespace std;
struct Queue{
	stack<int> stack1;
	stack<int> stack2;
}pQueue;

void push(int element){
	pQueue.stack1.push(element);
}

bool pop(){
	if(!pQueue.stack2.size() && !pQueue.stack1.size())
		return false;
	if(!pQueue.stack2.size()){
		while(pQueue.stack1.size()){
			pQueue.stack2.push(pQueue.stack1.top());
			pQueue.stack1.pop();
		}
	}
	pQueue.stack2.pop();
	return true;
}

int front(){
	if(!pQueue.stack2.size()){
		while(pQueue.stack1.size()){
			pQueue.stack2.push(pQueue.stack1.top());
			pQueue.stack1.pop();
		}
	}
	return pQueue.stack2.top();
} 