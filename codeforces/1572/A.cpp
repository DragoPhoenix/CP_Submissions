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
vector <set<int>> adji, adjo;

vector<bool> bvis;

vi colour;
bool directed_cycle_check_dfs(int v)
{
    bvis[v] = true;// extra
    colour[v] = 1;
    for(auto e : adjo[v])
        if(colour[e] == 1)
            return true;
        else if(colour[e] == 0 && directed_cycle_check_dfs(e)) // 0 to only call for unvisited
            return true;

    colour[v] = 2;
    return false;
}

vi topo_order;
// vector<bool> bvis;
void topo_dfs(int v) 
{
    bvis[v] = true;
    for (auto u : adjo[v])
        if (!bvis[u])
            topo_dfs(u);
    
    topo_order.PB(v);
}

void topological_sort(ll n) 
{
    bvis.clear();
    bvis.resize(n, false);
    topo_order.clear();
    FOR(i, n)
        if (!bvis[i])
            topo_dfs(i);
    
    reverse(topo_order.begin(), topo_order.end());
}

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n;
    
    adji.clear();
    adji.resize(n);
    adjo.clear();
    adjo.resize(n);

    vector<vi> a(n);

    FOR(i, n)
    {
        cin >> k;
        FOR(j, k)
        {
            cin >> x;
            a[i].PB(x);
        }
    }

    FOR(i, n)
    {
        k = a[i].size();
        FOR(j, k)
        {
            adjo[a[i][j] - 1].insert(i);
            adji[i].insert(a[i][j] - 1);
        }
    }

    bvis.clear();
    bvis.resize(n, false);
    colour.clear();
    colour.resize(n, 0);
    FOR(i, n)
    {
        if(!bvis[i])
        {
            if(directed_cycle_check_dfs(i))
            {
                cout << "-1\n";
                return;
            }
        }
    }

    topo_order.clear();
    topological_sort(n);
    // debugv(topo_order)

    y = -1;
    bvis.clear();
    bvis.resize(n, false);
    vi zval(n, INF);
    z = 0;

    FOR(i, n)
    {
        // pr3(topo_order[i], y, z)
        // if(topo_order[i] > y)
        // {
        //     y = topo_order[i];
        //     zval[topo_order[i]] = z;
        //     continue;
        // }
        y = 0;
        x = 0;
        t = 0;
        a1 = a2 = 0;
        // pr1(topo_order[i])
        // debugs(adji[topo_order[i]])
        for(auto e : adji[topo_order[i]])
        {
            if(e > topo_order[i] && zval[e] >= z)// && e > topo_order[i])
            {
                z++;
                x = 1;
                break;
            }
            else if(e > topo_order[i])
            {
                // if(e > topo_order[i])
                    // t = 1;
                y = max(y, zval[e]);
                a1 = 1;
            }
            else
            {
                t = max(t, zval[e]);
                a2 = 1;
            }
        }
        // pr3(x, z, y)
        if(x)
            zval[topo_order[i]] = z;
        else
        {
            if(a1)
                zval[topo_order[i]] = max(y + 1, t);
            else if(a2)
                zval[topo_order[i]] = t;
            else if(adji[topo_order[i]].empty())
                zval[topo_order[i]] = 0;
            else
                zval[topo_order[i]] = z;
        }

        // debugv(zval)
        // pr2(topo_order[i], z)
        // pr1("\n")
    }
    cout << z + 1 << "\n";
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