//Hey stalker :)
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

void solve()
{
    ll n,m,t=0,k=0,x=0,y=0,z=0,a1,a2,a3,a4,a5,var=1,f=INF;
    cin>>n;
    vi a(n);
    FOR(i,n)cin>>a[i];
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    ll s,c;
    s=a[0];
    x=0;
    z=1;
    y=a[x+1]-a[x];
    while(x+1<n&&a[x+1]>=a[x])
    {
        if(y!=a[x+1]-a[x])
            z=0;
        x++;
    }
    if(x==n-1&&z)
    {
        cout<<"0\n";
        return;
    }
    else if(x==n-1)
    {
        cout<<"-1\n";
        return;
    }
    x=n-1;
    z=1;
    y=a[x-1]-a[x];
    while(x>=1&&a[x-1]>=a[x])
    {
        if(y!=a[x-1]-a[x])
            z=0;
        x--;
    }
    if(x==0&&z)
    {
        cout<<"0\n";
        return;
    }
    else if(x==0)
    {
        cout<<"-1\n";
        return;
    }
    vector <pi> v;
    FOR(i,n)
    {
        // pr1(i)
        // if(i+1<n)
        //     c = a[i+1]-a[i];
        // else
        //     c = -1;
        a1=i;
        while(i+1<n&&a[i+1]>=a[i])
        {
            // if(a[i+1]-a[i]!=c)
            // {
            //     cout<<"-1\n";
            //     return;
            // }
            // pr2(a[i],a[i+1])
            i++;
        }
        
        v.PB({a1,i});
    }
    for(auto e:v)
    {
        // debugp(e)
        if(e.F+1<n)
        x=a[e.F+1] - a[e.F];
        if(e.F!=e.S)
        {
            c=x;
        }
        FORL(i,e.F+1,e.S)
        {
            // pr1(i)
            if(x!=a[i+1]-a[i])
            {
                cout<<"-1\n";
                return;
            }
        }
        // pr1("\n")
    }
    // pr1("POSS")
    m=a[v[0].S]+c - a[v[0].S+1];
    // pr2(m,c)
    for(auto e:v)
    {
        if(e.S+1<n)
        {
            x=a[e.S]+c - a[e.S+1];
            if(x!=m)
            {
                cout<<"-1\n";
                return;
            }
        }
    }
    if(a[0]>=m||c>=m||c<0||m<=0)
    {
        cout<<"-1\n";
        return;
    }
    //m>s
    vi b(n);
    b[0]=a[0]%m;
    FORL(i,1,n)
    {
        b[i]=(a[i-1]+c)%m;
    }
    if(a==b)
    cout<<m<<" "<<c<<"\n";
    else
        cout<<"-1\n";
}

int main() 
{
    by_ANIKET
    ll T=1,t=0;
    cin>>T;
    while(t++<T)
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
    