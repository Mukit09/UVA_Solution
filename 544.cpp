#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
using namespace std;

map<string,long>mp;
long i,j,k,cost,w[210][210],n,e,t=1,u,v;
char ch1[40],ch2[40];

long min(long a,long b)
{
	if(a<b) return a;
	else return b;
}
long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				w[i][j]=0;
		}
		j=1;
		for(i=1;i<=e;i++)
		{
			scanf("%s%s%ld",&ch1,&ch2,&cost);
			if(mp[ch1]==0)
			{
				mp[ch1]=j++;	
			}
			if(mp[ch2]==0)
			{
				mp[ch2]=j++;
			}
			u=mp[ch1];
			v=mp[ch2];
			w[u][v]=cost;
			w[v][u]=cost;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));
				}
			}
		}
		scanf("%s%s",ch1,ch2);
		printf("Scenario #%ld\n",t++);
		u=mp[ch1];
		v=mp[ch2];
		printf("%ld tons\n",w[u][v]);
		printf("\n");
		mp.clear();
	}
	return 0;
}