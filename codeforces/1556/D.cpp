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

ll query(int i, int j, int op)
{
    ll x = 1;
    if(op)
    {
        cout << "and " << i << " " << j << endl;
        cin >> x;
        return x;
    }
    cout << "or " << i << " " << j << endl;
    cin >> x;
    return x;
    
}
void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0;
    ll a1, a2, a3, o1, o2, o3, x1, x2, x3, s1, s2, s3;

    cin >> n >> k;
    
    vi a(n + 1, 0);

    if(n % 3 == 0)
    {
        FORL(i, 1, n + 1)
        {
            o1 = query(i, i + 1, 0);
            o2 = query(i + 1, i + 2, 0);
            o3 = query(i, i + 2, 0);

            a1 = query(i, i + 1, 1);
            a2 = query(i + 1, i + 2, 1);
            a3 = query(i, i + 2, 1);

            x1 = o1 - a1;
            x2 = o2 - a2;
            x3 = o3 - a3;

            s1 = x1 + 2 * a1;
            s2 = x2 + 2 * a2;
            s3 = x3 + 2 * a3;
            
            a[i] = (s1 - s2 + s3) / 2;
            a[i+2] = s3 - a[i];
            a[i+1] = s2 - a[i+2];

            i = i + 2;
        }
    }
    else if(n % 3 == 1)
    {
        FORL(i, 1, n + 1)
        {
            if(i == n)
            {
                o1 = query(i, i - 1, 0);
                a1 = query(i, i - 1, 1);
                x1 = o1 - a1;
                s1 = x1 + 2 * a1;
                a[i] = s1 - a[i-1];
                break;
            }

            o1 = query(i, i + 1, 0);
            o2 = query(i + 1, i + 2, 0);
            o3 = query(i, i + 2, 0);

            a1 = query(i, i + 1, 1);
            a2 = query(i + 1, i + 2, 1);
            a3 = query(i, i + 2, 1);

            x1 = o1 - a1;
            x2 = o2 - a2;
            x3 = o3 - a3;

            s1 = x1 + 2 * a1;
            s2 = x2 + 2 * a2;
            s3 = x3 + 2 * a3;
            
            a[i] = (s1 - s2 + s3) / 2;
            a[i+2] = s3 - a[i];
            a[i+1] = s2 - a[i+2];

            i = i + 2;
        }
    }
    else
    {
        FORL(i, 1, n + 1)
        {
            if(i == n - 1)
            {
                i--;
                o1 = query(i, i + 1, 0);
                o2 = query(i + 1, i + 2, 0);

                a1 = query(i, i + 1, 1);
                a2 = query(i + 1, i + 2, 1);

                x1 = o1 - a1;
                x2 = o2 - a2;

                s1 = x1 + 2 * a1;
                s2 = x2 + 2 * a2;

                a[i+1] = s1 - a[i];
                a[i+2] = s2 - a[i+1];
                break;
            }

            o1 = query(i, i + 1, 0);
            o2 = query(i + 1, i + 2, 0);
            o3 = query(i, i + 2, 0);

            a1 = query(i, i + 1, 1);
            a2 = query(i + 1, i + 2, 1);
            a3 = query(i, i + 2, 1);

            x1 = o1 - a1;
            x2 = o2 - a2;
            x3 = o3 - a3;

            s1 = x1 + 2 * a1;
            s2 = x2 + 2 * a2;
            s3 = x3 + 2 * a3;
            
            a[i] = (s1 - s2 + s3) / 2;
            a[i+2] = s3 - a[i];
            a[i+1] = s2 - a[i+2];

            i = i + 2;
        }
    }

    // debugv(a)

    sort(a.begin(), a.end());

    cout << "finish " << a[k] << "\n";
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