#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

queue<long>q;
vector<long>v[1000010];

long in[1000010];

int main()
{
	long flag,i,j,k,n,e,a,b,x;
	while(scanf("%ld%ld",&n,&e)&&(n||e))
	{
		flag=0;
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&a,&b);
			v[a].push_back(b);
			in[b]++;
		}

		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
				flag=1;
			}
		}
		if(!flag)
		{
			printf("IMPOSSIBLE\n");
		}

		else
		{
			while(!q.empty())
			{
				x=q.front();
				q.pop();
				k=v[x].size();
				for(i=0;i<k;i++)
				{
					j=v[x][i];
					in[j]--;
					if(in[j]==0)
					{
						q.push(j);
					}
				}
				printf("%ld\n",x);		
			}
		}
		for(i=0;i<=n;i++)
		{
			in[i]=0;
			v[i].clear();
		}
	}
	return 0;
}