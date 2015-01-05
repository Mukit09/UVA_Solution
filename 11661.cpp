#include<stdio.h>

int main()
{
	long i,j,n,min,flag,k,count,flag1=0;
	char c,ct;
	while(scanf("%ld",&n)&&n)
	{
		getchar();
		count=j=flag=0;
		k=0;
		flag1=0;
		min=999999999;
		for(i=1;i<=n;i++)
		{
			c=getchar();
			if(ct!=c&&count==0&&flag1)
				count++;
			if(count)
				k++;
			if(c=='Z')
			{
				flag=1;
				min=0;
			}
			if(!flag)
			{
				if((c=='R'||c=='D')&&count==0)
				{
					flag1=1;
					k=0;
					ct=c;
					count++;
				}
				else if(ct==c&&count==1)
				{
					k=0;
				}
				else if(count==1&&c!='.')
				{
					ct=c;
					count++;
					if(k<min)
					{
						min=k;
						k=0;
					}
				}
				
				if(count==2)
				{
					k=0;
					count=0;
					j=0;
				}
			}
		}
		printf("%ld\n",min);
	}
	return 0;
}
	
