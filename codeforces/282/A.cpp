#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,x=0;
	cin>>t;
	while(t--)
		{
		string a;
		cin>>a;
		if(a[1]=='+')
			x++;
		else
			x--;
	}
	cout<<x;
}