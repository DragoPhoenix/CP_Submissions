#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i = a; i<=b; i++)
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K,d,t;
    set <int> digits = {1,2,3,4,5,6,7,8,9,0};
    cin >> N >> K;
    FOR(i,0,K-1)
    {
        cin>>d;
        digits.erase(d);
    }
    FOR(i,N,10000000000)
    {
        d = i;
        int f = 1;
        while(d)
        {
            t = d%10;
            if(digits.find(t) == digits.end())
            {
                f = 0;
                break;
            }
            d/=10;
        }
        if(f)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
}