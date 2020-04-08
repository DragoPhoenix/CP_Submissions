#include "bits/stdc++.h"
using namespace std;

#define max(a, b) (a < b? b : a)
#define min(a, b) ((a>b)?b:a)

#define MOD 1000000007

#define FOR(a,c)   for ( int (a)=0; (a)<(c); (a)++)
#define FORL(a,b,c)  for ( int (a)=(b); (a)<(c); (a)++)
#define FORR(a,b,c)  for (  int (a)=(b); (a)>=(c); (a)--)

#define INF 1000000000000000003

#define abs llabs
#define BOOST ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

#define no cout<<"NO\n";
#define yes cout<<"YES\n";

#define Clear( a, b ) memset( a, b, sizeof( a ) )
#define run if(1)cout<<__LINE__<<endl;  

#define pr3(a,b,c) cout<<"var1="<<a<<"\n"<<"var2="<<b<<"\n"<<"var3="<<c<<"\n";
#define pr2(a,b) cout<<"var1="<<a<<"\n"<<"var2="<<b<<"\n";
#define pr1(a) cout<<"var1="<<a<<"\n";

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

void solve()
{
	ll n,m,k,c=0,x,y,z;
	cin>>n>>m;
	k=n*m;
	if(k%2==0)
	{
		c=k-1;
		x=c/2;
		y=c-x;
		z=m-1;
		cout<<"B";
		FOR(i,z)
		{
			if(i%2)
				cout<<"W";
			else
			cout<<"B";
		}
		cout<<"\n";
		n--;z=1;
		FOR(i,n)
		{
			
			FOR(j,m)
			{
				if(j%2==z%2)
					cout<<"W";
				else
					cout<<"B";
			}
			cout<<"\n";
			z++;
		}	
	}
	else
	{
		c=k;z=1;
		FOR(i,n)
		{
			
			FOR(j,m)
			{
				if(j%2==z%2)
					cout<<"W";
				else
					cout<<"B";
			}
			cout<<"\n";
			z++;
		}
	}


}

int main() 
{
	BOOST
	ll T=1,t=0;
	cin>>T;
	while(t++<T)
	{
		//cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
	}
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
