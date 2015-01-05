#include <stdio.h>
#define si 1010
#define max(a,b)(a>b ?a:b)

int n,m,a[si];
int chk(int x)
{
    int p=x,j=0,i;
    for(i=1;i<=n;i++)
	{
        if(p<a[i])
		{
            p=x;
			j++;
            if(j==m) 
				return 0;
        }
        p-=a[i];
    }
    return 1;
}

int main()
{
	int i,mn,sm,beg,end,w;
    while(~scanf("%d%d",&n,&m))
	{
        mn=sm=0;
        for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mn=max(mn,a[i]);
			sm+=a[i];
		}
		beg=mn;
		end=sm;
        while(beg<end)
		{
            w=(beg+end)/2;
            if(!chk(w)) 
				beg=w+1;
            else 
				end=w;
        }
        printf("%d\n",beg);
    }
    return 0;
}
