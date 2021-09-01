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

const ll N=2e5+5;
// vector <vi> mx, mi;
// map <pi, ll> mx, mi;
vector <vi> mx(20, vi(N));
vector <vi> mi(20, vi(N));

void rmq_init(vi &a, int n)
{
    // mx.clear();
    // mi.clear();
    // mx.resize(20, vi(n + 1, -1));
    // mi.resize(20, vi(n + 1, -1));
    
    // FORL(i, 0, n + 1)
    // mx[{i, i}] = mi[{i, i}] = a[i]; 
    
    // ll j = 2;
    // while(j <= n)
    // {
    //     FORL(i, 0, n + 1)
    //     {
    //         if(i + j - 1 > n)
    //             break;
    //         ll pr = j / 2;
    //         mx[{i, i + j - 1}] = max(mx[{i, i + pr - 1}], mx[{i + pr, i + j - 1}]);
    //         mi[{i, i + j - 1}] = min(mi[{i, i + pr - 1}], mi[{i + pr, i + j - 1}]);
    //     }
    //     j *= 2;
    // }

    FORL(i, 0, n + 1)
        mx[0][i] = mi[0][i] = a[i];
    
    ll j = 1, range = 2;
    while(range <= n)
    {
        FORL(i, 0, n + 1)
        {
            if(i + range - 1 > n)
                break;
            mx[j][i] = max(mx[j-1][i], mx[j-1][i + range / 2]);
            mi[j][i] = min(mi[j-1][i], mi[j-1][i + range / 2]);
        }
        range *= 2;
        j++;
    }
}

ll rmq_max(ll l, ll r)
{
    // ll x = r - l + 1;
    // ll z = INT_MIN;
    // ll last = l, range = 1;
    // while(x)
    // {
    //     if(x % 2)
    //     {
    //         z = max(z, mx[{last, last + range - 1}]);
    //         last = last + range;
    //     }
    //     range *= 2;
    //     x /= 2;
    // }
    // return z;
    ll x = log2(r - l + 1);
    if(l == r)
    {
        return mx[0][r];
    }
    ll sub = pow(2, x);
    return max(mx[x][l], mx[x][r - sub + 1]);
}

ll rmq_min(ll l, ll r)
{
    // ll x = 1;
    if(l == r)
    {
        return mi[0][r];
    }
    // while(x < r - l + 1)
    // {
    //     x *= 2;
    // }
    // x /= 2;
    // return min(mi[{l, l + x - 1}], mi[{r - x + 1, r}]);
    ll x = log2(r - l + 1);
    ll sub = pow(2, x);
    return min(mi[x][l], mi[x][r - sub + 1]);
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n >> m >> s;
    n++;
    vi a(n + 1, 0);

    FORL(i, 1, n + 1)
    {
        if(i == n)
        {
            a[i] = a[i-1];
            break;
        }
        if(s[i - 1] == '+')
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1] - 1;
    }

    rmq_init(a, n);
    
    // debugv(a)
    // debugv2(mx)
    // debugv2(mi)

    FOR(i, m)
    {
        cin >> x >> y;

        a1 = rmq_min(0, x - 1);
        a2 = rmq_max(0, x - 1);
        
        a3 = a[x - 1];
        
        a4 = a[y] - rmq_min(y + 1, n);
        a5 = rmq_max(y + 1, n) - a[y];
        
        a1 = min(a1, a3 - a4);
        a2 = max(a2, a3 + a5);
        
        cout << a2 - a1 + 1 << "\n\n";
    }

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