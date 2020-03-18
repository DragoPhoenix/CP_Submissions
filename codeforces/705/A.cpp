#include <iostream>
#include <string.h>
#include "bits/stdc++.h"
using namespace std;
#include<algorithm>

int main() 
{
	int n,c=0;
	cin>>n;
    string a="I hate";
	while(--n)
	{
		if(c%2==0)
		{
			a+=" that I love";
		}
		else
		{
			a+=" that I hate";
		}
		c++;
	}
	a+=" it";
	cout<<a;
}
