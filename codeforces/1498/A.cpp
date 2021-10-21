#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

#define MOD 1000000007

#define FOR(a, c) for (ll(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (ll(a) = (b); (a) < (c); (a)++)
#define FORR(a, b, c) for (ll(a) = (b); (a) >= (c); (a)--)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs

#define no cout << "No\n";
#define yes cout << "Yes\n";

#define Clear(a, b) memset(a, b, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

typedef unsigned long long ull;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back

const ll N = 2e5 + 5;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    cin >> n;
    while (true)
    {
        m = n;
        x = 0;
        while (m)
        {
            x += (m % 10);
            m /= 10;
        }
        if (gcd(x, n) != 1)
        {
            cout << n << "\n";
            return;
        }
        n++;
    }
}

int main()
{
    ll T = 1, t = 0;
    cin >> T;
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    while (t++ < T)
        solve();
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
