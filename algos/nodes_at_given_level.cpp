#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int nodes_at_nth_level(vector<int> graph[], int level){
	// assumed that root is 0;
	int visited[100] ={0};
	visited[0] = 1;
	queue<int> q1,q2;
	q1.push(0);
	int curr_level = 0, counter = 0;
start:
	while(1){
		if(q1.empty()){
			if(curr_level == level) goto end;
			curr_level++;
			break;
		}
		int node = q1.front();
		q1.pop();
		if(curr_level == level){
			counter++;
		}
		for(auto x:graph[node]){
			if(!visited[x])
				q2.push(x);
			visited[x] = 1;
		}
	}
	while(1){
		if(q2.empty()){
			if(curr_level == level) goto end;
			curr_level++;
			break;
		}
		int node = q2.front();
		q2.pop();
		if(curr_level == level){
				counter++;
		}
		for(auto x:graph[node]){
			if(!visited[x])
				q1.push(x);
			visited[x] = 1;
		}
	}
	if(curr_level <=  level)
		goto start;
end:
	return counter;
}
int main(){
	int n;
	cin >> n;
	vector<int> graph[100];
	while(n--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	while(1){
		int level;
		cin >> level;
		if(level == -1){ break; }
		cout << nodes_at_nth_level(graph, level) << endl;
	}
}
