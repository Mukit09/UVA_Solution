#include<stdio.h>
#define si 2002

int a_in[si],a_de[si],in[si],cur_in,cur_de;

void bsearch_in(int beg,int end,int key)
{
	int mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a_in[mid]==key)
			return ;
		else if(a_in[mid]>key)
			end=mid-1;
		else
			beg=mid+1;
	}
	a_in[beg]=key;
}

void bsearch_de(int beg,int end,int key)
{
	int mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a_de[mid]==key)
			return ;
		else if(a_de[mid]<key)
			end=mid-1;
		else
			beg=mid+1;
	}
	a_de[beg]=key;
}

int main()
{
	int t,n,i,j,fg_in,fg_de,mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&in[i]);
		mx=0;
		for(i=1;i<=n;i++)
		{
			a_in[0]=in[i];
			a_de[0]=in[i];
			cur_in=fg_in=0;
			cur_de=fg_de=0;
			for(j=i+1;j<=n;j++)
			{
				if(in[j]>a_in[cur_in])
				{
					cur_in++;
					a_in[cur_in]=in[j];
					fg_in=1;
				}
				else if(fg_in&&in[j]>a_in[0])
					bsearch_in(1,cur_in,in[j]);
				if(in[j]<a_de[cur_de])
				{
					cur_de++;
					a_de[cur_de]=in[j];
					fg_de=1;
				}
				else if(fg_de&&in[j]<a_de[0])
					bsearch_de(1,cur_de,in[j]);
			}
			if(mx<cur_in+cur_de+1)
				mx=cur_in+cur_de+1;
		}
		printf("%d\n",mx);
	}
	return 0;
}
