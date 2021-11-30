//Hey stalker :)
#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b? b : a)
#define min(a, b) ((a>b)?b:a)

#define MOD 998244353 

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

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

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

const ll N=1e5+5;
vector<vector<int>> adj(N); 
vi vis(N), h(N), p(N);
vi level_sum(N);
ll n;
vi sub_tree_popn(N);
vector <pi> checker(N);
int flag = 1;

int bfs()
{
	// mp.clear();
	int v = 1;
	pi pr;
	queue <pi> q;
	q.push({v,0});
	vis[v] = 1;
	int prev_i = 0, prev;
	int cur_i = 0, cur;
	while(!q.empty())
	{
		pr = q.front();
		v = pr.F;
		q.pop();
		level_sum[pr.S] += h[v];
		for(auto e:adj[v])
		{
			if(!vis[e])
				q.push({e, pr.S+1});
		}
	}
	FOR(i,n-1)
	{
		if(level_sum[i]<level_sum[i+1])
			return 0;
	}
	return 1;
}

int calc_sub_popn(int v, int pr)
{
	// pr1(v)
	if(sub_tree_popn[v] != -1)
		return sub_tree_popn[v];
	int z = 0;
	for(auto e:adj[v])
	{
		if(e == pr) continue;
		z+=calc_sub_popn(e, v);
	}
	sub_tree_popn[v] = z + p[v];
	return sub_tree_popn[v];
}
void checkers(int p, int v) // wrong??
{
	int x=0,y=0,X = checker[v].F, Y = checker[v].S;
	for(auto e : adj[v])
	{
		if(e == p) continue;
		x+=checker[e].F;
		y+=checker[e].S;
		if(adj[e].size()!=1)
		checkers(v, e);
	}
	if(x>X )
	{
		// pr1(v)
		// pr2(x,X)
		// pr2(y,Y)
		flag = 0;
	}
}

void solve()
{
    ll m,t=0,k=0,x=0,y=0,z=0,a1,a2,a3,a4,a5,var=1,f=INF;
    flag = 1;
    cin >> n >> m;
    FOR(i, n)
    {
    	checker[i+1] = {0,0};
    	sub_tree_popn[i+1] = -1;
    	level_sum[i] = 0;
    	cin >> p[i+1];
    	adj[i+1].clear();
    	vis[i+1] = 0;
 	}
 	level_sum[n] = 0;
 	FOR(i, n) cin >> h[i+1];
    FOR(i, n-1)
    {
    	cin >> x >> y;
    	adj[x].PB(y);
    	adj[y].PB(x);
    }
    // pr1("here")
    FORL(i, 2, n+1)
    {
    	if(adj[i].size() == 1)
    	{
    		sub_tree_popn[i] = p[i];
    	}
    }
    // pr1("i")
    calc_sub_popn(1, 0);
    // pr2(sub_tree_popn[1], m)
    // debuga(sub_tree_popn,10)
    assert(sub_tree_popn[1] == m);
    
    if(flag  && (m + h[1]) % 2 == 0 && m+h[1] >= 0)
    {
    	x = (m+h[1])/2;
    	y = m - x;
    	checker[1] = {x, y};
    	if(x<0 || y<0 || x>m)
    	{
    		no
    		return;
    	}
    	FORL(i, 2, n+1)
    	{
    		if( (sub_tree_popn[i] + h[i]) % 2 != 0 || sub_tree_popn[i] + h[i] < 0)
    		{
    			no
    			return;
    		}

    		x = (sub_tree_popn[i] + h[i])/2;
	    	y = sub_tree_popn[i] - x;
	    	if(x<0 || y<0 || x>sub_tree_popn[i])
	    	{
	    		no
	    		return;
	    	}
    		checker[i] = {x, y};
    	}
    	a1 = 0;
    	FORL(i, 2, n+1)
    	{
    		a1 += checker[i].F;
    	}
    	// pr1(flag)
    	checkers(1,1);
    	// pr2(a1,checker[1].F)
    	// pr1(flag)
    	if(flag)
    	yes
    	else
    		no
    }
    else
    	no
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