#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;

map<string,long>mp;

int main()
{
	char ch[110][55],u[55],v[55];
	long i,j,k=1,n,e,a[110][110],c,d,x,l,flag,count;
	while(scanf("%ld",&n)==1)
	{
		count=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",&ch[i]);
			mp[ch[i]]=0;
		}

		scanf("%ld",&e);
		for(i=1;i<=e;i++)
		{
			scanf("%s%s",&u,&v);
			for(j=1;j<=n;j++)
			{
				if(strcmp(ch[j],u)==0)
				{
					c=j;
				}
				else if(strcmp(ch[j],v)==0)
				{
					d=j;
				}
			}	
			if(a[c][d]!=1)
				mp[v]++;
			a[c][d]=1;
		}

		flag=0;
		for(i=1;i<=n;i++)
		{
			if(mp[ch[i]]==0)
			{
				x=i;
				mp[ch[i]]=-1;
				count++;
				break;
			}
		}

		printf("Case #%ld: Dilbert should drink beverages in this order:",k++);

		while(count!=n)
		{
			printf(" %s",ch[x]);
			for(i=1;i<=n;i++)
			{
				if(a[x][i]==1)
				{
					mp[ch[i]]--;
					a[x][i]=0;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(mp[ch[i]]==0)
				{
					x=i;
					mp[ch[i]]=-1;
					count++;
					break;
				}
			}
		}
		printf(" %s.\n\n",ch[x]);
	}
	return 0;
}

