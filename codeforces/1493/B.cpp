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

void solve()
{
	ll n,m,h,k=0,x=0,y=0,a1,a2,a3,a4,a5,var=1,f=INF;
	cin>>h>>m;
	string t;
	cin>>t;
	string hs,ms;
	string mir_h="00",mir_m="00";
	hs=t.substr(0,2);
	ms=t.substr(3,2);
	x=stoi(hs);
	y=stoi(ms);
	while(x!=h)
	{
		// pr2(x,y)
		// pr2(hs,ms)
		//assert
		if(hs[0]=='0'||hs[0]=='1'||hs[0]=='8')
			mir_m[1]=hs[0];
		else if(hs[0]=='2')
			mir_m[1]='5';
		else if(hs[0]=='5')
			mir_m[1]='2';
		else
		{
			//increment
			y++;
			if(y==m)
			{
				y=0;
				x++;
			}
			hs=to_string(x);
			if(x<10)
			{
				hs='0'+hs;
			}
			ms=to_string(y);
			if(y<10)
				ms='0'+ms;
			continue;
		}


		if(hs[1]=='0'||hs[1]=='1'||hs[1]=='8')
			mir_m[0]=hs[1];
		else if(hs[1]=='2')
			mir_m[0]='5';
		else if(hs[1]=='5')
			mir_m[0]='2';
		else
		{
			//increment
			y++;
			if(y==m)
			{
				y=0;
				x++;
			}
			hs=to_string(x);
			if(x<10)
			{
				hs='0'+hs;
			}
			ms=to_string(y);
			if(y<10)
				ms='0'+ms;
			continue;
		}


		if(ms[0]=='0'||ms[0]=='1'||ms[0]=='8')
			mir_h[1]=ms[0];
		else if(ms[0]=='2')
			mir_h[1]='5';
		else if(ms[0]=='5')
			mir_h[1]='2';
		else
		{
			y++;
			if(y==m)
			{
				y=0;
				x++;
			}
			hs=to_string(x);
			if(x<10)
			{
				hs='0'+hs;
			}
			ms=to_string(y);
			if(y<10)
				ms='0'+ms;
			continue;
		}

		if(ms[1]=='0'||ms[1]=='1'||ms[1]=='8')
			mir_h[0]=ms[1];
		else if(ms[1]=='2')
			mir_h[0]='5';
		else if(ms[1]=='5')
			mir_h[0]='2';
		else
		{
			y++;
			if(y==m)
			{
				y=0;
				x++;
			}
			hs=to_string(x);
			if(x<10)
			{
				hs='0'+hs;
			}
			ms=to_string(y);
			if(y<10)
				ms='0'+ms;
			continue;
		}
		// pr1("IMAGE-")
		// pr2(mir_h,mir_m)

		if(stoi(mir_h)<h&&stoi(mir_m)<m)
		{
			cout<<hs<<":"<<ms<<"\n";
			return;
		}
		else
		{
			y++;
			if(y==m)
			{
				y=0;
				x++;
			}
			hs=to_string(x);
			if(x<10)
			{
				hs='0'+hs;
			}
			ms=to_string(y);
			if(y<10)
				ms='0'+ms;
		}
	}
	cout<<"00:00\n";
}
int main() 
{
	// #ifndef ONLINE_JUDGE
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	// freopen("Error.txt","w",stderr);
	// #endif
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
    