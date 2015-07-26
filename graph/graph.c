#include <vector>
3include <queue>
#include <algorithm>
using namespace std;

#define MAX_V 20;
/* the struct to express the graph.*/
//无权图
vector<int> G[MAX_V];
//带权图
/* struct edge{int to,cost;};
 * vector<edge> G[MAX_V];
 */
int V;	//the number of vertices.
int E; 	//the number of edge.


/* judge whether the edge exists in the graph.*/
bool existsEdge(int i,int j){
	vector<int>::iterator it;
	for(it=G[i].begin(); it!=G[i].end(); it++)
		if(j == *it)
			return true;
	return false;
}
 
/* insert the edge into the graph.*/
void insertEdge(int i,int j){
	if(existsEdge(i,j))
		return ;
	G[i].push_back(j);
	G[j].push_back(i);
}
/* erase the edge from the graph.*/
void eraseEdge(int i,int j){
	for(it=G[i].begin(); it!=G[i].end(); it++)
		if(j == *it)
			G[i].erase(it);
	for(it=G[j].begin(); it!=G[j].end(); it++)
		if(i == *it)
			G[j].erase(it);
}
/* get the degree of the vertices.*/
int degree(int i){
	return G[i].size();
}
/* the dfs of graph.*/
void dfs(int v){
	static int flag[MAX_V] = {0};
	flag[v] = 1;
	for(int i=0; i<G[v].size(); i++){
		if(0 == flag[G[v][i]]){
			dfs(G[v][i]);
			printf("%d <--> %d\n",v,G[v][i]);
		}
	}
}

/* the bfs of graph.*/
void bfs(int v){
	queue<int> que;
	bool flag[MAX_V];
	fill(flag,flag+MAX_V,false);
	que.push(v);
	flag[v] = true;
	while(!que.empty()){
		int vi = que.front();
		que.pop();
		vector<int> it;
		for(it=G[vi].begin(); it!=G[vi].end(); it++){
			if(!flag[*it]){
				printf("%d <--> %d\n",vi,*it);
				que.push(*it);
				flag[*it] = true;
			}
		}
	}
}