#include<iostream>
#include<queue>

using namespace std;

#define MAX_NODES 100

bool isBipartite(vector<int> graph[], int root){
	queue<int> q;
	q.push(root);
	int visited[MAX_NODES]={0};
	visited[root] = 1;
	
	int color[MAX_NODES] = {0};
	color[root] = 1;

	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(auto &x : graph[top]){
			if(visited[x] == 0){
				q.push(x);
				visited[x] = 1;
				if( color[top] == 1)
					color[x] = 2;
				else 
					color[x] = 1;
			}
			else if(color[x] == color[top])
				return false;
		}
	}
	return true;
}

int main(){
	int u,v,N;
	cin >> N;

	vector<int> graph[MAX_NODES];

	while(N--){
		cin >> u >> v;	
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << isBipartite(graph,0) << endl;
	return 0;
}
