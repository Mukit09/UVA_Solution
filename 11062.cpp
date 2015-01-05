#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<string>v;

int main()
{
	char c;
	string ch;
	long i,l,flag=0;
	while((c=getchar())!=EOF)
	{
		if(c>=65&&c<=90)
			c+=32;
		
		if(flag&&c>=97&&c<=122)
		{
			ch+='-';
			flag=0;
		}
		if(c>=97&&c<=122)
			ch+=c;
		else if(c=='-')
		{
			flag=1;
		}
		else if(flag)
		{
			flag=0;
		}
		else if(ch[0]>=97&&ch[0]<=122)
		{
			flag=0;
			v.push_back(ch);
			ch.erase(ch.begin(),ch.end());
		}
	}
	sort(v.begin(),v.end());
	l=v.size();
	cout<<v[0]<<endl;
	for(i=1;i<l;i++)
	{
		if(v[i]!=v[i-1])
			cout<<v[i]<<endl;
	}
	return 0;
}