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

const ll N=2e5+5;

bool isPrime(ll n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

ll fact(ll n)
{
    ll x = 1;
    FORL(i, 2, n + 1)
    {
        x = x * i;
        x = x % MOD;
    }
    return x;
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n;

    vi a(n);

    FOR(i, n)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            a1 = i;
            x = 1;
        }
        y = max(y, a[i]);
    }

    vi c(n);
    FORL(i, a1, n)
        c[k++] = a[i];
    FOR(i, a1)
        c[k++] = a[i];

    k = 0;
    a = c;
    a1 = 0;

    if(!x || a[0] != 1)
    {
        no
        return;
    }

    vi b(n, 0);

    b[0] = n;

    // debugv(a)
    // debugv(b)

    if(1 < n && a[1] <= a[0])
    {
        no
        return;
    }

    x = 0;
    FORL(i, 1, n)
    {
        if(a[i] - a[i-1] > 1)
        {
            x = 1;
            break;
        }
    }

    if(x)
    {
        no
        return;
    }


    // yes

    map<int, int> mp;
    mp[1] = n;
    map<int, int> putt;
    map<int, int> co;
    map<int, vi> ter;

    FORL(i, 1, n)
    {
        // pr2(a[i], a[i-1])
        if(a[i] > a[i-1])
        {
            b[i] = b[i-1] - 1;
            putt[i] = b[i-1];
            co[b[i-1]]++;
            ter[b[i-1]].PB(i);
        }
        else if(a[i] <= a[i-1])
        {
            x = a[i] - 1;
            b[i] = mp[x] - 1;
            putt[i] = mp[x];
            co[mp[x]]++;
            ter[mp[x]].PB(i);
        }
        // pr1(b[i])
        mp[a[i]] = b[i];
    }

    // debugv(b)
    // debugm(mp)
    // debugm(putt)
    // debugm(co)

    x = n;
    FORR(i, n, 1)
    {
        if(!co[i])
        {
            continue;
        }
        m = ter[i].size();
        assert(m == co[i]);
        // x = i;
        FORR(j, m - 1, 0)
        {
            b[ter[i][j]] = --x;
        }
    }

    // debugv(b)
    sort(b.begin(), b.end());

    if(b[0] != 1)
    {
        no
        return;
    }

    FORL(i, 1, n)
    {
        if(b[i] - b[i-1] != 1)
        {
            no
            return;
        }
    }

    yes
}

int main() 
{
    by_ANIKET
    ll T = 1,t = 0;
    cin >> T;
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