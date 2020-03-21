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
	ll t,n,m,k,r;
	cin>>t;
	n=t/5;
	t=t%5;
	m=n;
	n=t/4;
	t=t%4;
	m+=n;
	n=t/3;
	t=t%3;
	m+=n;
	n=t/2;
	t=t%2;
	m+=n;
	n=t/1;
	t=t%1;
	m+=n;
	cout<<m;
}
