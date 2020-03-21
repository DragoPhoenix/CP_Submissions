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
	int t,n,m,k,r;
	cin>>n;
	int a[n];
	FOR(i,n)
	cin>>a[i];
	int b[n];
	b[0]=a[0];
	m=a[0];
	FORL(i,1,n)
	{
		b[i]=a[i]+m;
		if(b[i]>m)
			m=b[i];
	}
	FOR(i,n)
	cout<<b[i]<<" ";
	
}
