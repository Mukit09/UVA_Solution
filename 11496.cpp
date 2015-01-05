#include<stdio.h>

int main()
{
	long n,i,a[10010],cnt,fg;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		fg=cnt=0;
		a[0]=a[n];
		a[n+1]=a[1];
		for(i=0;i<=n;i++)
		{
			fg=0;
			if(a[i+1]>a[i])
			{
				while(a[i+1]>a[i])
				{
					fg=1;
					i++;
				}
				cnt++;
				if(fg)
					i--;
			}
			else if(a[i+1]<a[i])
			{
				while(a[i+1]<a[i])
				{
					fg=1;
					i++;
				}
				cnt++;
				if(fg)
					i--;
			}
		}
		printf("%ld\n",cnt-1);
	}
	return 0;
}