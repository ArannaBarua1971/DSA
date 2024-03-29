
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int maximumLengthSubstring(string s) {
        unordered_map<int,int> helper;
        queue<int> temp;
        int maxValue=0;
        
        for(auto ch : s){
            helper[ch]++;
            temp.push(ch);
            
            if(helper[ch]>2){
                maxValue=temp.size()-1;
                while(true){
                    
                    char ele=temp.front();
                    helper[ele]--;
                    temp.pop(); 
                    
                    if(ch==ele){
                        break;
                    }
                }
                int size=temp.size();
                maxValue=max(maxValue,size);
            }
        }
        
        return maxValue;
    }
void solve(int a, int b, int c)
{
    if (a < b && b < c)
    {
        cout << "STAIR" << endl;
    }
    else if (a < b && b > c)
    {
        cout << "PEAK" << endl;
    }
    else
    {
        cout << "NONE" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
}