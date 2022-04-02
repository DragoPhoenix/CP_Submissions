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

    cin >> n;
    
    vi a(n);
    FOR(i, n) cin >> a[i];

    // vector<vi> co(n, vi(5, 0));
    // vi vp(n, 0);

    // FOR(i, n)
    // {
    //     // x = a[i] + 2;
    //     // if(i > 0)
    //     // {
    //     //     co[i] = co[i-1];
    //     //     co[i][x]++;
    //     // }
    //     // else
    //     //     co[i][x]++;
    //     // vp[i] = (co[i][0] + co[i][1]) % 2;
    // }

    // debugv2(co)
    // debugv(vp)

    vi b;
    FOR(i, n)
    {
        if(!a[i])
            b.PB(i);
    }

    if(b.empty())
    {
        x = 0;
        FOR(i, n)
        if(a[i] < 0)
            x++;
        if(x % 2)
        {
            y = 0;
            FOR(i, n)
            {
                if(a[i] == 2 || a[i] == -2)
                    y++;
                if(a[i] < 0)
                {
                    a1 = i + 1;
                    break;
                }
            }

            a3 = 0;
            FORR(i, n - 1, 0)
            {
                if(a[i] == 2 || a[i] == -2)
                    a3++;
                if(a[i] < 0)
                {
                    a2 = n - i;
                    break;
                }
            }
            if(y < a3)
                cout << a1 << " " << "0\n";
            else
                cout << "0 " << a2 << "\n";
        }
        else
            cout << "0 0\n";
        return;
    }
    
    x = 0;
    y = 0;
    z = 0;

    if(b.back() != n - 1)
        b.PB(n);
    if(b[0] != 0)
        b.PB(-1);    
    
    m = b.size();
    sort(b.begin(), b.end());
    // debugv(b)
    FORL(i, 1, m)
    {
        ll l = b[i-1];
        ll r = b[i];
        a1 = a2 = 0;
        FORL(i, l + 1, r)
        {
            if(abs(a[i]) == 2)
                a1++;
            if(a[i] < 0)
                a2++;
        }

        if(a2 % 2)
        {
            k = 0;
            FORL(i, l + 1, r)
            {
                if(a[i] == 2 || a[i] == -2)
                    k++;
                if(a[i] < 0)
                {
                    a4 = i;
                    break;
                }
            }

            a3 = 0;
            FORR(i, r - 1, l + 1)
            {
                if(a[i] == 2 || a[i] == -2)
                    a3++;
                if(a[i] < 0)
                {
                    a5 = i;
                    break;
                }
            }
            
            if(k < a3)
            {
                if(a1 - k > z)
                {
                    z = a1 - k;
                    x = a4 + 1;
                    y = n - r;
                }
            }
            else
            {
                if(a1 - a3 > z)
                {
                    z = a1 - a3;
                    x = l + 1;
                    y = n - a5;
                }
            }
        }
        else
        {
            if(a1 > z)
            {
                z = a1;
                x = l + 1;
                y = n - r;
            }
        }
    }

    if(z == 0)
        x = n;
    cout << x << " " << y << "\n";
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