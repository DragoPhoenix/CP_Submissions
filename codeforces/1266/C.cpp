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
// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b)  (x/gcd(x,y))*y
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
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int j = 0; j< (v).size(); j++) cerr<<v[j]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[i].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
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

const ll N=1e3+5;
vi spf(N,1);
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

void handle(ll n, ll m)
{
    if(n == m)
    {
        cout << "0\n";
        exit(0);
    }
    ll k = 2;
    FOR(i, n)
    {
        FOR(j, m)
        {
            cout << k++ << " ";
        }
        cout << "\n";
    }
    exit(0);
}
void spfS()
{
    spf[2] = 2;
    for(int i = 3; i < N; i++)
    {
        for(int j = 2; j*j <= i; j++)
        {
            if(i % j  == 0)
            {
                spf[i] = j;
                break;
            }
        }
        if(spf[i] == 1)
            spf[i] = i;
    }
}
void solve()
{
    ll n, m, tt=0, k=0, x=0, y=0, z=0, a1, a2, a3, a4, a5, var=1, f=INF;    
    
    cin >> n >> m;
    if(n>m)
    {
        tt = 1;
        swap(n,m);
    }
    if(n == 1 || m == 1)
    {
        handle(n, m);
    }
    vi pr = {2, 3, 5, 7, 11, 13 };
    FORL(i, 17, N * 4)
    {
        x = 1;
        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                x = 0;
                break;
            }
        }
        if(x)
            pr.PB(i);
        if(pr.size() == 501)
            break;
    }
    // sort(pr.begin(), pr.end());
    set <int> st;
    FORL(i, 2, 1002)
    st.insert(i);

    int a[n][m];
    FOR(i, n)
    {
        FOR(j, m)
            a[i][j] = -1;
    }

    FOR(i,m)
    {
        if(pr[i] > n + m)
        {
            k = i;
            break;
        }
        a[0][i] = pr[i];
        st.erase(pr[i]);
        k = i+1;
    }
    // debuga2(a,n,m)
    FORL(i, k, m)
    {
        a[0][i] = *st.begin();
        st.erase(a[0][i]);
    }
    // debuga2(a,n,m)

    FORL(i, 1, n)
    {
        z = *st.begin();
        st.erase(z);
        y = spf[z];
        if(y == z)
        {
            assert(0);
            // a[i][0] = z;
        }
        else
        {
            auto it = lower_bound(pr.begin(), pr.end(), y) - pr.begin();
            // pr2(it, y)
            a[i][it] = z;
        }
        FORL(j, 0, m)
        {
            if(a[i][j] == -1)
            a[i][j] = lcm(z, a[0][j]);
            // a[i][j] = lcm(a[i-1][j], a[i][j-1]);
        }
    }
    // pr1("1")
    vi checker;
    FOR(i, n)
    {
        x = a[i][0];
        FORL(j, 1, m)
        {
            x = gcd(x, a[i][j]);
        }
        checker.PB(x);
    }
    FOR(i, m)
    {
        x = a[0][i];
        FORL(j, 1, n)
            x = gcd(x, a[j][i]);
        checker.PB(x);
    }
    if(checker.size() != n + m)
    {
        cout << "0\n";
        return;
    }
    if(!tt)
    FOR(i, n)
    {
        FOR(j, m)
            cout << a[i][j] << " ";
        cout << "\n";   
    }
    else
    {
        FOR(i, m)
        {
            FOR(j, n)
                cout << a[j][i] << " ";
            cout << "\n";   
        }
    }
}

int main() 
{
    by_ANIKET
    ll T = 1,t = 0;
    // cin >> T;
    spfS();
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