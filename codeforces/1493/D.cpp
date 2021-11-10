#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
 
#define max(a, b) (a < b? b : a)
#define min(a, b) ((a>b)?b:a)
 
#define MOD 1000000007
 
#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define all(v)                      (v).begin(),(v).end()
#define Sort(v)                     sort(all((v)))
#define rSort(v)                    sort((v).rbegin(),(v).rend())
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  (x/gcd(x,y))*y
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
 
#define no cout<<"No\n";
#define yes cout<<"Yes\n";
 
#define Clear( a, b ) memset( a, b, sizeof( a ) )
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
 
#define pr3(a,b,c) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\n";
#define pr2(a,b) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\n";
#define pr1(a) cerr<<#a<<"="<<a<<"\n";
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
typedef unsigned long long ull;
typedef int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
 
#define F first
#define S second
#define PB push_back
#define POB pop_back
 
inline long long  max3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  min3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
 
const ll N=2e5+5;
vi pr;
map<ll,ll> cnt[N];
vi a(N);
vi spf(N);

ll powm(ll x,ll y,ll m=MOD)
{
    x=x%m;
    ll res=1;
    while(y)
    {
        if(y&1)
            res=(res*x)%m;
        y=y>>1;
        x=x*x;
        x%=m;
    }
    return res;
}

void Sieve(ll n = N)
{
    bool prime[n+5];
    Clear(prime,true);
    prime[0]=prime[1]=false;
    FOR(i,n+1)
    spf[i]=i;
    for(ll i = 2; i * i <= n; i++)
    {
        for(ll j = i * 2; j <= n; j += i)
        {
            if(spf[j]!=j)continue;
            spf[j]=i;
            prime[j]=false;
        }
    }
    FORL(i,2,n+1)
        if(prime[i])
            pr.PB(i);
}

void solve()
{
    ll n,m,k,c=0,x=0,y=0,z,a1,a2,a3;
    cin>>n>>m;
    FOR(i,n)cin>>a[i];
    
    ll g=a[0];
    FORL(i,1,n)
    g=gcd(g,a[i]);
    FOR(i,n)
    {
        a[i]/=g;
    }
    multiset <ll> prime_pov[pr.size()];
    FOR(i,n)
    {
        z = a[i];
        while(z!=1)
        {
            x=spf[z];
            y=0;
            while(z%x==0)
            {
                z/=x;
                y++;
            }
            auto idx = lower_bound(pr.begin(), pr.end(), x)-pr.begin();
            prime_pov[idx].insert(y);
            cnt[i][idx]=y;
        }
    }
    FOR(i,m)
    {
        cin>>y>>x;
        
        while(x!=1)
        {
            a1 = spf[x];
            // pr2(x,spf[x])
            int count = 0;
            while(x % a1 == 0)
            {
                x /= a1;
                count ++;
            }
            auto index = lower_bound(pr.begin(), pr.end(), a1) - pr.begin();
            if(cnt[y-1].find(index) != cnt[y-1].end())
            {
                ll ini = *prime_pov[index].begin(); 
                auto itr = prime_pov[index].find(cnt[y-1][index]);
                assert(itr != prime_pov[index].end());
                prime_pov[index].erase(itr);
                cnt[y-1][index] += count;
                prime_pov[index].insert(cnt[y-1][index]);

                ll fi = *prime_pov[index].begin();
                

                if(fi - ini != 0 && prime_pov[index].size() == n)
                {
                    g= (1LL*g * powm(pr[index],(fi - ini)))%MOD;
                }
            }
            else
            {
                cnt[y-1][index] = count;
                prime_pov[index].insert(cnt[y-1][index]);
                if(prime_pov[index].size() == n)
                {
                    g= (1LL* g * powm(pr[index],(*prime_pov[index].begin())))%MOD;
                }
            }
        }
        cout<<g<<"\n";
    }
}

int main() 
{
    by_ANIKET
    ll T=1,t=0;
    // cin>>T;
    Sieve();
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
/*//   ©
//                      ______  __    __ ______ __    __ ________ ________ 
//                     /      \|  \  |  \      \  \  /  \        \        \
//                    |  ▓▓▓▓▓▓\ ▓▓\ | ▓▓\▓▓▓▓▓▓ ▓▓ /  ▓▓ ▓▓▓▓▓▓▓▓\▓▓▓▓▓▓▓▓
//  ______ ______     | ▓▓__| ▓▓ ▓▓▓\| ▓▓ | ▓▓ | ▓▓/  ▓▓| ▓▓__      | ▓▓   
// |      \      \    | ▓▓    ▓▓ ▓▓▓▓\ ▓▓ | ▓▓ | ▓▓  ▓▓ | ▓▓  \     | ▓▓   
//  \▓▓▓▓▓▓\▓▓▓▓▓▓    | ▓▓▓▓▓▓▓▓ ▓▓\▓▓ ▓▓ | ▓▓ | ▓▓▓▓▓\ | ▓▓▓▓▓     | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓ \▓▓▓▓_| ▓▓_| ▓▓ \▓▓\| ▓▓_____   | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓  \▓▓▓   ▓▓ \ ▓▓  \▓▓\ ▓▓     \  | ▓▓   
//                     \▓▓   \▓▓\▓▓   \▓▓\▓▓▓▓▓▓\▓▓   \▓▓\▓▓▓▓▓▓▓▓   \▓▓   
*/