#include<stdio.h>

int main()
{
	long long n,i,j,k=1,t,a[110][110],fg;
	char ch[10];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s%s%lld",ch,ch,&n);
		fg=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%lld",&a[i][j]);
				if(a[i][j]<0)
					fg=1;
			}
		}
		if(!fg)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][j]!=a[n-1-i][n-1-j])
					{
						fg=1;
						break;
					}
				}
				if(fg)
					break;
			}
		}
		if(fg)
			printf("Test #%lld: Non-symmetric.\n",k++);
		else
			printf("Test #%lld: Symmetric.\n",k++);
	}
	return 0;
}