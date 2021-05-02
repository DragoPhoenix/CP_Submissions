#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        int n = s.length();
        int f = 0;
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] != s[n-1-i])
            {
                f = 1;
                break;
            }
        }
        if(f)
        cout<<s<<"\n";
        else
        cout<<"-1\n";
    }
}