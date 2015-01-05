#include<stdio.h>
long neg_inf=-1047483648;

long a[1001000],in[1001000],par[1001000],ind[1001000],last_index,cur=0;

void binary_search(long beg,long end,long key,long index)
{
	long mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==key)
			return;
		else if(a[mid]>key)
			end=mid-1;
		else
			beg=mid+1;
	}
	a[beg]=key;
	ind[beg]=index;
	par[index]=beg>1?ind[beg-1]:-1;
	if(beg==cur)
		last_index=index;
}

void print_path(long last_index)
{
	if(last_index==-1)
		return ;
	print_path(par[last_index]);
	printf("%ld\n",in[last_index]);
}

int main()
{
	long i=1,x=1,j=1,k=1,len=0;
	a[0]=neg_inf;
	par[1]=-1;
	while(~scanf("%ld",&in[i]))
	{
		if(in[i]>a[cur])                   
		{
			cur++;
			a[cur]=in[i];
			ind[cur]=i;
			par[i]=cur>1?ind[cur-1]:-1;
			if(len<cur)
				len=cur,last_index=i;
			
		}
		else if(in[i]<a[cur])
			binary_search(0,cur,in[i],i);
		i++;
	}
	printf("%ld\n-\n",len);
	print_path(last_index);
	return 0;
}


/*

O(n^2) solution got TLE

#include<stdio.h>

long a[100100],n,dir[100100],dp[100100];

long longest(long u)
{
	if(u>n)
		return 0;
	if(dp[u]!=-1)
		return dp[u];
	long mx=0,p,v;
	for(v=u+1;v<=n;v++)
	{
		if(a[v]>a[u])
		{
			p=longest(v);
			if(mx<=p)
			{
				mx=p;
				dir[u]=v;
			}
		}
	}
	dp[u]=1+mx;
	return dp[u];
}

void print_path((long start)
{
	while(1)
	{
		printf("%ld\n",a[start]);
		if(dir[start]==-1)
			break;
		start=dir[start];
	}
}

int main()
{
	long i=1,mx=0,k,start,p;
	while(~scanf("%ld",&k))
	{
		dp[i]=dir[i]=-1;
		a[i++]=k;
	}
	n=i-1;
	for(i=1;i<=n;i++)
	{
		p=longest(i);
		if(mx<p)
		{
			mx=p;
			start=i;
		}
	}
	printf("%ld\n-\n",mx);
	print_path((start);
	return 0;
}

*/