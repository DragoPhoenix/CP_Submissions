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

int main() 
{
	BOOST
	ll t,n,k;
	string a;
	cin>>a;
	vi o,z;
	n=a.length();
	FOR(i,n)
	{
		if(a[i]=='1')
			o.PB(i);
		else
			z.PB(i);
	}
	k=0;
	FOR(i,o.size())
	{
		if(i+6<o.size())
		{
			if(o[i+6]==o[i]+6)
				k=1;
		}
	}
	FOR(i,z.size())
	{
		if(i+6<z.size())
		{
			if(z[i+6]==z[i]+6)
				k=1;
		}
	}
	if(k)
		yes
	else
		no
}