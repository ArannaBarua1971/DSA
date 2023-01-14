#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int;

int main()
{
    int test;cin>>test;

    for(int i=0;i<test;i++)
    {
        int input;cin>>input;
        vector<int> arr[input];

        for(int j=0;j<input;j++)
        {
            int n,val;
            cin>>n;
            for(int p=0;p<n;p++)
            {
                cin>>val;
                arr[j].push_back(val);
            }
        }

        for(int j=0;j<input;j++)
        {
            int min=arr[j][0];
            
        }
        cout<<endl;        
    }
}