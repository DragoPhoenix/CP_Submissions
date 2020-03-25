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

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

ll fcn(ll n) 
{ 
	ll res=1;
  
  	for (int i = 2; i * i <= n; ++i) { 
        if (n % i == 0) { 
            int count = 0; 
            while (n % i == 0) { 
                n /= i; 
                count += 1; 
            } 
          res*=count+1; 
        } 
    } 
    if (n > 1) { 
        res*=2; 
    } 
    return res;
} 
int check(ll n)
{
	if(n<3)
		return 0;
	else if(fcn(n)==2)
		return 1;
	else return 0;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	ll t,a,b,x,y,z,c;
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>x>>y;
		if(x>a-1-x)
			z=x;
		else
			z=a-1-x;
		if(y>b-1-y)
			c=y;
		else
			c=b-1-y;
		if(z*b>=c*a)
		cout<<z*b<<"\n";
		else
			cout<<c*a<<"\n";
	}
}