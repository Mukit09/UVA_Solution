#include<stdio.h>
#include<algorithm>

using namespace std;

long n,m,i,j;

struct ss
{
	long din;
	long dou;
}T[10010];

long even(long x)
{
	if(x<0) x*=-1;
	if(x%2==0)
		return 1;
	return 0;
}

long odd(long x)
{
	if(x<0) x*=-1;
	if(x%2!=0) return 1;
	return 0;
}

bool cmp(ss aa,ss bb)
{
	if ( aa.dou < bb.dou ) 
		return true;
	 
	    if ( aa.dou == bb.dou ) 
		{
	        if ( odd (aa.din) && even (bb.din) ) return true;
	        if ( odd (aa.din) && odd (bb.din) && aa.din > bb.din ) return true;
	        if ( even (aa.din) && even (bb.din) && aa.din < bb.din ) return true;
	    }
	 
	    return false;
}

int main()
{
	while(scanf("%ld%ld",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
		{
			printf("0 0\n");
			break;
		}
		printf("%ld %ld\n",n,m);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&T[i].din);		
			T[i].dou=T[i].din%m;
		}
		sort(T,T+n,cmp);

		for(i=0;i<n;i++)
			printf("%ld\n",T[i].din);
	}
	return 0;
}
