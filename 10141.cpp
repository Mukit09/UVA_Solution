#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define eps 1e-9
char ch[110];

struct ss
{
	char st[110];
	double cst;
	long ind,com;
}stru[1010];

bool cmp(ss aa,ss bb)
{
	if(aa.com==bb.com)
	{
		if(fabs(aa.cst-bb.cst)<eps)
			return aa.ind<bb.ind;
		return aa.cst<bb.cst;
	}
	return aa.com>bb.com;
}

int main()
{
	long i,p,r,fg=0,x=1,n;
	while(~scanf("%ld%ld",&n,&p)&&(n||p))
	{
		if(fg)
			puts("");
		fg=1;
		while(getchar()!='\n');
		for(i=1;i<=n;i++)
			gets(ch);
		for(i=0;i<p;i++)
		{
			stru[i].ind=i;
			gets(stru[i].st);
			scanf("%lf%ld",&stru[i].cst,&r);
			while(getchar()!='\n');
			stru[i].com=r;
			while(r--)
				gets(ch);
		}
		sort(stru,stru+n,cmp);
		printf("RFP #%ld\n",x++);
		printf("%s\n",stru[0].st);
	}
	return 0;
}