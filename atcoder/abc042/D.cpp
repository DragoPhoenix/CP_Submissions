#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i = a; i<=b; i++)
typedef long long int ll;
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
ll MOD = 1'000'000'007;
#define pr3(a,b,c) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\n";
#define pr2(a,b) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\n";
#define pr1(a) cerr<<#a<<"="<<a<<"\n";

ll extgcd(ll a, ll b, ll &x, ll &y) {                     // ExtGCD
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

inline ll mod(ll a, ll m) {                               // mod a wrt b
    return (a % m + m) % m;
}

ll modinv(ll a) {                                         // mod inverse a wrt 10^9+7
    ll x, y;
    extgcd(a, MOD, x, y);
    return mod(x, MOD);
}
vector<ll> vp (2e5+2,-1);
ll fact(ll n)
{
    if(vp[n]!=-1)
        return vp[n];
    ll f = ( fact(n-1) * n ) % MOD; 
    vp [n] = f;
    return f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int h, w, a, b;
    cin>>h>>w>>a>>b;

    // int arr[h][w];
    /*
    0 0 0 0 0
    0 0 0 0 0
    1 1 1 0 0
    1 1 1 0 0
    */
    // FOR(i,0,h-1)
    // {
    //     FOR(j,0,w-1)
    //     {
    //         arr[i][j] = 0;
    //         // cout<< arr[i][j] <<" "; 
    //     }
    //     // cout<<"\n";
    // }
    // FOR(i,0,a-1)
    // {
    //     FOR(j,0,b-1)
    //     {
    //         arr[h-1-i][j] = -1; 
    //     }
    // }
    // arr[h-1][w-1] = 1;
    // for(int i = h-1; i>=0; i--)
    // {
    //     for (int j = w-1 ; j >= 0; --j)
    //     {
    //         int val = 0;
    //         if(arr[i][j] == -1 || (i==h-1 && j==w-1))
    //             continue;
    //         if(i+1<h && arr[i+1][j] != -1)
    //             val+=arr[i+1][j];
    //         if(j+1<w && arr[i][j+1] != -1)
    //             val+=arr[i][j+1];
    //         arr[i][j] = val % 1'000'000'007;
    //     }
    // }
    // cout<<arr[0][0]<<"\n";


    // H rows  W cols
    // H D's and W R's
    // H - A D's and W R's followed by A D's
    // A D's and W R's
    // h--;
    // w--;
    // a--;
    // b--;
    // ll tot = ((( fact(h+w) * modinv( fact(w) ) ) % MOD ) * modinv(fact(h)))%MOD;
    // ll p1 = ((( fact(a+w) * modinv( fact(w) ) )%MOD)* modinv( fact(a)))%MOD;
    // ll p2 = ((( fact(a+w-b) * modinv( fact(w-b) ) ) % MOD ) * modinv (fact(a)))%MOD;
    // cout<<tot-p1 + p2<<"\n";
    // p1 = 1;
    // FOR(i,1,b-1)
    // {
    //     p2 = ((( fact(h - a +i) * modinv( fact(h-a) ) ) % MOD ) * modinv (fact(i)))%MOD;
    //     p1 = (p1 + p2) % MOD;
    // }
    // pr3(tot, p1, p2)
    
    // cout<<tot-p1<<"\n";
    ll c = 0,d,e,f;
    vp [0] = vp [1] =1;
    FOR(i,b,w-1)
    {
        d =( ( ((( fact(h - a -1 + i) * modinv( fact(h-a-1) ) ) % MOD ) * modinv (fact(i)))%MOD  ) * 
                  (  ((( fact(a - 1 + w - 1 - i ) * modinv( fact(a-1) ) ) % MOD ) * modinv (fact(w - i - 1)))%MOD  )  ) % MOD ;
        c = (c + d) % MOD;
    }
    cout<<c<<"\n";
}