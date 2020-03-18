#include <iostream>
#include<string.h>
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
	int n,flag=1;
	cin>>n;
	char a;
	FOR(i,n)
	{
		cin>>a;
		if(a=='1')
		{
			flag=0;
			break;
		}
	}
	if(!flag)
		cout<<"HARD";
	else
		cout<<"EASY";
}