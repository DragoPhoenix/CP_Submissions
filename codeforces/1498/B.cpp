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

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0;
    ll W;
    
    cin >> n >> W;
    
    multiset <int> w;
    FOR(i, n)
    {
        cin >> t;
        w.insert(t);
    }
    ll l = 0, r = n - 1;
    while (!w.empty())
    {
        k = *w.rbegin();
        auto i = w.lower_bound(k);
        w.erase(i);
        while(k < W)
        {
            t = W - k;
            auto it = w.upper_bound(t);
            if(it == w.begin())
            break;
            it--;
            k += *it;
            w.erase(it);
        }
        z++;
    }
    cout << z << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1, t = 0;
    cin >> T;
    while (t++ < T)
        solve();
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
//   ©
//                      ______  __    __ ______ __    __ ________ ________ 
//                     /      \|  \  |  \      \  \  /  \        \        \
//                    |  ▓▓▓▓▓▓\ ▓▓\ | ▓▓\▓▓▓▓▓▓ ▓▓ /  ▓▓ ▓▓▓▓▓▓▓▓\▓▓▓▓▓▓▓▓
//  ______ ______     | ▓▓__| ▓▓ ▓▓▓\| ▓▓ | ▓▓ | ▓▓/  ▓▓| ▓▓__      | ▓▓   
// |      \      \    | ▓▓    ▓▓ ▓▓▓▓\ ▓▓ | ▓▓ | ▓▓  ▓▓ | ▓▓  \     | ▓▓   
//  \▓▓▓▓▓▓\▓▓▓▓▓▓    | ▓▓▓▓▓▓▓▓ ▓▓\▓▓ ▓▓ | ▓▓ | ▓▓▓▓▓\ | ▓▓▓▓▓     | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓ \▓▓▓▓_| ▓▓_| ▓▓ \▓▓\| ▓▓_____   | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓  \▓▓▓   ▓▓ \ ▓▓  \▓▓\ ▓▓     \  | ▓▓   
//                     \▓▓   \▓▓\▓▓   \▓▓\▓▓▓▓▓▓\▓▓   \▓▓\▓▓▓▓▓▓▓▓   \▓▓   