//Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 998244353

#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL);

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

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

const ll N = 4e5+5;
ll M = 1e6+10;

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n >> x;

    vi a(n);
    FOR(i, n)
    	cin >> a[i];

    set <int> st;
    FOR(i, M)
	    st.insert(i);

	FOR(i, n)
	{
		// pr2(i, a[i])
		// debugs(st)
		y = *st.begin();
		if(y % x <= a[i] % x)
			t = a[i] % x - y % x;
		else
			t = a[i] % x - y % x + x;
		// pr1(t)
		if(t == 0)
		{
			st.erase(y);
			cout << *st.begin() << "\n";
		}
		else
		{
			ll l = 0, r = (N - y - t) / x + 2;
			while(r - l >= 3)
			{
				m = l + (r - l) / 2;
				if(st.find(y + t + m * x) != st.end())
					r = m - 1;
				else
					l = m;
			}
			// pr2(l, r)
			if(st.find(y + t + l * x) != st.end())
			{
				// pr1(y + t + l * x)
				st.erase(y + t + l * x);
			}
			else
			FORL(i, l, r + 1)
			{
				if(st.find(y + t + (i + 1) * x) != st.end())
				{
					// pr2(i + 1, y + t + (i + 1) * x	)
					st.erase(y + t + (i + 1) * x);
					break;
				}
			}
			cout << *st.begin() << "\n";
		}
	}
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
