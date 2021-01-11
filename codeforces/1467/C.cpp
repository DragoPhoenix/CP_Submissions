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

#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

#define Clear( a, b ) memset( a, b, sizeof( a ) )
#define run if(1)cout<<__LINE__<<endl;  

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
#define MP make_pair


inline long long  max3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  min3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

void print(std::vector<pi> &a,ll z,ll x)
{
	// pr1("yo")
	a[x-1].F*=-1;
	a[x-2].F*=-1;
	FOR(i,a.size())
	z+=a[i].F;
	cout<<z<<"\n";
}
void solve()
{
	ll n1,n2,n3,m,z=0,x=0,y=0;//,a1,a2,a3,a4,a5,ex,che,var,k;
	cin>>n1>>n2>>n3;
	vi a1(n1),a2(n2),a3(n3);
	std::vector<pi> a;
	FOR(i,n1){cin>>a1[i];a.PB({a1[i],1});}
	FOR(i,n2){cin>>a2[i];a.PB({a2[i],2});}
	FOR(i,n3){cin>>a3[i];a.PB({a3[i],3});}
	sort(a.rbegin(), a.rend());
	// for(auto it:a)
	// cout<<it.F<<" "<<it.S<<"\n";
	x=a.size();
	if(n1==1||n2==1||n3==1)
	{
		if(n1==n2&&n2==n3&&n1==1)
		{
			cout<<a[0].F+a[1].F-a[2].F<<"\n";
			return;
		}
		if(n1==n2&&n1==1)
		{
			ll arrsum=0;
			FOR(i,n3)arrsum+=a3[i];
			cout<<max3(arrsum+a1[0]-a2[0],arrsum-a1[0]+a2[0],-arrsum+a1[0]+a2[0])<<"\n";
			return;
		}

		if(n1==n3&&n1==1)
		{
			ll arrsum=0;
			FOR(i,n2)arrsum+=a2[i];
			cout<<max3(arrsum+a1[0]-a3[0],arrsum-a1[0]+a3[0],-arrsum+a1[0]+a3[0])<<"\n";
			return;
		}

		if(n3==n2&&n2==1)
		{
			ll arrsum=0;
			FOR(i,n1)arrsum+=a1[i];
			cout<<max3(arrsum+a3[0]-a2[0],arrsum-a3[0]+a2[0],-arrsum+a3[0]+a2[0])<<"\n";
			return;
		}
		if(n1==1)
		{
			FOR(i,a.size())
				z+=a[i].F;
			if(a[x-1].S==1||a[x-2].S==1)
			{
				cout<<z-2*a1[0]<<"\n";
				return;
			}
			if(a[x-1].S!=a[x-2].S)
			{
				if(a1[0]<=a[x-1].F+a[x-2].F)
					cout<<z-(2*a1[0])<<"\n";
				else
					cout<<z-(2*(a[x-1].F+a[x-2].F))<<"\n";
				return;
			}
		}
		if(n2==1)
		{
			FOR(i,a.size())
				z+=a[i].F;
			if(a[x-1].S==2||a[x-2].S==2)
			{
				cout<<z-2*a2[0]<<"\n";
				return;
			}
			if(a[x-1].S!=a[x-2].S)
			{
				if(a2[0]<=a[x-1].F+a[x-2].F)
					cout<<z-(2*a2[0])<<"\n";
				else
					cout<<z-(2*(a[x-1].F+a[x-2].F))<<"\n";
				return;
			}
		}
		if(n3==1)
		{
			FOR(i,a.size())
				z+=a[i].F;
			if(a[x-1].S==3||a[x-2].S==3)
			{
				cout<<z-2*a3[0]<<"\n";
				return;
			}
			if(a[x-1].S!=a[x-2].S)
			{
				if(a3[0]<=a[x-1].F+a[x-2].F)
					cout<<z-(2*a3[0])<<"\n";
				else
					cout<<z-(2*(a[x-1].F+a[x-2].F))<<"\n";
				return;
			}
		}
	}
	z=0;
	if(a[x-1].S!=a[x-2].S)
	{
		print(a,z,x);
		return;
	}
	else
	{
		y=a[x-1].S;
		// if(y==1&&a1.size()==2)
		// {
		// 	print(a,z,x);
		// 	return;
		// }
		// else if(y==2&&a2.size()==2)
		// {
		// 	print(a,z,x);
		// 	return;
		// }
		// else if(y==3&&a3.size()==2)
		// {
		// 	print(a,z,x);
		// 	return;
		// }
		ll arrsum=0,m1,m2=-1;
		if(y==1)
		{
			sort(a2.begin(), a2.end());
			sort(a3.begin(), a3.end());
			m1=min(a2[0],a3[0]);
			FOR(i,a1.size())arrsum+=a1[i];
			if(n2==1)
			{
				m2=a2[0];
			}
			else if(n3==1)
			{
				m2=a3[0];
			}
		}
		else if(y==2)
		{
			sort(a1.begin(), a1.end());
			sort(a3.begin(), a3.end());
			m1=min(a1[0],a3[0]);
			FOR(i,a2.size())arrsum+=a2[i];
			if(n1==1)
			{
				m2=a1[0];
			}
			else if(n3==1)
			{
				m2=a3[0];
			}
		}
		else if(y==3)
		{
			sort(a2.begin(), a2.end());
			sort(a1.begin(), a1.end());
			m1=min(a2[0],a1[0]);
			FOR(i,a3.size())arrsum+=a3[i];
			if(n2==1)
			{
				m2=a2[0];
			}
			else if(n1==1)
			{
				m2=a1[0];
			}			
		}
		else
			assert(0);
		FOR(i,a.size())
			z+=a[i].F;
		// pr3(z,arrsum,a[x-1].F)
		// pr2(m1,m2)
		if(m2==-1)
		if(arrsum<=m1+a[x-1].F)
			cout<<z-(2*arrsum)<<"\n";
		else
			cout<<z-(2*(m1+a[x-1].F))<<"\n";
		else
		{
			if(arrsum<=m1+a[x-1].F&&arrsum<=m2)
				cout<<z-(2*arrsum)<<"\n";
			else if(m1+a[x-1].F<=arrsum&&m1+a[x-1].F<=m2)
				cout<<z-(2*(m1+a[x-1].F))<<"\n";
			else
				cout<<z-(2*m2)<<"\n";

		}
	}
}

int main() 
{
	by_ANIKET
	ll T=1,t=0;
	// cin>>T;
	while(t++<T)
	{
		//cout<<"Case "<<t<<":"<<' ';
        solve();
        //cout<<'\n';
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