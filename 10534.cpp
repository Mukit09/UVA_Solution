#include<stdio.h>
#include<math.h>
#define neg_inf -2147483648
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define si 10001
int lis[si],a[si],chk1[si],chk2[si];

void bsearch(int lo,int hi,int key)
{
	int mid;
	while(lo<=hi)
	{
		mid=(lo+hi)>>1;
		if(lis[mid]==key)
			return ;
		else if(lis[mid]>key)
			hi=mid-1;
		else
			lo=mid+1;
	}
	lis[lo]=key;
}

int main()
{
	int cur,i,n;
	while(~scanf("%d",&n))
	{
		cur=0;
		lis[cur]=neg_inf;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>lis[cur])
			{
				cur++;
				lis[cur]=a[i];
			}
			else if(a[i]<lis[cur])
				bsearch(1,cur,a[i]);
			chk1[i]=cur;
		}
		cur=0;
		lis[cur]=neg_inf;
		for(i=n;i>=1;i--)
		{
			if(a[i]>lis[cur])
			{
				cur++;
				lis[cur]=a[i];
			}
			else if(a[i]<lis[cur])
				bsearch(1,cur,a[i]);
			chk2[i]=cur;
		}
		cur=-1;
		for(i=1;i<=n;i++)
			cur=max(cur,min(chk1[i],chk2[i]));
		printf("%d\n",cur*2-1);
	}
	return 0;
}
