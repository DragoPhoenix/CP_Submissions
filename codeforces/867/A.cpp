#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#include<algorithm>
#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)

int main()
{
	int n,N=0,Y=0;
	cin>>n;
	string a;
	cin>>a;
	FOR(i,n-1)
	{
		if(a[i]=='F'&&a[i+1]=='S')
			N++;
		else if(a[i]=='S'&&a[i+1]=='F')
			Y++;

	}
	if(Y>N)
		cout<<"YES";
	else
		cout<<"NO";
}