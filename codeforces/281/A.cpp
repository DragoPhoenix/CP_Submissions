#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin>>a;
	if(a[0]>='A'&&a[0]<='Z')
		cout<<a;
	else
	{
		a[0]-=32;
		cout<<a;
	}
}