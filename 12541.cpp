#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct ss
{
	char ch[1010];
	long y,m,d;
}stru[110];

bool cmp(ss aa,ss bb)
{
	if(aa.y==bb.y)
	{
		if(aa.m==bb.m)
			return aa.d<bb.d;
		return aa.m<bb.m;
	}
	return aa.y<bb.y;
}

int main()
{
	long n,i;
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
			scanf("%s%ld%ld%ld",stru[i].ch,&stru[i].d,&stru[i].m,&stru[i].y);
		sort(stru,stru+n,cmp);
		printf("%s\n",stru[n-1].ch);
		printf("%s\n",stru[0].ch);
		
	}
	return 0;
}