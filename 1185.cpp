    #include<stdio.h>

    #define max 1001
    #define len 2600

    int num[max][len];

    void fact()
    {
		int i,j;
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
		long n,i,sum;
		fact();
		while(scanf("%ld",&n)==1)
		{
			sum=0;
			for(i=0;i<len;i++)
			{
				sum+=num[n][i];
			}
			printf("%d\n",sum);
		}
		return 0;
    }