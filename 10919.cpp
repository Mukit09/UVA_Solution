#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<string,long>mp;

char ch[10];
long cnt[110],n,i,j,fg,total,must,m;

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		scanf("%ld",&m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch);
			mp[ch]=1;
		}
		fg=0;
		for(i=1;i<=m;i++)
		{
			cnt[i]=0;
			scanf("%ld%ld",&total,&must);
			for(j=1;j<=total;j++)
			{
				scanf("%s",ch);
				if(mp[ch]==1)
					cnt[i]++;
			}
			if(must>cnt[i])
				fg=1;
		}
		if(fg)
			puts("no");
		else
			puts("yes");
		mp.clear();
	}

	return 0;
}