#include <iostream>
#include<utility>
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
	ll n,m,d,k,z,c=0,x,y;
	cin>>n;
	ll a[n+1][n+1];
	//k=((n*n)-n)/2;
	//pair <pair<int,int>,int> u[k],x,y;

	FORL(i,1,n+1)
	{
		FORL(j,1,n+1)
		{
			cin>>k;
			a[i][j]=k;
		}
	}
	cin>>k;
	m=k;
	while(k--)
	{
		cin>>d>>z>>x;
		a[d][z]=min(x,a[d][z]);
		a[z][d]=a[d][z];
		FORL(i,1,n+1)
		{
			//if(i==1)
				//pr3(a[i][d],a[d][z],a[i][z])
			FORL(j,1,n+1)
			if(a[i][d]+a[d][z]+a[z][j]<a[i][j])
			{
				//pr2(i,z);
				a[i][j]=a[i][d]+a[d][z]+a[z][j];
				a[j][i]=a[i][j];
			}
			FORL(j,1,n+1)
			if(a[i][z]+a[z][d]+a[d][j]<a[i][j])
			{
				//pr2(i,z);
				a[i][j]=a[i][z]+a[z][d]+a[d][j];
				a[j][i]=a[i][j];
			}
		}/*
		d=y;
		z=x;
		FORL(i,1,n+1)
		{
			if(a[i][d]+a[d][z]<a[i][z])
			{
				a[i][z]=a[i][d]+a[d][z];
				a[z][i]=a[i][z];
			}
		}*/
		c=0;
		FORL(i,1,n+1)
		{
			FORL(j,i+1,n+1)
			{
				c+=a[i][j];
			}
		}
		cout<<c<<" ";
	}
}

int main() 
{
	BOOST
	ll T=1,t=0;
	//cin>>T;
	while(t++<T)
	{
		//cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
	}
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
