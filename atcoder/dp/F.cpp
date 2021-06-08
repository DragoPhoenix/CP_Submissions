//Hey stalker :)
#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

#define MOD 1000000007

#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define all(v)                      (v).begin(),(v).end()
#define Sort(v)                     sort(all((v)));
#define rSort(v)                    sort((v).rbegin(),(v).rend());
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL);

#define no cout<<"No\n";
#define yes cout<<"Yes\n";

#define Clear( a, b ) memset( a, b, sizeof( a ) )
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

const ll N=3e3+5;
string s, t;
ll n, m;
int vp[N+2][N+2];

int memo(int i, int j)
{
    // pr3(i, j ,vp[i][j])
    if(vp[i][j] != -1)
        return vp[i][j];
    if(i == 0)
    {
        if(j == 0)
        {
            if(s[i] == t[j])
                return vp[i][j] = 1;
            else
                return vp[i][j] = 0;
        }
        else
        {
            if(s[i] == t[j])
                return vp[i][j] = 1;
            else
                return vp[i][j] = memo(i, j-1);
        }
    }
    else if(j == 0)
    {
        if(s[i] == t[j])
            return vp[i][j] = 1;
        else
            return vp[i][j] = memo(i-1, j);
    }
    if(s[i] == t[j])
        return vp[i][j] = max3(1 + memo(i-1, j-1), memo(i-1, j), memo(i, j-1));
    else
        return vp[i][j] = max(memo(i-1, j), memo(i, j-1));
}

void solve()
{
    ll nn, mm, tt = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string a;    

    cin >> s >> t;

    n = s.length();
    m = t.length();

    FOR(i, n+2)
        FOR(j, m+2)
            vp[i][j] = -1;


    // cout << memo(n-1, m-1) << "\n";
   

    if(memo(n-1, m-1) == 0)
        return;

    // debuga2(vp,n+2,m+2)
    int i = n-1, j = m-1;

    while(vp[i][j] != 0 && i >= 1 && j >= 1)
    {
        // pr2(i, j)
        if(s[i] == t[j])
        {
            a += s[i];
            i--;
            j--;
        }
        else if(vp[i][j-1] > vp[i-1][j])
            j--;
        else //if(vp[i-1][j-1] < vp[i][j])
            i--;
        // else
        // {
        //     assert(0);
        // }
    }
    // pr3(i, j, a)
    if(vp[i][j] != 0 && !i)
        a += s[i];
    else if(vp[i][j] != 0 && !j)
        a += t[j];
    
    reverse(a.begin(), a.end());
    
    cout << a << "\n";
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