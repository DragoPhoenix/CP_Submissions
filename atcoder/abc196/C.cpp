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

const ll N=2e7+5;

void solve()
{
    ll n,m,k,c=0,x=0,y=0,z=-INF,a1,a2,a3,a4;
    cin >> n;
    string s,s1,t;
    vi a;
    FORL(i,1,10)
    {
        s='0'+i;
        t=s+s;
        x=stoll(t);
        a.PB(x);
    }
    FORL(i1,1,10)
    {
        FORL(i2,0,10)
        {
            s=('0'+i1);
            s+=('0'+i2);
            t=s+s;
            x=stoll(t);
            a.PB(x);
        }
    }

    FORL(i1,1,10)
    {
        FORL(i2,0,10)
        {
            FORL(i3,0,10)
            {
                s=('0'+i1);
                s+=('0'+i2);
                s+=('0'+i3);
                t=s+s;
                x=stoll(t);
                a.PB(x);
            }
        }
    }


    FORL(i1,1,10)
    {
        FORL(i2,0,10)
        {
            FORL(i3,0,10)
            {
                FORL(i4,0,10)
                {
                    s=('0'+i1);
                    s+=('0'+i2);
                    s+=('0'+i3);
                    s+=('0'+i4);
                    t=s+s;
                    x=stoll(t);
                    a.PB(x);
                }
            }
        }
    }


    FORL(i1,1,10)
    {
        FORL(i2,0,10)
        {
            FORL(i3,0,10)
            {
                FORL(i4,0,10)
                {
                    FORL(i5,0,10)
                    {
                        s=('0'+i1);
                        s+=('0'+i2);
                        s+=('0'+i3);
                        s+=('0'+i4);
                        s+=('0'+i5);
                        t=s+s;
                        x=stoll(t);
                        a.PB(x);
                    }
                }
            }    
        }
    }

    FORL(i1,1,10)
    {
        FORL(i2,0,10)
        {
            FORL(i3,0,10)
            {
                FORL(i4,0,10)
                {
                    FORL(i5,0,10)
                    {
                        FORL(i6,0,10)
                        {
                            s=('0'+i1);
                            s+=('0'+i2);
                            s+=('0'+i3);
                            s+=('0'+i4);
                            s+=('0'+i5);
                            s+=('0'+i6);
                            t=s+s;
                            x=stoll(t);
                            a.PB(x);
                        }
                    }
                }
            }    
        }
    }
    sort(a.begin(), a.end());
    // pr2(n,a.size())
    // debugv(a)
    int it=upper_bound(a.begin(), a.end(),n)-a.begin();
    cout<<it<<"\n";
}

int main() 
{
    by_ANIKET
    ll T=1,t=0;
    // cin>>T;
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
1
S2(S3(ES)SE4(SE)6(2(NW))SE)SSEE    */