#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i = a; i<=b; i++)
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A,B,C,f=0,s=0;
    cin >> A >> B >> C;
    if( A == 5 )
    f++;
    if( B == 5 )
    f++;
    if( C == 5 )
    f++;
    if( A == 7 )
    s++;
    
    if( B == 7 )
    s++;
    
    if( C == 7 )
    s++;
    
    if(f == 2 && s == 1)
        cout<<"YES\n";
    else cout<<"NO\n";
        
}