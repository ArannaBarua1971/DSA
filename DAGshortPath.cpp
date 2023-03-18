#include <bits/stdc++.h>
#include<limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void makeAdj(int u, int v, int m)
    {
        adj[u].push_back({v, m});
    }
    void printEdge(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> ";
            for (auto j : adj[i])
            {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (auto x : adj[node])
        {
            if (!visited[x.first])
            {
                dfs(x.first, visited, st);
            }
        }
        st.push(node);
        return;
    }

    void topo(int n, stack<int> &st, unordered_map<int, bool> &visited)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st);
            }
        }
    }

    void dist(int start, stack<int> &st, vector<int> &dis)
    {
        dis[start] = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (dis[top] != INT_MAX)
            {
                for(auto i:adj[top]){
                    if((dis[top]+i.second) < dis[i.first]){
                        dis[i.first]=dis[top]+i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;

    g.makeAdj(0, 1, 5);
    g.makeAdj(0, 2, 3);
    g.makeAdj(1, 2, 2);
    g.makeAdj(1, 3, 6);
    g.makeAdj(2, 3, 7);
    g.makeAdj(2, 4, 4);
    g.makeAdj(2, 5, 2);
    g.makeAdj(3, 4, -1);
    g.makeAdj(4, 5, -2);

    g.printEdge(6);

    stack<int> st;
    unordered_map<int, bool> visited;
    vector<int> dis(6);
    int start = 1;

    for (int i = 0; i < 6; i++)
    {
        dis[i] = INT_MAX;
    }

    g.topo(6, st, visited);
    g.dist(start, st, dis);
    for(auto x:dis) cout<<x<<" ";
}