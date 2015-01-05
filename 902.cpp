#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>

using namespace std;
map<string,long>mp;

string st;
string ch;
string re;

int main()
{
	long i,j,k,max,n,l,cnt;
	while(~scanf("%ld",&n))
	{
		cin>>st;
		max=0;
		l=st.length();
		for(i=0;i<=l-n;i++)
		{
			ch=st.substr(i,n);
			cnt=mp[ch]++;
			if(cnt>max)
			{
				max=cnt;
				re=ch;
			}
		}
		cout<<re<<endl;
		mp.clear();
	}
	return 0;
}