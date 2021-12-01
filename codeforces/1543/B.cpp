#include "bits/stdc++.h"
using namespace std;

#define FOR(a, b) for(ll (a) = 0; (a) < (b); (a)++)
#define MOD 10000007

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

void solve()
{
    ll n, m;
    ll sum = 0;
    cin >> n;
    vi a(n);

    FOR(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll av = sum % n;
    cout << av * (n - av) << "\n";
}

int32_t main()
{
    int t;
    
    cin >> t;
    
    while(t --)
        solve();
    
    return 0;
}