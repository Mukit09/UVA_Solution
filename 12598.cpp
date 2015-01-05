#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define si 50005
#define max(a,b) (a>b?a:b)
int lft[si],dif[si],a[si],ans[si];

int main()
{
	int t,n,k,j,q,u,lo,mid,hi,i,mx,x=1;
	dif[0]=lft[0]=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
			ans[i+1]=a[i];
		}
		sort(a,a+k);
		j=1;
		if(a[0]!=1)
		{
			lft[j]=1;
			dif[j]=a[0]-1;
			j++;
		}	
		for(i=0;i<k-1;i++)
		{
			if(a[i+1]-a[i]>1)
			{
				lft[j]=a[i]+1;
				dif[j]=dif[j-1]+a[i+1]-a[i]-1;
				j++;
			}
		}
		if(a[k-1]!=n)
		{
			lft[j]=a[k-1]+1;
			dif[j]=dif[j-1]+n-a[k-1];
			j++;
		}
		printf("Case %d:\n",x++);
		while(q--)
		{
			scanf("%d",&u);
			if(u<=k)
			{
				printf("%d\n",ans[u]);
				continue;
			}
			u-=k;
			lo=1;
			hi=j-1;
			mx=-1;
			while(lo<=hi)
			{
				mid=(lo+hi)/2;
				if(dif[mid]>u)
					hi=mid-1;
				else
				{
					mx=max(mx,mid);
					lo=mid+1;
				}
			}
			if(mx==-1)
				mx=lo;
			if(dif[mx]<u)
				printf("%d\n",lft[mx+1]+u-dif[mx]-1);
			else
				printf("%d\n",lft[mx]+u-dif[mx-1]-1);
		}
	}
	return 0;
}