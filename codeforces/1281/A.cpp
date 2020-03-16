#include <iostream>
#include<string.h>
#include "bits/stdc++.h"
using namespace std;
#include<algorithm>
/*continue
cin
cout
while
if else
string*/


int main() 
{
	int t,n;
	cin>>t;
	string s,w;
	while(t--)
	{
		cin>>s;
		n=s.size();
		if(n>=2&&s[n-2]=='p'&&s[n-1]=='o')
		{
			cout<<"FILIPINO\n";
			continue;
		}
		if(n>=5){
		w=s.substr(n-5);
		
		if(w=="mnida")
		{
			cout<<"KOREAN\n";
			continue;
		}}
		if(n>=4){
		w=s.substr(n-4);
		if(w=="desu"||w=="masu")
		{
			cout<<"JAPANESE\n";
			continue;
		}}
	}
}