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

vector<vi> adj(300005);
vi v(300005);
vector<bool> vis(300005);

ll powm(ll x,ll y,ll m=MOD)
{
	x=x%m;
	ll res=1;
	while(y)
	{
		if(y&1)
			res=(res*x)%m;
		y=y>>1;
		x=x*x;
		x%=m;
	}
	return res;
}

pi bfs(int i)
{
	queue<int> q;
	q.push(i);
	vis[i] = true;
	v[i] = 2;
	int c = 0;
	pi p={0,1};

	while(!q.empty())
	{
		int j = q.front();
		c++;
		q.pop();
		for(auto e : adj[j])
		{
			if(!vis[e])
			{
				vis[e] = true;
				v[e] = 3 - v[j];
				if(v[e] == 1)
					p.F++;
				else
					p.S++;
				q.push(e);
			}
			else
			{
				if(v[e] != 3 - v[j])
					return {0,0};
			}
		}
	}
	if(c==1)
		// v[i] = 3;
	return {0,3};
	return p;
}

void solve()
{
    ll n,m,t=0,k=0,x=0,y=0,z=0,a1,a2,a3,a4,a5,var=1,f=INF;
    cin >> n >> m;
	
	// adj.clear();
	FORL(i,1,n+1)
	{
		adj[i].clear();
		v[i] = 0;
		vis[i] = false;
	}
	
	FOR(i, m)
	{
		cin>>x>>y;
		adj[x].PB(y);
		adj[y].PB(x);
	}

	// FORL(i,1,n+1)
	// debugv(adj[i])
	z=1;
	FORL(i,1,n+1)
	{
		if(!vis[i])
		{
			pi ai = bfs(i);
			// debugp(ai)
			// pr1(z)
			if(ai.F == 0 && ai.S == 0)
			{
				cout<<"0\n";
				return;
			}
			else if(ai.F == 0 && ai.S== 3)
			{
				z = (z*3)%MOD;
			}
			else
			{
				z = (z * ( (powm(2,ai.F) + powm(2,ai.S))%MOD))%MOD;
			}
		}
	}
	cout<<z<<"\n";
	return;
	// debugv(v)
	// if()
	// {
		ll th = 0,tw = 0, o = 0;
		FORL(i, 1, n+1)
		{
			if(v[i]==3)
				th++;
			else if(v[i] == 2)
				tw++;
			else if(v[i] == 1)
			{
				// pr1(v[i])
				o++;
			}
			else assert(0);
		}
		// pr3(o,tw,th)
		if(o == 0 && o == tw)
		{
			cout<<powm(3,th)<<"\n";
			return;
		}
		x = (powm(2,tw)*powm(3,th))%MOD;
		y = (powm(2,o)*powm(3,th))%MOD;
		// pr2(x,y)
		z = (x + y) % MOD;
		cout << z << "\n";
		// pr1(powm(3,100000))
	// }
	// else
	// 	cout<<"0\n";

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
