#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

#define MOD 1000000007

#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs

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

const ll N=2e5+5;

void solve()
{
    ll n, m, t = 0, k = 0, x = -1, y = -1, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n >> m;
    
    char a[n][m];

    FOR(i, n) 
        FOR(j, m)
        {
            cin >> a[i][j];
            if(a[i][j] == '.')
                z++;
        }
    // debuga2(a, n, m)
    if(z == n * m)
    {
        a[0][0] = 'R';
    }
    FOR(i, n) 
        FOR(j, m)
        {
            // pr2(i, j)
            // debuga2(a, n, m)
            if(a[i][j] == 'R')
            {
                // if(i - 1 >= 0)
                // {
                //     if(a[i-1][j] == 'R')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i-1][j] == '.')
                //         a[i-1][j] = 'W';
                // }
                // if(i + 1 < n)
                // {
                //     if(a[i+1][j] == 'R')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i+1][j] == '.')
                //         a[i+1][j] = 'W';
                // }
                // if(j - 1 >= 0)
                // {
                //     if(a[i][j-1] == 'R')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i][j-1] == '.')
                //         a[i][j-1] = 'W';
                // }
                // if(j + 1 < m)
                // {
                //     if(a[i][j+1] == 'R')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i][j+1] == '.')
                //         a[i][j+1] = 'W';
                // }
                x = i + j;
                break;
            }
            else if(a[i][j] == 'W')
            {
                // if(i - 1 >= 0)
                // {
                //     if(a[i-1][j] == 'W')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i-1][j] == '.')
                //         a[i-1][j] = 'R';
                // }
                // if(i + 1 < n)
                // {
                //     if(a[i+1][j] == 'W')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i+1][j] == '.')
                //         a[i+1][j] = 'R';
                // }
                // if(j - 1 >= 0)
                // {
                //     if(a[i][j-1] == 'W')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i][j-1] == '.')
                //         a[i][j-1] = 'R';
                // }
                // if(j + 1 < m)
                // {
                //     if(a[i][j+1] == 'W')
                //     {
                //         no
                //         return;
                //     }
                //     else if(a[i][j+1] == '.')
                //         a[i][j+1] = 'R';
                // }
                y = i + j;
                break;
            }
        }
    char c1,c2;
    if(y == -1)
    c1 = 'R', c2 = 'W', z = x;
    else
        c1 = 'W', c2 = 'R', z = y;
    FOR(i, n) 
        FOR(j, m)
        {
            if((i+j)%2 == z % 2)
            {
                if(a[i][j] == '.')
                    a[i][j] = c1;
                else if(a[i][j] != c1)
                {
                    no
                    return;
                }
            }
            else
            {
                if(a[i][j] == '.')
                    a[i][j] = c2;
                else if(a[i][j] != c2)
                {
                    no
                    return;
                }
            }
        }

    yes
    FOR(i, n)
    {
        FOR(j, m)
        cout << a[i][j];
        cout << "\n";
    }


}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1,t = 0;
    cin >> T;
    while(t++ < T)
      solve();
}
