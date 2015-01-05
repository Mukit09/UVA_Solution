#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#define si 10010
using namespace std;
map<string,long>mp;
char ch[si],ch1[si],in[si];

struct ss
{
	string st;
	long cst;
}stru[110];

bool cmp(ss aa,ss bb)
{
	if(aa.cst==bb.cst)
		return aa.st<bb.st;
	return aa.cst<bb.cst;
}

int main()
{
	long t,i,m,n,b,k,fg,cst,cnt;
	scanf("%ld",&t);
	while(getchar()!='\n');
	while(t--)
	{
		gets(in);
		for(i=0;in[i];i++)
		{
			if(in[i]>=97&&in[i]<=122)
				in[i]-=32;
		}
		scanf("%ld%ld%ld",&m,&n,&b);
		while(m--)
		{
			scanf("%s%ld",ch,&cst);
			mp[ch]=cst;
		}
		getchar();
		i=fg=0;
		while(n--)
		{
			gets(ch);
			scanf("%ld",&k);
			cst=0;
			while(k--)
			{
				scanf("%s%ld",ch1,&cnt);
				cst+=(mp[ch1]*cnt);
			}
			if(cst<=b)
			{
				fg=1;
				stru[i].st=ch;
				stru[i++].cst=cst;
			}
			getchar();
		}
		sort(stru,stru+i,cmp);
		puts(in);
		if(fg)
		{
			for(k=0;k<i;k++)
				cout<<stru[k].st<<endl;
		}
		else
			printf("Too expensive!\n");
		puts("");
	}
	return 0;
}