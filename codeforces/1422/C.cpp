//Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007

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

const ll N=1e3+5;

ll powm(ll x, ll y, ll m = MOD)
{
    x = x % m;
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = x * x;
        x %= m;
    }
    return res;
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = 0;
    string s;

    cin >> s;

    n = s.length();

    x = n - 1;
    y = 0;
    FORR(i, n - 1, 0)
    {
        a1 = x * (x + 1) / 2 * (s[i] - '0');
        a2 = powm(10, y);
        a1 %= MOD;
        a1 = (a1 * a2) % MOD;
        z += a1;
        z %= MOD;
        z += k * (s[i] - '0');
        z %= MOD;
        k += (((y + 1) * a2) % MOD);
        k %= MOD;
        y++;
        x--;
    }

    cout << z << "\n";
}

int main() 
{
    by_ANIKET
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