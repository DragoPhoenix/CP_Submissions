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
	ll a,b,c,d,x1,x2,y1,y2,x,y;
	cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
	x=x-a+b;
	y=y-c+d;
	if(x1==x2)
	{
		if(a==b&&a==0);
		else
		{
			no
			return;
		}
	}
	if(y1==y2)
	{
		if(c==d&&c==0);
		else
		{
			no
			return;
		}
	}
	if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
		yes
	else
		no
}

int main() 
{
	BOOST
	ll t;

	cin>>t;
	
	
	while(t--)
	{
		solve();
	}
}
