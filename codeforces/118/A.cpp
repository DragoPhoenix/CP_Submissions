#include<stdio.h>
#include<string.h>

int main()
{
	char a[101];
	scanf("%s",a);
	int l = strlen(a);
	int i =0 ;
	while(i<l)
	{
		char c= a[i];
		if((c =='a') || (c =='e') ||(c =='i') ||(c =='o') ||(c =='u') ||(c =='A') ||(c =='E') || (c =='I') ||(c =='O') ||(c =='U') ||c=='Y'||c=='y')
		{
			i++;
		}
		else
		{
			if((c >= 'A') && (c <= 'Z'))
			{
				c =c + 32;
			}
			printf(".%c",c);
			i++;
		}
	}
	
	return 0;
}