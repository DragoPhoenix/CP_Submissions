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

    cin >> n >> m;
    
    vector<vector<char>> a(n + 1, vector<char>(m + 1));

    vector<vi> ans;

    FORL(i, 1, n + 1)
        FORL(j, 1, m + 1)
            cin >> a[i][j];

    vi dx = {0, 0, 1, 1};
    vi dy = {0, 1, 0, 1};

    FORL(i, 1, n + 1)
    {
        FORL(j, 1, m + 1)
        {
            if(j + 1 == m + 1)
                j--;
            if(i + 1 == n + 1)
                i--;

            x = 0;
            FOR(l, 4)
            {
                if(a[i+dx[l]][j+dy[l]] == '1')
                    x++;
            }

            vi step;
            if(x == 3)
            {
                FOR(l, 4)
                {
                    if(a[i+dx[l]][j+dy[l]] == '1')
                    {
                        step.PB(i + dx[l]);
                        step.PB(j + dy[l]);
                        a[i+dx[l]][j+dy[l]] = '0';
                    }
                }
                ans.PB(step);
            }
            else //if(x == 4 || x == 1)
            {
                if(x == 4)
                {
                    FOR(l, 3)
                    {      
                        step.PB(i + dx[l]);
                        step.PB(j + dy[l]);
                        a[i+dx[l]][j+dy[l]] = '0';
                    }
                    x = 1;
                }
                if(!step.empty())
                {
                    ans.PB(step);
                    step.clear();
                }

                if(x == 1)
                {
                    vi pos;
                    FOR(l, 4)
                        if(a[i+dx[l]][j+dy[l]] == '1')
                        {
                            y = l;
                            a[i+dx[l]][j+dy[l]] = '0';
                        }
                        else if(pos.size() < 2)
                        {
                            pos.PB(l);
                            a[i+dx[l]][j+dy[l]] = '1';
                        }

                    pos.PB(y);
                    for(auto e : pos)
                    {
                        step.PB(i + dx[e]);
                        step.PB(j + dy[e]);
                    }
                    x = 2;  
                }


                if(!step.empty())
                {
                    ans.PB(step);
                    step.clear();
                }

                if(x == 2)
                {
                    // debugv(step)
                    // debugv2(ans)
                    // debugv2(a)
                    vi ze;
                    y = -1;
                    FOR(l, 4)
                        if(a[i+dx[l]][j+dy[l]] == '1' && y == -1)
                        {
                            y = l;
                            a[i+dx[l]][j+dy[l]] = '0';
                        }
                        else if(a[i+dx[l]][j+dy[l]] == '0')
                        {
                            ze.PB(l);
                            a[i+dx[l]][j+dy[l]] = '1';
                        }

                    ze.PB(y);
                    for(auto e : ze)
                    {
                        step.PB(i + dx[e]);
                        step.PB(j + dy[e]);
                    }

                    ans.PB(step);
                    step.clear();
                    x = 3;

                    FOR(l, 4)
                    {
                        if(a[i+dx[l]][j+dy[l]] == '1')
                        {
                            step.PB(i + dx[l]);
                            step.PB(j + dy[l]);
                            a[i+dx[l]][j+dy[l]] = '0';
                        }
                    }
                    ans.PB(step);
                }
            }
            j++;
        }
        i++;
    }

    cout << ans.size() << "\n";
    for(auto e : ans)
    {
        for(auto f : e)
            cout << f << " ";
        cout << "\n";
    }
}

int main() 
{
    by_ANIKET
    ll T = 1,t = 0;
    cin >> T;
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