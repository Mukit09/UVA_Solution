#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

char foul[5],s1[30],s2[30];
long long n,i,m,s,ms,t,k,j;

struct ss
{
	char ch[30];
	long cost;
}T[110];

bool cmp(ss aa,ss bb)
{
	if(aa.cost<bb.cost) return true;
	else if(aa.cost==bb.cost)
	{
		strcpy(s1,aa.ch);
		strcpy(s2,bb.ch);
		for(j=0;s1[j];j++)
			if(s1[j]>=65&&s1[j]<=90)
				s1[j]+=32;
		for(j=0;s2[j];j++)
			if(s2[j]>=65&&s2[j]<=90)
				s2[j]+=32;
		if(strcmp(s1,s2)<=0) return true;
	}
	return false;
}

int main()
{
	while(~scanf("%lld",&n))
	{
		i=0;
		while(n--)
		{
			scanf("%s%s%lld%s%lld%s%lld%s",&T[i].ch,&foul,&m,&foul,&s,&foul,&ms,&foul);
			t=(m*60+s)*1000+ms;
			T[i].cost=t;
			i++;
		}
		sort(T,T+i,cmp);
		k=1;
		for(j=0;j<i;j++)
		{
			if(j%2==0)
				printf("Row %lld\n",k++);
			printf("%s\n",T[j].ch);
		}
		printf("\n");
	}
	return 0;
}
