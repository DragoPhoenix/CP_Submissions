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
	int n,m,d,t=0,k=0,x=0,y=0,z=0,a1,a2,a3,a4,a5,var=1;//,f=INF;
	cin>>n;
	vi a(2*n);
	m=2*n;
	// vi fq(1000005,0);//,fq2(2000005,0);//try map
	// vector <pair<ll,pi>> b;
	map <int,int> mp,mpt;
	set <int> st,stt;
	FOR(i,m){cin>>a[i];mp[a[i]]++;st.insert(a[i]);z=max(z,a[i]);}
	Sort(a);
	// z=a[m-1];
	// st.erase(z);
	mp[z]--;
	if(!mp[z])
		st.erase(z);
	else
		pr1(mp[z])
	FOR(i,m)
	{
		if(!mp[a[i]])continue;
		stt=st;
		mpt=mp;
		vector <pi> ans1;
		ans1.PB({z,a[i]});
		mp[a[i]]--;
		if(!mp[a[i]])
			st.erase(a[i]);
		k=z;
		while(ans1.size()!=n)
		{
			// pr1(a.size())
			x=*st.rbegin();
			while(!mp[x])
			{
				st.erase(x);
				x=*st.rbegin();
			}
			y=k-x;
			if(st.find(y)!=st.end()&&mp[y]>0&&x!=y)
			{
				// pr2(x,y)
				// pr2(mp[x],mp[y])
				ans1.PB({x,y});
				k=x;
				mp[x]--;
				if(!mp[x])
				st.erase(x);
				mp[y]--;
				if(!mp[y])
				st.erase(y);
			}
			else if(st.find(y)!=st.end()&&x==y&&mp[x]>1)
			{
				ans1.PB({x,y});
				k=x;
				mp[x]--;
				if(!mp[x])
				st.erase(x);
				mp[y]--;
				if(!mp[y])
				st.erase(y);
			}
			else
				break;
		}
		if(ans1.size()==n)
		{
			yes
			cout<<ans1[0].F+ans1[0].S<<"\n";
			for(auto e:ans1)
			cout<<e.F<<" "<<e.S<<"\n";
			return;
		}
		mp=mpt;
		st=stt;

		// FORL(j,i+1,m)
		// {


			// if(mp.find(a[i]+a[j])==mp.end())
			// mp[a[i]+a[j]].PB({a[i],a[j]});
			// b.PB({a[i]+a[j],{a[i],a[j]}});
		// }
	}
	no
	return;
	// // for(auto e:b)
	// // {
	// // 	cout<<e.F<<" = "<<e.S.F<<" + "<<e.S.S<<"\n";
	// // }
	// x=a[m-1];
	// // m=b.size();
	
	// pi fr={0,0};
	// fr.F=x;
	// fq[x]--;
	// // ans.PB()
	// // for(auto it=mp)
	// // {
	// // 	for(auto e:(it->S))
	// // 	{
	// // 		// debugp(e)
	// // 		// cout<<e.F<<
	// // 	}
	// // }
	// // debugm(mp)
	// while(ans.size()!=n-1)
	// {
	// 	y=x;
	// 	pr1(x)
	// 	for(auto e=((int)mp[x].size())-1;e>=0;e--)
	// 	{
	// 		// pr1(e)
	// 		a1=mp[x][e].F;
	// 		a2=mp[x][e].S;
	// 		if(mp[x][e].F!=mp[x][e].S&&fq[mp[x][e].F]>0&&fq[mp[x][e].S]>0)
	// 		{
	// 			ans.PB({a1,a2});
	// 			// pr1("sel")
	// 			// debugp(e)
	// 			fq[a1]--;
	// 			fq[a2]--;
	// 			x=max(a1,a2);
	// 			break;
	// 		}
	// 		else if(a1==a2&&fq[a2]>1)
	// 		{
	// 			ans.PB({a1,a2});
	// 			fq[a1]-=2;
	// 			x=a1;
	// 			break;
	// 		}
	// 		else
	// 		{
	// 			pr2(a1,a2)
	// 			pr2(fq[a1],fq[a2])
				
	// 		}
	// 	}
	// 	if(x==y)
	// 	{
	// 	// 	for(auto e:ans)
	// 	// cout<<e.F<<" "<<e.S<<"\n";
	// 	// 	pr2(x,y)
	// 		no
	// 		return;
	// 	}
	// }
	// // pr1(x)
	// // rSort(b);
	// // FORR(i,m-1,0)
	// // {
	// // 	if(b[i].F==x&&fq[b[i].S.F]>0&&fq[b[i].S.S]>0&&b[i].S.F!=b[i].S.S)
	// // 	{
	// // 		ans.PB(b[i].S);
	// // 		x=max(b[i].S.F,b[i].S.S);
	// // 		fq[b[i].S.F]--;
	// // 		fq[b[i].S.S]--;
	// // 		// i=m;
	// // 	}
	// // 	else if(b[i].F==x&&b[i].S.F==b[i].S.S&&fq[b[i].S.F]>1)
	// // 	{
	// // 		ans.PB(b[i].S);
	// // 		x=max(b[i].S.F,b[i].S.S);
	// // 		fq[b[i].S.F]--;
	// // 		fq[b[i].S.S]--;
	// // 		// i=m;
	// // 	}
	// // 	// else //if(b[i].F==x)
	// // 	// {
	// // 	// 	pr3(b[i].F,fq[b[i].S.F],fq[b[i].S.S] )
	// // 	// }
	// // 	if(ans.size()==n-1)
	// // 		break;
	// // }
	// if(ans.size()!=n-1)
	// {
	// 	// for(auto e:ans)
	// 	// cout<<e.F<<" "<<e.S<<"\n";
	// 	no
	// 	return;
	// }
	// FOR(i,2*n)
	// if(fq[a[i]])
	// {
	// 	// pr1(a[i])
	// 	fr.S=a[i];
	// 	break;
	// }
	// yes
	// cout<<fr.F+fr.S<<"\n";
	// cout<<fr.F<<" "<<fr.S<<"\n";
	// for(auto e:ans)
	// 	cout<<e.F<<" "<<e.S<<"\n";
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
    