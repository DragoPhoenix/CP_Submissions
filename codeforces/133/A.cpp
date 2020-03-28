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
	int t,n,L,U,k=0,z=0;;
	string a;
	cin>>a;
	n=a.length();
	FOR(i,n)
	{
		if(a[i]=='H'||a[i]=='Q'||a[i]=='9')
		{
			//if(a[i]=='Q'&&i!=0)
			z=1;
			break;
		}
	}
	if(z)
		cout<<"YES";
	else
		cout<<"NO";

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