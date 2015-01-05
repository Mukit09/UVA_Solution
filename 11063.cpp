#include<stdio.h>
long a[10005];
int main()
{
	long n,t=1,i,sa[110],j,d,k,flag;
	while(scanf("%ld",&n)==1)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&sa[i]);
			if(sa[i]==0)
				flag=1;
			if((sa[i]<sa[i-1]) && i)
				flag=1;
		}
		d=0;
		if(!flag)
		{
			for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
				{
					a[d]=sa[i]+sa[j];
					d++;
					for(k=d-2;k>=0;k--)
					{
						if(a[d-1]==a[k])
						{
							flag=1;
							break;
						}
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
		}
		if(flag)
			printf("Case #%ld: It is not a B2-Sequence.\n\n",t++);
		else
			printf("Case #%ld: It is a B2-Sequence.\n\n",t++);
	}
	return 0;
}