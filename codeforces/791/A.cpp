#include <iostream>
#include <string.h>
#include "bits/stdc++.h"
using namespace std;
#include<algorithm>
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
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

int main() 
{
	ll t,n,k,c=0;
	cin>>n>>t;

	while(n<=t)
	{
		n*=3;
		t*=2;
		c++;
	}
	cout<<c;
}
