#include <vector>
using namespace std;

#define MAX_V 20;
/* the struct to express the graph.*/
//无权图
vector<int> G[MAX_V];
//带权图
/* struct edge{int to,cost;};
 * vector<edge> G[MAX_V];
 */

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
	int flag[MAX_V] = {0};
	int i = 0;
	list<int> list_v;
	while(i < MAX_V){
		flag[v] = 1;
		vector<int>::iterator it;
		for(it = G[v].begin(); it!=G[v].end(); it++){
			if(0 == flag[*it]){
				printf("%d <--> %d\n",v,*it);
				list_v.push(*it);
			}
		}
		if(list_v.size()){
			v = list_v.front();
			list_v.pop();
		}else{
			
		}
		i ++;
	}
}