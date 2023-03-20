#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // make a adjcent list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }

    // let's start algo
    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<=n;i++){

        int mini=INT_MAX;
        int u;

        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }

        mst[u]=true;

        for(auto x:adj[u]){
            int n=x.first;
            int w=x.second;

            if(mst[n]==false && w<key[n]){
                key[n]=w;
                parent[n]=u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> res;

    for(int i=2;i<=n;i++){
        res.push_back({{i,parent[i]},key[i]});
    }

    return res;

}
