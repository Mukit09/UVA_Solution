#include<stdio.h>
#include<map>
using namespace std;

#define si 63000
#define mem(a,v) memset(a,v,sizeof(a))
#define max(a,b) (a>b ?a:b)
using namespace std;

int a[si],in[si];
int t,i,j,k=1,p,q,n,x=1;

void b_search(int lo,int hi,int val)
{
	int mid;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(a[mid]>val)
			hi=mid-1;
		else
			lo=mid+1;
	}
	a[lo]=val;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		j=1;
		scanf("%d%d%d",&n,&p,&q);
		for(i=0;i<=p;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]=j++;
		}
		j=1;
		for(i=0;i<=q;i++)
		{
			scanf("%d",&a[i]);
			if(mp[a[i]])
				in[j++]=mp[a[i]];
		}
		int cur=0;

		i=1;
		a[cur++]=in[i++];
		while(i<j)
		{
			if(a[cur-1]<in[i])
				a[cur++]=in[i];
			else
				b_search(0,cur-1,in[i]);
			i++;
		}
		printf("Case %d: %d\n",x++,cur);
		mp.clear();
	}
	return 0;
}
