#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,long>mp;

char ch[20],ch1[20];
long taken[30],p,s,t,mat[20][20];

struct ss
{
	char st[20];
	long l;
}stru[20];

bool cmp(ss aa,ss bb)
{
	if(aa.l==bb.l)
	{
		if(strcmp(aa.st,bb.st)<0)
			return true;
		else
			return false;
	}
	return aa.l>bb.l;
}

void rec(long ind,long len)
{
	long i,fg,j;
	if(len==s)
	{
		fg=1;
		for(i=0;i<=ind;i++)
		{
			for(j=i+1;j<=ind;j++)
			{
				if(taken[i]&&taken[j]&&mat[mp[stru[i].st]][mp[stru[j].st]])
					return;
			}
		}
		
		for(i=0;i<=ind;i++)
		{
			if(taken[i]==1&&fg)
			{
				fg=0;
				printf("%s",stru[i].st);
			}
			else if(taken[i]==1)
				printf(" %s",stru[i].st);
		}
		puts("");
		return ;
	}
	for(i=ind;i<t;i++)
	{
		if(taken[i]==0)
		{
			taken[i]=1;
			rec(i+1,len+1);
			taken[i]=0;
		}
	}
}

int main()
{
	long T,x=1,i,j,k;
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%ld%ld%ld",&t,&p,&s);
		for(i=0;i<t;i++)
		{
			scanf("%s",stru[i].st);
			stru[i].l=strlen(stru[i].st);
			for(j=0;j<stru[i].l;j++)
			{
				if(stru[i].st[j]>=97&&stru[i].st[j]<=122)
					stru[i].st[j]-=32;
			}
			for(j=1;j<=t;j++)
				mat[i+1][j]=0;
		}
		sort(stru,stru+t,cmp);
		k=1;
		for(i=1;i<=p;i++)
		{
			scanf("%s%s",ch,ch1);
			for(j=0;ch[j];j++)
			{
				if(ch[j]>=97&&ch[j]<=122)
					ch[j]-=32;
			}
			for(j=0;ch1[j];j++)
			{
				if(ch1[j]>=97&&ch1[j]<=122)
					ch1[j]-=32;
			}
			if(mp[ch]==0)
				mp[ch]=k++;
			if(mp[ch1]==0)
				mp[ch1]=k++;
			mat[mp[ch]][mp[ch1]]=mat[mp[ch1]][mp[ch]]=1;
		}
		printf("Set %ld:\n",x++);
		rec(0,0);
		puts("");
		mp.clear();

	}
	return 0;
}