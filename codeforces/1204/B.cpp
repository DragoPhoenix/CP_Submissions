#include <iostream>
#include <string.h>
#include "bits/stdc++.h"
using namespace std;
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
typedef long long int ll;


int main() 
{
	int l,r,n;
	ll m=0,x=0;
	cin>>n>>l>>r;
	l--;
	int k=0,i=2;
	m+=n-l;
	while(l--)
	{
		k+=i;
		i*=2;
	}
	m+=k;
	n-=r;
	x+=1;
	r--;
	i=2;
	k=0;
	while(r--)
	{
		k+=i;
		i*=2;
	}
	x+=k;
	i/=2;
	while(n--)
	{
		x+=i;
	}
	cout<<m<<" "<<x;
}
	