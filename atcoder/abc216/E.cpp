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

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s; 

    cin >> n >> k;

    vi a(n);
    FOR(i, n)
    cin >> a[i];

    if(n == 1)
    {
        z = a[0] * (a[0] + 1) / 2;
        if(k < a[0])
        {
            x = a[0] - k;
            y = x * (x + 1) / 2;
            z -= y;   
        }
        cout << z << "\n";
        return;
    }
    sort(a.begin(), a.end());

    vi b(n + 1, 0);

    y = 1;
    t = 0;
    FORR(i, n - 2, 0)
    {
        x = a[i + 1] - a[i];
        z += x * y++;
        if(z > k)
        {
            t = 1;
            x = i + 1;
            break;
        }
    }
    if(!t)
    {
        t = 0;
        FOR(i, n)
        t += a[i];
        if(t > k)
        {
            // z = 0;
            // x = a[1] * (a[1] + 1) / 2 - (a[0] * (a[0] + 1) / 2);
            // z += x;
            // // pr1(z)
            // k -= a[1] - a[0];
            // a2 = k / 2;
            // y = a[0] * (a[0] + 1) / 2;
            // z += (y - ((a[0] - a2) * (a[0] - a2 + 1) / 2)) * 2;
            
            // k = k - a2 * 2;

            // z += k * (a[0] - a2);

            // cout << z << "\n";
            // return;


            x = 0;
            y = a[x] * (a[x] + 1) / 2;
            z = 0;
            // pr2(x, y)

            FORL(i, x + 1, n)
            {
                // pr2(a[i], a[x])
                z += ((a[i] * (a[i] + 1) / 2) - y);
                k -= (a[i] - a[x]);
            }

            // pr2(z, k)

            a1 = n - x;
            a2 = k / a1;

            // pr2(a1, a2)
            z += (y - ((a[x] - a2) * (a[x] - a2 + 1) / 2)) * a1;

            // pr1(z)
            k = k - a2 * a1;

            z += k * (a[x] - a2);

            cout << z << "\n";
            return;
        }
        z = 0;
        FOR(i, n)
        {
            z += a[i] * (a[i] + 1) / 2;
        }
        cout << z << "\n";
        return;
    }
    y = a[x] * (a[x] + 1) / 2;
    z = 0;
    // pr2(x, y)

    FORL(i, x + 1, n)
    {
        // pr2(a[i], a[x])
        z += ((a[i] * (a[i] + 1) / 2) - y);
        k -= (a[i] - a[x]);
    }

    // pr2(z, k)

    a1 = n - x;
    a2 = k / a1;

    // pr2(a1, a2)
    z += (y - ((a[x] - a2) * (a[x] - a2 + 1) / 2)) * a1;

    // pr1(z)
    k = k - a2 * a1;

    z += k * (a[x] - a2);

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