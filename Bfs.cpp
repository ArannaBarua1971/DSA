#include <bits/stdc++.h>
using namespace std;
void adjecentlist(vector<pair<int, int>> &edges,
                  unordered_map<int, set<int>> &adjlist) {

  for (auto &pr : edges) {
    int u = pr.first;
    int v = pr.second;

    adjlist[u].insert(v);
    adjlist[v].insert(u);
  }
}

void bfsdo(unordered_map<int, set<int>> adjlist, vector<int> &ans,unordered_map<int, bool> &visited,int Node) {

    queue<int> q;
    q.push(Node);
    visited[Node]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
            
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {

  vector<int> ans;
  unordered_map<int, set<int>> adjlist;
  unordered_map<int, bool> visited;

  adjecentlist(edges, adjlist);

  for (int i = 0; i < vertex; i++) {
    if (!visited[i]) {
      bfsdo(adjlist, ans,visited,i);
    }
  }
  return ans;

}