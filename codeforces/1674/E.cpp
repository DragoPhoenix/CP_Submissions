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

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

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

void solve()
{
    ll n, m, tt = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s, t;

    cin >> n;

    vi a(n), b(n), c(n);
    FOR(i, n)
    {
        cin >> a[i];
        if(!i)
            b[i] = a[i];
        else
        {
            b[i] = min(a[i], b[i-1]);
        }
    }

    c[n-1] = a[n-1];
    FORR(i, n - 2, 0)
    {
        c[i] = min(c[i+1], a[i]);
    }

    set<ll> ans, hf;

    hf.insert((a[0] + 1) / 2);
    a1 = a[1] - *hf.begin();
    a1 = max(0LL, a1);
    z = (a1 + 1) / 2 + *hf.begin();

    x =  max(a[0], a[1]) - min(a[0], a[1]);
    y = max(0LL, min(a[0], a[1]) - x);
    z = min(z, x + y / 3 * 2 + y % 3);

    FORL(i, 1, n - 1)
    {
        x = (a[i] + 1) / 2;
        y = max(0LL, ((min(a[i-1], a[i+1]) - x + 1) / 2));

        z = min(z, x + y);
        
        a1 = min(a[i-1], a[i+1]) - x;
        if(i - 2 >= 0)
            a1 = min(a1, b[i-2]);
        if(i + 2 < n)
            a1 = min(a1, c[i+2]);
        
        a1 = max(a1, 0LL);
        z = min(z, x + (a1 + 1) / 2);
        z = min(z, max(a[i+1], a[i-1]));
        
        x =  max(a[i], a[i-1]) - min(a[i], a[i-1]);
        y = max(0LL, min(a[i], a[i-1]) - x);

        z = min(z, x + y / 3 * 2 + y % 3);

        x =  max(a[i], a[i+1]) - min(a[i], a[i+1]);
        y = max(0LL, min(a[i], a[i+1]) - x);

        z = min(z, x + y / 3 * 2 + y % 3);

        x = min(a[i-1], a[i+1]);
        y = max(a[i-1], a[i+1]) - x;
        y = max(0LL, y);
        z = min(z, x + (y + 1) / 2);
    }

    a2 = (a[n-1] + 1) / 2;
    a1 = max(0LL, a[n-2] - a2);
    z = min(z, (a1 + 1) / 2 + a2);

    x =  max(a[n-2], a[n-1]) - min(a[n-2], a[n-1]);
    y = max(0LL, min(a[n-2], a[n-1]) - x);
    z = min(z, x + y / 3 * 2 + y % 3);
    
    sort(a.begin(), a.end());

    x = (a[0] + 1) / 2;
    y = (a[1] + 1) / 2;
    z = min(z, x + y);

    cout << z << "\n";
}

int main() 
{
    by_ANIKET
    ll T = 1,t = 0;
    // cin >> T;
    // pre();
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