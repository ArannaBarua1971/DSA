
#include <bits/stdc++.h>
using namespace std;

#define ll long long
bool isBinaryDecimal(int num)
{
    string s = to_string(num);

    for (char c : s)
    {
        if (c != '0' and c != '1')
        {
            return false;
        }
    }

    return true;
}

void solve(int n,vector<int>arr){
if (isBinaryDecimal(n))
        {
            cout << "YES" << endl;
        }
        else
        {

            for (auto num : arr)
            {
                while (n % num == 0)
                {
                    n = n / num;
                }
            }
            if (isBinaryDecimal(n))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
}

int main()
{
    int t;
    cin >> t;

    vector<int> arr;

    for (int i = 2; i < 100001; i++)
    {
        if (isBinaryDecimal(i))
        {
            arr.push_back(i);
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        solve(n,arr);
    }
}