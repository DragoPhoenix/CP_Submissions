#include <iostream>
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int main() 
{
	ll t,n,m,k,r;
	cin>>n>>m>>t;
	k=min(n,m);
	if(n!=m)
		r=2*k+1;
	else
		r=2*k;
	r+=2*t;
	cout<<r;
	
}
