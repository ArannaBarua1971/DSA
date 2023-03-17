#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> &ans,unordered_map<int,set<int>> adj,unordered_map<int,bool> &visited){
    ans.push_back(node);
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,ans,adj,visited);
        }
    }
}

void depthFirstSearch(int v,int e,vector<vector<int>> & edges){

    // adjecent list
    unordered_map<int,list<int>> adj;
    
    for(auto i:edges){
        int u=i[0];
        int v=i[1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,ans,adj,visited);
        }
    }
    cout<<ans.size();
    for(auto x:ans) cout<<x<<" ";
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>  edges;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[i].push_back(a);
        edges[i].push_back(b);
    }
    cout<<edges[0][0];
    // depthFirstSearch(v,e,edges);
}