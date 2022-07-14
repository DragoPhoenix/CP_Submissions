#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &e : a)
        {
            cin >> e;
        }
        int x;
        char ch;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            for(int j = 0; j < x; j++)
            {
                cin >> ch;
                if(ch == 'D')
                    a[i] += 1;
                else
                    a[i] -= 1;
                a[i] += 10;
                a[i] %= 10;
            }
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}