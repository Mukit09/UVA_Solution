#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

map<string,long>mp;

struct ss
{
	long a;
	string st;
}T[1000010];

bool cmp(ss aa,ss bb)
{
	if(aa.st>bb.st)
		return false;
	else
		return true;
}

char ch[1000010][40];

int main()
{
	long t,i,j,k;
	double cnt;
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t--)
	{
		i=0;
		while(gets(ch[i]))
		{
			if(strcmp(ch[i],"")==0)
				break;
			mp[ch[i]]++;
			i++;
		}
		cnt=i;
		k=0;
		for(j=0;j<i;j++)
		{
			if(mp[ch[j]]!=0)
			{
				T[k].st=ch[j];
				T[k].a=mp[ch[j]];
				mp[ch[j]]=0;
				k++;
			}
		}
		sort(T,T+k,cmp);
		for(i=0;i<k;i++)
		{
			cout<<T[i].st<<" ";		
			printf("%.4lf\n",(T[i].a/cnt)*100);
		}
		if(t)
			printf("\n");
		mp.clear();
	}
	return 0;
}
