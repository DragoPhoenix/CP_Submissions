#include <iostream>

#include "bits/stdc++.h"
using namespace std;
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef long long int ll;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	//string a;
	cin>>n>>t;
	int a[n];
	FOR(i,n)
	cin>>a[i];
	int w=0;
	FOR(i,n)
	if(a[i]>t)
		w+=2;
	else
		w++;
	cout<<w;
}
