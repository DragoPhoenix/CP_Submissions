#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main() 
{
    int a,b,c,k=0,d,t;
    cin>>t;
    while(t--)
    {
    	cin>>a>>b>>c;
    	d=a+b+c;
    	if(d>=2)
    		k++;
    }
    cout<<k;
}