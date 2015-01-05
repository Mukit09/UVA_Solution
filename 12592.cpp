#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;

map<string,string>mp;
char ch[110],ch1[110];
int i,j,l,n,q;

int main()
{
	while(~scanf("%d",&n))
	{
		while(getchar()!='\n');
		for(i=1;i<=n;i++)
		{
			gets(ch);
			gets(ch1);
			mp[ch]=ch1;
		}
		scanf("%d",&q);
		while(getchar()!='\n');
		while(q--)
		{
			gets(ch);
			cout<<mp[ch]<<endl;
		}
	}
	return 0;
}