#include <bits/stdc++.h>
using namespace std;

int    dfs(int node,unordered_map<int,vector<int>> &adj,int target,vector<bool> &visited,int &path)
{
    visited[node]=true;
    int ch=0;
    for(auto x:adj[node]){

        if(x==target) {
            path++;
            ch=1;
            break;
        }
        else if(!visited[x]){
            path++;
            dfs(x,adj,target,visited,path);
            return path;
        }
    }
    if(ch==0){
        path=-1;
    }
    return path;
}


int bfs(int node,unordered_map<int,vector<int>> &adj,vector<bool> &visited){

    set<int>st;
    visited[node]=true;
    for(auto x:adj[node]){
        int path=dfs(x,adj,node,visited,path);
        if(path!=-1){
            path++;
        }
        st.insert(path);
        path=0;
    }
    return *st.begin();
}

void solve(vector<vector<int>> &vc)
{
    int t = vc.size();
    unordered_map<int,vector<int>> adj;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if(vc[i][j]==1){
                adj[i].push_back(j);
            }

        }
    }
    

    vector<bool>visited(t);

    for(int i=0;i<t;i++){

        int path=bfs(i,adj,visited);
        // cout<<"path::"<<path<<endl;
        if(path==-1){
            cout<<"NO WAY"<<endl;
        }
        else{
            cout<<path<<endl;
        }
        fill(visited.begin(),visited.end(),false);
    }
}

int main()
{
    // your code goes here

    int t;
    cin >> t;

    vector<vector<int>> vc(t, vector<int>(t));

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int num;
            cin >> num;
            vc[i][j] = num;
        }
    };

    int start = 0;
    do
    {
        solve(vc);
    } while (start != 0);
}
