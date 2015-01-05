#include<stdio.h>

#define max 1001
#define len 2600

long num[max][len];
void fact()
{
	long i,j;
	num[0][0]=num[1][0]=1;
	for(i=2;i<max;i++)
	{
		for(j=0;j<len;j++)
		{
			num[i][j]+=num[i-1][j]*i;
			if(num[i][j]>9)
			{
				num[i][j+1]+=num[i][j]/10;
				num[i][j]%=10;
			}
		}
	}
}

int main()
{
	long n,i;
	fact();
	while(scanf("%d",&n)==1)
	{
		printf("%d!\n",n);
		for(i=len-1;i>0;i--)
		{
			if(num[n][i]!=0)
				break;
		}
		for(;i>=0;i--)
		{
			printf("%d",num[n][i]);
		}
		printf("\n");
	}
	return 0;
}