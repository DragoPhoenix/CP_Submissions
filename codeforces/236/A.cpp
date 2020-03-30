#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin>>a;
	int f[26]={0},n=a.length();
	for(int i=0;i<n;i++)
	{
		f[a[i]-97]++;
	}
	int c=0;
	for(int i=0;i<26;i++)
	{
		if(f[i])
			c++;
	}
	if(c%2==0)
	{
		cout<<"CHAT WITH HER!";
	}
	else
		cout<<"IGNORE HIM!";

}