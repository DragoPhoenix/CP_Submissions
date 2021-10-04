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
    cin>>n>>k;
    string s,st;
    cin>>s;
    FOR(i,n)
    {
        if(s[i] == '*' && x != 1)
        {
            s[i] = 'x';
            x++;
                a1 = i;
        }
    }
    FORR(i, n-1, a1 + 1)
    {
        if(s[i] == '*' && x != 2)
        {
            s[i] = 'x';
            x++;
                a2 = i;
        }
    }
    // pr2(s,x)
    if(a2 - a1 <= k && x == 2)
    {
        cout << x << "\n";
        return;
    }
    else if(x < 2)
    {
        assert( x != 0 );
        cout << x << "\n";
        return;
    }
    st = s;
    // pr1(s)
    FORL(i,a1+1,n)
    {
        // pr2(i,s)
        if(s[i]== '*')
            y = i;
        if(s[i] == 'x')
        {
            // a1 = i;
            assert( i == a2);
            break;
        }
        if(i - a1 > k)
        {
            // pr3(i,a1,k)
            y = i - 1;
            while(s[y] != '*')
            {
                y--;
            }
            s[y] = 'x';
            i = y;
            a1 = y;
        }
    }
    if(a2 - a1 > k)
    {
        // pr1(y)
        assert(a2 - y <= k);
        s[y]='x';
    }
    // pr2(s,k)
    FOR(i,n)
    {
        // pr1(e)
        if(s[i] == 'x')
            z++;
    }
    // pr1(z)
    s = st;

    FORR(i,a2-1,0)
    {
        // pr1(i)
        if(s[i] == 'x')
        {
            a2 = i;
            break;
        }
        if(a2 - i > k)
        {
            // pr3(i,a1,k)
            y = i + 1;
            while(s[y] != '*')
            {
                y++;
            }
            s[y] = 'x';
            i = y;
            a2 = y;
        }
    }
    // pr2(s,k)
    y=z;
    z=0;
    FOR(i,n)
    {
        // pr1(e)
        if(s[i] == 'x')
            z++;
    }
    cout<<y<<"\n";
}

int main() 
{
    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
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
 