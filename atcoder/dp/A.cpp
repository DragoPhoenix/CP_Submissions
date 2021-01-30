#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> a(n),dp(n,1000000000);
  for(int i=0;i<n;i++)cin>>a[i];
  dp[n-1]=0;
  dp[n-2]=dp[n-1]+abs(a[n-1]-a[n-2]);
  for(int i=n-3;i>=0;i--)
  {
    dp[i]=min(dp[i+1]+abs(a[i+1]-a[i]),dp[i+2]+abs(a[i+2]-a[i]));
  }
  cout<<dp[0]<<"\n";
}  