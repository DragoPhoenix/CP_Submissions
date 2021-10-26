//Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007

#define FOR(a,c)   for ( ll (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( ll (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  ll (a)=(b); (a)>=(c); (a)--)
#define INF 9223372036854775807
//18446744073709551615
#define abs llabs
#define by_ANIKET ios::sync_with_stdio(false);  cin.tie(NULL);

#define no cout<<"No\n";
#define yes cout<<"Yes\n";

#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

#define pr4(a,b,c,d) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\t"<<#d<<"="<<d<<"\n";
#define pr3(a,b,c) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\n";
#define pr2(a,b) cerr<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\n";
#define pr1(a) cerr<<#a<<"="<<a<<"\n";
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int india = 0; india<N;india++) cerr<<A[india]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int india=0;india<N;india++){cerr<<"[";for(int sachin=0;sachin<M;++sachin) cerr<<A[india][sachin]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int india = 0; india< (v).size(); india++) cerr<<v[india]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int india=0;india<v.size();india++){cerr<<"[";for(int sachin=0;sachin<(v[india].size());++sachin) cerr<<v[india][sachin]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto india = m.begin(); india!=m.end();india++) cerr<<*india<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto india = m.begin();india!=m.end(); india++) cerr<<"("<<india->first<<","<<india->second<<") ";cerr<<"]\n";

typedef unsigned long long ull;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back

inline long long  max3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  min3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

const ll N=2e5+5;

void solve()
{
    ll n, m, t = 0, k = 0, x = 0, y = 0, z = 0, a1, a2, a3, a4, a5, var = 1, f = INF;
    string s;

    cin >> n >> m >> s;
    
    if(n < 3)
    {
        FOR(i, m)
        {
            cin >> x >> y;
            if(y == x)
            {
                cout << "0\n";
                continue;
            }
            if(y == x + 1)
            {
                if(s[x-1] == s[y-1])
                    cout << "1\n";
                else
                    cout << "0\n";
                continue;
            }
            a1 = a2 = a3 = 0;
            FORL(i, x-1, y)
                if(s[i] == 'a')
                    a1++;
                else if(s[i] == 'b')
                    a2++;
                else
                    a3++;
            z = 0;
            if(a1 == 0)
                z++;
            if(a2 == 0)
                z++;
            if(a3 == 0)
                z++;
            cout << z << "\n";
            continue;
        }
        return;
    }

    vector<vi> v0, v1, v2;

    map <int, vi> mp;

    vi temp = {0, 0, 0};
    temp[s[0] - 'a']++;
    // v0.PB(temp);
    mp[0] = temp;

    FORL(i, 3, n)
    {
        temp[s[i] - 'a']++;
        // v0.PB(temp);
        mp[i] = temp;
        i += 2;
    }

    temp = {0, 0, 0};
    temp[s[1] - 'a']++;
    // v1.PB(temp);
    mp[1] = temp;

    FORL(i, 4, n)
    {
        temp[s[i] - 'a']++;
        // v1.PB(temp);
        mp[i] = temp;
        i += 2;
    }

    temp = {0, 0, 0};
    temp[s[2] - 'a']++;
    mp[2] = temp;
    // v2.PB(temp);

    FORL(i, 5, n)
    {
        temp[s[i] - 'a']++;
        // v2.PB(temp);
        mp[i] = temp;
        i += 2;
    }

    mp[-1] = {0, 0, 0};
    mp[-3] = mp[-2] = mp[-1];
    // debugv2(v0)
    vi b1, b2, b3;

    vector<string> vs = {"abc", "acb", "bac", "bca", "cab", "cba"};

    FOR(i, m)
    {
        cin >> x >> y;
        if(y - x < 3)
        {
            if(y == x)
            {
                cout << "0\n";
                continue;
            }
            if(y == x + 1)
            {
                if(s[x-1] == s[y-1])
                    cout << "1\n";
                else
                    cout << "0\n";
                continue;
            }
            a1 = a2 = a3 = 0;
            FORL(i, x-1, y)
                if(s[i] == 'a')
                    a1++;
                else if(s[i] == 'b')
                    a2++;
                else
                    a3++;
            z = 0;
            if(a1 == 0)
                z++;
            if(a2 == 0)
                z++;
            if(a3 == 0)
                z++;
            cout << z << "\n";
            continue;
        }
        else
        {
            x--;
            y--;
            a1 = x % 3;
            FORR(j, y, -1)
            {
                if(j % 3 == a1)
                {
                    a2 = j;
                    break;
                }
            }
            temp = mp[a2];
            FOR(j, 3)
                temp[j] -= mp[x-3][j];
            b1 = temp;

            a1 = (x + 1) % 3;
            FORR(j, y, -1)
            {
                if(j % 3 == a1)
                {
                    a2 = j;
                    break;
                }
            }
            temp = mp[a2];
            FOR(j, 3)
                temp[j] -= mp[x-2][j];
            b2 = temp;

            a1 = (x + 2) % 3;
            FORR(j, y, -1)
            {
                if(j % 3 == a1)
                {
                    a2 = j;
                    break;
                }
            }
            temp = mp[a2];
            FOR(j, 3)
                temp[j] -= mp[x-1][j];
            b3 = temp;
            
            z = INF;

            // pr2(x, y)
            // debugv(b1)
            // debugv(b2)
            // debugv(b3)

            for(auto e : vs)
            {
                //e[0] -- b1
                k = 0;
                FOR(j, 3)
                {
                    FOR(q, 3)
                    {
                        if(j == 0 && e[j] - 'a' != q)
                        {
                            k += b1[q];
                        }
                        if(j == 1 && e[j] - 'a' != q)
                        {
                            k += b2[q];
                        }
                        if(j == 2 && e[j] - 'a' != q)
                        {
                            k += b3[q];
                        }
                    }
                }
                // pr2(e, k)
                z = min(z, k);
            }

            cout << z << "\n";
        }
    }
}

int main() 
{
    by_ANIKET
    ll T = 1,t = 0;
    // cin >> T;
    while(t++ < T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
//   ©
//                      ______  __    __ ______ __    __ ________ ________ 
//                     /      \|  \  |  \      \  \  /  \        \        \
//                    |  ▓▓▓▓▓▓\ ▓▓\ | ▓▓\▓▓▓▓▓▓ ▓▓ /  ▓▓ ▓▓▓▓▓▓▓▓\▓▓▓▓▓▓▓▓
//  ______ ______     | ▓▓__| ▓▓ ▓▓▓\| ▓▓ | ▓▓ | ▓▓/  ▓▓| ▓▓__      | ▓▓   
// |      \      \    | ▓▓    ▓▓ ▓▓▓▓\ ▓▓ | ▓▓ | ▓▓  ▓▓ | ▓▓  \     | ▓▓   
//  \▓▓▓▓▓▓\▓▓▓▓▓▓    | ▓▓▓▓▓▓▓▓ ▓▓\▓▓ ▓▓ | ▓▓ | ▓▓▓▓▓\ | ▓▓▓▓▓     | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓ \▓▓▓▓_| ▓▓_| ▓▓ \▓▓\| ▓▓_____   | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓  \▓▓▓   ▓▓ \ ▓▓  \▓▓\ ▓▓     \  | ▓▓   
//                     \▓▓   \▓▓\▓▓   \▓▓\▓▓▓▓▓▓\▓▓   \▓▓\▓▓▓▓▓▓▓▓   \▓▓   