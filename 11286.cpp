#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
using namespace std;

map<string,long>mp;
string ch[10010];

long n,i,cntmx,a,j,k;

struct ss
{
	char st[30];
}T[10];

bool cmp(ss aa,ss bb)
{
	if(strcmp(aa.st,bb.st)<0) 
		return true;
	else
		return false;
}

int main()
{
	long mx;
	while(~scanf("%ld",&n)&&n)
	{
		k=cntmx=mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s%s%s%s%s",T[0].st,T[1].st,T[2].st,T[3].st,T[4].st);
			sort(T,T+5,cmp);
			for(j=1;j<=4;j++)
				strcat(T[0].st,T[j].st);
			ch[k++]=T[0].st;
			mp[T[0].st]++;
			if(mp[T[0].st]>mx)
				mx=mp[T[0].st];
		}
		for(i=0;i<k;i++)
		{
			if(mp[ch[i]]==mx)
				cntmx++;
		}
		printf("%ld\n",cntmx);
		mp.clear();
	}
	return 0;
}