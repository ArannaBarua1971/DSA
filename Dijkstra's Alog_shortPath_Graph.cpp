#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // make a adjecent list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int weight=vec[i][2];

        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    vector<int> dist(vertices);
    set<pair<int,int>> st;

    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    st.insert({dist[source],source});

    while(!st.empty()){
        auto front = *(st.begin());
        st.erase(front);

        for(auto neighbour : adj[front.second]){
            if((neighbour.second + front.first) < dist[neighbour.first]){
                dist[neighbour.first]=(neighbour.second + front.first);
                st.insert({dist[neighbour.first],neighbour.first});
            }
        }
    }

    return dist;
}
