#include <bits/stdc++.h> 
using namespace std;

void dfs(int node,vector<int> &visited,unordered_map<int,list<int>> &adj,stack<int> &st){

    visited[node]=true;

    for(auto x:adj[node]){
        if(!visited[x]){
            dfs(x,visited,adj,st);
        }
    }
    st.push(node);
    return;

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> visited(v);
    stack<int> st;
    vector<int> ans;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }

    while(v--){
        ans.push_back(st.top());
        st.pop();
    } 
    // for(auto x:ans) cout<<x<<" ";
    return ans;
}

int main()
{
    string name="aranna";

    reverse(name.begin(),name.end());

    cout<<name;
}
