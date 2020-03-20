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
#define mod 1e9+7
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( int (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  int (a)=(b); (a)>=(c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define POB pop_back


int main() 
{
	ll t,n,m,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n==m)
		{
			cout<<"0\n";
			continue;
		}
		else if(n>m)
		{
			if(n%2==m%2)
			{
				cout<<"1\n";
				continue;
			}
			else
			{
				cout<<"2\n";
				continue;
			}
		}
		else
		{
			if(n%2!=m%2)
			{
				cout<<"1\n";
				continue;
			}
			else
			{
				cout<<"2\n";
				continue;
			}
		}
	}
}
