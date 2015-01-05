#include<stdio.h>
#include<math.h>
#define eps 1e-14
#define si 60
int a[si],com[si][si];
double total,m,cnt,res;

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

int main()
{
	int i,j,x,n;
	for(i=0;i<=50;i++)
		com[i][i]=com[i][0]=1;
	for(i=2;i<=50;i++)
	{
		for(j=0;j<=2;j++)
			com[i][j]=com[i-1][j-1]+com[i-1][j];
	}
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				x=gcd(a[i],a[j]);
				if(x==1)
					cnt++;
			}
		}
		if(cnt)
		{
			total=com[n][2];
			res=sqrt((6*total)/cnt);
			printf("%.6lf\n",res+eps);
		}
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}