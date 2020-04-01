#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b? b : a)
#define min(a, b) ((a>b)?b:a)

#define MOD 1000000007

#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( int (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  int (a)=(b); (a)>=(c); (a)--)

#define INF 1000000000000000003

#define abs llabs
#define BOOST ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

#define Clear( a, b ) memset( a, b, sizeof( a ) )
#define run if(1)cout<<__LINE__<<endl;  

#define pr3(a,b,c) cout<<"var1="<<a<<"\n"<<"var2="<<b<<"\n"<<"var3="<<c<<"\n";
#define pr2(a,b) cout<<"var1="<<a<<"\n"<<"var2="<<b<<"\n";
#define pr1(a) cout<<"var1="<<a<<"\n";

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

void solve()
{
	ll n,m,d,k,z,c=0;
	cin>>n;
	m=n;
	int p[n+1]={0};
	p[0]=-1;
	FORL(i,1,n+1)
	{
		cin>>k;
		z=1;
		while(k--)
		{
			cin>>d;
			if(p[d]==0&&z)
			{
				p[d]=i;
				z=0;
				c++;
			}
		}
	}
	if(c==n)
	{
		cout<<"OPTIMAL";
		return;
	}
	int pr[n+1]={0};
	FORL(i,1,n+1)
	{
		pr[p[i]]++;
	}
	FORL(i,1,n+1)
	if(pr[i]==0)
	{
		z=i;break;
	}

	cout<<"IMPROVE\n";
	cout<<z<<" ";
	FORL(i,1,n+1)
	{
		if(p[i]==0)
		{
			z=i;
			break;
		}
	}
	cout<<z;
}

int main() 
{
	BOOST
	ll T=1,t=0;
	cin>>T;
	while(t++<T)
	{
		//cout<<"Case #"<<t<<":"<<' ';
        solve();
        cout<<'\n';
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
