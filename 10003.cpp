#include<stdio.h>
#define inf 99999999
#define min(a,b) (a<b ?a:b)
#define si 55

int dp[si][si],a[si];

int rec(int x,int y)
{
    if(y-x==1)    
		return 0;

	int &ret=dp[x][y];
    if(ret!=-1)
		return ret;

    int cst,mn=inf,i;

    for(i=x+1;i<y;i++)
    {
        cst=rec(x,i)+rec(i,y)+a[y]-a[x];
        mn=min(cst,mn);
    }
    return ret=mn;
}

int main()
{
    int l,n,i,j;
    while(~scanf("%d",&l)&&l)
    {
        scanf("%d",&n);
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++)
				dp[i][j]=-1;
		}
        a[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1]=l;
        printf("The minimum cutting is %d.\n",rec(0,n+1));
    }
return 0;
}