#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>v;
bool my(string aa,string bb)
{
	if(aa+bb<bb+aa)
		return false;
	return true;
}
int main()
{
	string st;
	long n,i;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>st;
			v.push_back(st);
		}
		sort(v.begin(),v.end(),my);
		for(i=0;i<v.size();i++)
			printf("%s",v[i].c_str());
		printf("\n");
		v.clear();
	}
	return 0;
}
