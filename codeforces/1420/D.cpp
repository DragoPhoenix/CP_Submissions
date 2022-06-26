//Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 998244353

#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL);

#define no cout<<"No\n";
#define yes cout<<"Yes\n";

#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define pr4(a,b,c,d) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\t"<<#d<<"="<<d<<"\n";
#define pr3(a,b,c) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\n";
#define pr2(a,b) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\n";
#define pr1(a) cerr<<#a<<"="<<a<<"\n";
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int india = 0; india<N;india++) cerr<<A[india]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int india=0;india<N;india++){cerr<<"[";for(int sachin=0;sachin<M;++sachin) cerr<<A[india][sachin]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int india = 0; india< (v).size(); india++) cerr<<v[india]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int india=0;india<v.size();india++){cerr<<"[";for(int sachin=0;sachin<(v[india].size());++sachin) cerr<<v[india][sachin]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto india = m.begin(); india!=m.end();india++) cerr<<*india<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto india = m.begin();india!=m.end(); india++) cerr<<"("<<india->first<<","<<india->second<<") ";cerr<<"]\n";

typedef unsigned long long ull;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back

inline long long  max3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  min3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

const ll N=3e5+5;

vi fct(N), i_fct(N);

ll extgcd(ll a, ll b, ll &x, ll &y) {                     // ExtGCD
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

inline ll mod(ll a, ll m) {                               // mod a wrt b
    return (a % m + m) % m;
}

ll modinv(ll a) {                                         // mod inverse a wrt 10^9+7
    ll x, y;
    extgcd(a, MOD, x, y);
    return mod(x, MOD);
}

void pre()
{
    fct[0] = 1;
    FORL(i, 1, N)
    {
        fct[i] = fct[i-1] * i;
        fct[i] %= MOD;
    }

    /*
    n! = n * (n-1) !
    ==> 1/(n-1!) = n/(n!)
    ==> (1/(n-1!)) % M = (n/(n!)) % M
    ==> (1/(n-1!)) % M = ((n % M) * ((1/(n!)) % M)) % M
    */

    i_fct[N - 1] = modinv(fct[N - 1]);
    FORR(i, N-2, 0)
    {
        i_fct[i] = i_fct[i + 1] * (i + 1);
        i_fct[i] %= MOD;
    }
}

ll C(ll n, ll r)
{
    return (((fct[n] * i_fct[r]) % MOD ) * i_fct[n-r]) % MOD;
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n >> k;
    
    vector<pi> a(n);
    map<ll, ll> mp;
    FOR(i, n)
    {
        cin >> a[i].S >> a[i].F;
        mp[a[i].S] += 1;
        mp[a[i].F + 1] -= 1;
    }

    vi bin;
    for(auto &e : mp)
    {
        bin.PB(e.F);
        e.S += x;
        x = e.S;
    }

    sort(a.begin(), a.end());

    FOR(i, n)
    {
        x = a[i].S;
        y = a[i].F;
        if(mp.find(y) != mp.end())
        {
            t = mp[y];
        }
        else
        {
            auto it = lower_bound(bin.begin(), bin.end(), y) - bin.begin();
            it--;
            mp[y] = mp[bin[it]];
            t = mp[y];
        }
        if(t-1 >= k-1)
        {
            z += C(t-1, k-1);
            z %= MOD;
        }
        mp[y]--;
    }
    cout << z << "\n";
}

int main() 
{
    by_ANIKET
    pre();
    ll T = 1,t = 0;
    // cin >> T;
    while(t++ < T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
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