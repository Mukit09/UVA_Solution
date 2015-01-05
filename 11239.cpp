#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define sz 110
using namespace std;
map<string,long>mp,mp1;
set<string>s[sz];
char ch[10100],ch1[10100];
long i,ind,l,k,j,ll,t;

struct ss
{
	string st;
	long cnt;
}stru[sz];

bool cmp(ss aa,ss bb)
{
	if(aa.cnt==bb.cnt)
		return aa.st<bb.st;
	return aa.cnt>bb.cnt;
}

int main()
{
	while(gets(ch))
	{
		if(strcmp(ch,"0")==0)
			break;
		ind=0,j=0;
		while(1)
		{
			if(strcmp(ch,"1")==0)
				break;
		//	ind++;
			while(1)
			{
				gets(ch1);
				if((ch1[0]>=65&&ch1[0]<=90)||strcmp(ch1,"1")==0)
				{
					stru[j].st=ch;
					stru[j].cnt=mp1[ch];
					j++;
					strcpy(ch,ch1);
					break;
				}
				t=mp[ch1];
				if(t!=(j+1)&&t)
				{
					if(stru[t-1].cnt>0)
						stru[t-1].cnt--;
					mp[ch1]=-1;
					continue;
				}
				if(t==-1)
					continue;
				mp[ch1]=j+1;
				l=s[j].size();
				s[j].insert(ch1);
				ll=s[j].size();
				if(ll!=l)
					mp1[ch]++;
			}
		}
		sort(stru,stru+j,cmp);
		for(i=0;i<j;i++)
			cout<<stru[i].st<<" "<<stru[i].cnt<<endl;

		for(i=0;i<j;i++)
			s[i].clear();

		mp.clear();
		mp1.clear();
	}
	return 0;
}