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


char prime[1000000]={0};
int P[100000],k;

void sieve()
{
	
	P[k++]=2;

	for(int i=3;i*i<1000000;i+=2)
	{
		if(!prime[i])
		{
			P[k++]=i;
			for(int j=i*i;j<1000000;j+=i+i)
				prime[j] = 1;
		}
	}

	for(int i=1001;i<1000000;i+=2)
		if(!prime[i])
			P[k++]=i;
}

void solve()
{
	ll n,m,k,c=0,x,y,z;
	cin>>n;
	x=pow(2,8);
	if(n<=x)
	{
		// while(m--)
		// {
		// 	cout<<x<<" "<<n<<"\n";
		// }
		m=n;
		z=0;
		while(n!=1)
		{
			z++;
			// cout<<m<<" 2\n";
			n=ceil(n/2.0);
		}
		cout<<m-3+z<<"\n";
		y=m-3;
		x=3;
		if(y!=0)
		while(y--)
		{
			cout<<x<<" "<<m<<"\n";
			x++;
		}
		while(z--)
		{
			cout<<m<<" 2\n";
		}
	}
	else
	{
		x=pow(2,6);
		y=n-4;
		z=0;
		m=n;
		while(m!=1)
		{
			z++;
			m=ceil((double)m/x);
		}
		cout<<y+z+6<<"\n";
		k=3;
		while(y--)
		{
			cout<<k<<" "<<n<<"\n";
			k++;
			if(k==x)k++;
		}
		while(z--)
		{
			cout<<n<<" "<<x<<"\n";
		}
		k=6;
		while(k--)
			cout<<x<<" "<<2<<"\n";
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
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
