#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

long penalty[120][20],corchk[120][20],s[120],check[120];

struct ss
{
	long s,co,man,chk;
}T[120];

bool cmp(ss aa,ss bb)
{
	if(aa.co>bb.co)
		return true;
	else if(aa.co==bb.co)
	{
		if(aa.s<bb.s)
			return true;
		else if(aa.s==bb.s)
		{
			if(aa.man<bb.man)
				return true;
		}
	}
	return false;
}

int main()
{
	long c,p,t,i,j,tt,n,sum,cnt;
	char ch[10],st[1000];

	scanf("%ld",&tt);
	getchar();
	gets(st);
	while(tt--)
	{
		for(i=1;i<=110;i++)
		{
			for(j=1;j<=110;j++)
			{
				penalty[i][j]=0;
				corchk[i][j]=0;
			}
			check[i]=0;
		}
		i=1;
		while(gets(st))
		{
			if(!strcmp(st,""))
				break;
			sscanf(st,"%ld%ld%ld%s",&c,&p,&t,ch);
			if(check[c]==0)
			{
				check[c]=1;
				s[i++]=c;
			}
			T[c-1].chk=1;
			if(ch[0]=='I'&&corchk[c][p]==0)
				penalty[c][p]=penalty[c][p]+20;
			else if(ch[0]=='C'&&corchk[c][p]==0)
			{
				penalty[c][p]+=t;
				corchk[c][p]=1;
			}
		}
		n=i-1;
		for(i=1;i<=n;i++)
		{
			c=s[i];
			sum=0;
			cnt=0;
			for(j=1;j<=9;j++)
			{
				if(corchk[c][j]==1)
				{
					sum+=penalty[c][j];
					cnt++;
					corchk[c][j]=0;
				}
			}
			T[i-1].s=sum;
			T[i-1].co=cnt;
			T[i-1].man=c;
		}
		sort(T,T+n,cmp);
		for(i=1;i<=n;i++)
			printf("%ld %ld %ld\n",T[i-1].man,T[i-1].co,T[i-1].s);

		if(tt)
			printf("\n");
	}
	return 0;
}
		