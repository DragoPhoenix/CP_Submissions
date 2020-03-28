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

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,x=0,k=0,z=0;;
	//string a;
	cin>>n>>t;
	FORL(i,1,7)
	{
		if(abs(i-n)<abs(i-t))
			x++;
		else if(abs(i-n)>abs(i-t))
			z++;
		else
			k++;
	}
	cout<<x<<" "<<k<<" "<<z;
	

}

/*

4
10
2 1 1 1 1 1 1 1 2 1
8
2 2 2 1 1 1 1 2
10
2 1 2 1 2 3 1 2 2 2
6
3 3 3 3 3 3
*/