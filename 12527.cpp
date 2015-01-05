#include<stdio.h>
#define si 5010

long a[si],chk[10];

void pre_cal()
{
	long i,cnt=0,j,k,fg;
	for(i=1;i<=si-10;i++)
	{
		for(j=0;j<=9;j++)
			chk[j]=0;
		fg=1;
		j=i;
		while(j!=0)
		{
			k=j%10;
			chk[k]++;
			if(chk[k]>1)
			{
				fg=0;
				break;
			}
			j/=10;
		}
		if(fg)
		{
			cnt++;
			a[i]=cnt;
		}
		else
			a[i]=cnt;
	}
}


int main()
{
	pre_cal();
	long n,m;
	while(~scanf("%ld%ld",&n,&m))
	{
		printf("%ld\n",a[m]-a[n-1]);
	}
	return 0;
}