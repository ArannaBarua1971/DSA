#include <bits/stdc++.h>
#include<unordered_map>
#include<math.h>
using namespace std;

void solve(){
    double n;
    cin>>n;

    vector<int> v1,v2;
    vector<pair<int,int>> p;
    int max1=0, max2=0,id1=0,id2=0;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(max1<x){
             max1=x;
             id1=i;
        }
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(max2<x) {
            max2=x;
            id2=i;
        }
        v2.push_back(x);
    }

    if(max1>v1[n-1] && max2>v2[n-1]){
        cout<<"No"<<endl;
        return;
    }
    else if(max1>v1[n-1]){
        if(max1>v2[n-1]){
            cout<<"No"<<endl;
            return;
        }
        if(v2[id1]>v1[n-1]){
            cout<<"No"<<endl;
            return;
        }
        if(max1<max2) max1=max2;
        for(int i=0;i<n;i++){
            if(v1[i]==max1 && v2[i]==max1){
                    cout<<"No"<<endl;
                    return;
            }
        }
    }  
    else if(max2>v2[n-1]){
        if(max2>v1[n-1]){
            cout<<"No"<<endl;
            return;
        }
        if(v1[id2]>v2[n-1]){
            cout<<"No"<<endl;
            return;
        }
        if(max1<max2) max1=max2;
        for(int i=0;i<n;i++){
            if(v1[i]==max1 && v2[i]==max1){
                    cout<<"No"<<endl;
                    return;
            }
        }
    } 
    cout<<"Yes"<<endl;
    return;
}
int main()
{
    int t;cin>>t;

    while(t--){
        solve();
    }
}