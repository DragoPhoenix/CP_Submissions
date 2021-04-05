#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i = a; i<=b; i++)
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,L;
    std::vector< string > v;
    cin >> N >> L;
    v.resize(N);
    FOR(i,0,N-1)
        cin>>v[i];
    sort(v.begin(), v.end());
    for(auto e:v)
        cout<<e;
        
}