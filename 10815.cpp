#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<string>v;

int main()
{
	char c;
	string ch;
	long l,i;
	while((c=getchar())!=EOF)
	{
		if(c>=65&&c<=90)
			c+=32;
		if(c>=97&&c<=122)
			ch+=c;
		else if(ch[0]>=97&&ch[0]<=122)
		{
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