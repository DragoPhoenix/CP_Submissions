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
typedef vector<int> vi;
typedef pair<int,int> pi;
/*

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;
*/

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,k,m=0,l;
	cin>>t;
	//string a,b,c;
	while(t--)
	{
		cin>>n;
		set <int, greater <int> > a;
		//int a[n];
		FOR(i,n)
		//cin>>a[i];
		{
			cin>>k;
			a.insert(k);
		}
		cout<<a.size()<<"\n";
	}
}
