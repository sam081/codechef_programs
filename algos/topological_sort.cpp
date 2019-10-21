#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define MAX_SIZE 100

void print_stack(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}

void dfs(vector<int> g[], int root){
	//modify dfs for the topological sort.
	stack<int> s;
	int visited[MAX_SIZE]={0};
	s.push(root);
	cout << "dfs: ";
	while(!s.empty()){
		int top = s.top();
		visited[top] = 1;
		cout << top << " "; 
		s.pop();
		for(int x: g[top]){
			if(!visited[x])
				s.push(x);
		}
	}
	cout << endl;
}

vector<int> S;
void topological_sort(vector<int> g[], int root, int*  visited){
	if(g[root].empty()){
		S.push_back(root);
		return;
	}
	for(int x : g[root]){
		if(!visited[x]){
			visited[x]=1;
			topological_sort(g, x, visited);
		}
	}
	S.push_back(root);
	return;
}
int main(){
	while(1){
		S.clear();
		int n,m;
		cin >> n >> m;
		vector<int> graph[MAX_SIZE];
		while(m--){
			int u,v;
			cin >> u >> v;
			graph[u].push_back(v);
		}
		int visited[MAX_SIZE] = {0};
		dfs(graph,0);
		topological_sort(graph, 0, visited);
		cout << "T-sort: ";
		for(auto it=S.rbegin(); it!=S.rend();it++)
			cout << *it << " ";
		cout << endl;
	}
}
