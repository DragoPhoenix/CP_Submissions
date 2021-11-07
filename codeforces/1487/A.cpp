#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,min,co=0,it=0;;
    cin>>n;
    vector<long long int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    min=a[0];
    while(a[it]==min)
        it++;
    co=it;
    cout<<n-it<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}