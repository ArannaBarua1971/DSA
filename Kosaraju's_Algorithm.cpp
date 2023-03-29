// to find stronly connect components in graph
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &visited,unordered_map<int,list<int>> &adj,stack<int> &topo){
	visited[node]=true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(nbr,visited,adj,topo);
		}
	}

	topo.push(node);
	return;
}

void Components(int node,vector<bool> &visited,unordered_map<int,list<int>> &adj){
	visited[node]=true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			Components(nbr,visited,adj);
		}
	}

}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// ADJ
	unordered_map<int,list<int>> adj1;
	unordered_map<int,list<int>> adj2;

	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}

	vector<bool> visited(v,false);
	vector<bool> visited1(v,false);
	stack<int> topo;

	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,visited,adj1,topo);
		}
	} 


	int Component=0;
	while(!topo.empty()){
		int start=topo.top();
		topo.pop();
		if(!visited1[start]){
			Component++;
			Components(start,visited1,adj2);
		}
	}

	return Component;
}