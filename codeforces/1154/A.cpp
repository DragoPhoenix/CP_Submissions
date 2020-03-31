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
  ll a,b,c,d,k,m,x=0,y;
  cin>>a>>b>>c>>d;
  int n[4];
  n[0]=a;
  n[1]=b;
  n[2]=c;
  n[3]=d;
  sort(n,n+4);
  k=n[3];
  //m=k-a;
  if(a==k)
  {  
    m=k-b;
    x=c-m;
    y=d-m;
    cout<<m<<" "<<x<<" "<<y;
  }
  else if(b==k)
  {  
    m=k-c;
    x=a-m;
    y=d-m;
    cout<<m<<" "<<x<<" "<<y;
  }
  else if(c==k)
  {  
    m=k-b;
    x=a-m;
    y=d-m;
    cout<<m<<" "<<x<<" "<<y;
  }
  else
  {  
    m=k-b;
    x=c-m;
    y=a-m;
    cout<<m<<" "<<x<<" "<<y;
  }
}
