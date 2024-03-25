// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> num){
    int value=num[num.size()-1];
    
    for(int i=0;i<n;i++){
        while(num[i]<value){
            num[i]=num[i]+num[i]%10;
        }
        value=max(num[i],value);
    }
    for(int i=0;i<n;i++){
        if(value!=num[i]){ cout<<"No"<<endl;break;}
    }
    cout<<"Yes"<<endl;
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        vector<int> num;
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            num.push_back(temp);
        }
        solve(n,num);
    }

    return 0;
}