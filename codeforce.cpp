#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 


void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,stack<int> &st){

    visited[node]=true;
    stack<int> st;

    for(auto x:adj[node]){
        if(!visited[x]){
            dfs(x,visited,adj,st);
        }
    }
    stack.push(node);
    return;

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    stack<int> st;
    vector<int> ans;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }

    while(v--){
        ans.push(st.top());
        st.pop();
    } 

    return ans;
}

int main()
{
    string name="aranna";

    reverse(name.begin(),name.end());

    cout<<name;
}
