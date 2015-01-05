#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

long i,t,k=1,j;

struct ss
{
	char ch[30];
	long atk,dfn;
}T[15],re[7];

bool cmp(ss aa,ss bb)
{
	if(aa.atk>bb.atk) 
		return true;
	else if(aa.atk==bb.atk)
	{
		if(aa.dfn<bb.dfn)
			return true;
		else if(aa.dfn==bb.dfn)
		{
			if(strcmp(aa.ch,bb.ch)<=0) 
				return true;
		}
	}
	return false;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
			scanf("%s%ld%ld",T[i].ch,&T[i].atk,&T[i].dfn);
		sort(T,T+10,cmp);
		printf("Case %ld:\n",k++);
		for(i=0;i<5;i++)
		{
			strcpy(re[i].ch,T[i].ch);
			re[i].atk=0;
			re[i].dfn=0;
		}
		sort(re,re+5,cmp);
		printf("(%s, %s, %s, %s, %s)\n",re[0].ch,re[1].ch,re[2].ch,re[3].ch,re[4].ch);

		j=0;
		for(i=5;i<10;i++)
		{
			strcpy(re[j++].ch,T[i].ch);
			re[i].atk=0;
			re[i].dfn=0;
		}
		sort(re,re+5,cmp);
		printf("(%s, %s, %s, %s, %s)\n",re[0].ch,re[1].ch,re[2].ch,re[3].ch,re[4].ch);
	}
	return 0;
}