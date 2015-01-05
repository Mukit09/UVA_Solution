#include<stdio.h>

long dp[10010],mx_m,mx_n,m,n,t,mx,mc,nc;

long max(long a,long b,long c)
{
	if(a>=b&&a>=c)
		return a;
	else if(b>=a&&b>=c)
		return b;
	else
		return c;
}

long rec(long mm,long nn)
{
	if(mm*m+nn*n>t)
		return 0;
	if(dp[mm*m+nn*n]!=-1)
		return dp[mm*m+nn*n];
	
	long p1,p2,p3;
	p1=rec(mm+1,nn);
	p2=rec(mm,nn+1);
	p3=mm*m+nn*n;
	dp[mm*m+nn*n]=max(p1,p2,p3);
	if(dp[mm*m+nn*n]>mx||(dp[mm*m+nn*n]==mx&&(mc+nc)<(mm+nn)))
	{
		mx=dp[mm*m+nn*n];
		mc=mm;
		nc=nn;
	}
	return dp[mm*m+nn*n];
}

int main()
{
	long i,re,swp;
	while(~scanf("%ld%ld%ld",&m,&n,&t))
	{
		for(i=0;i<=t;i++)
			dp[i]=-1;
		if(m>n)     //otherwise give WA
		{
			swp=m;
			m=n;
			n=swp;
		}
		mx=mc=nc=0;
		re=rec(0,0);
		printf("%ld",mc+nc);
		if(re!=t)
			printf(" %ld",t-re);
		printf("\n");
	}
	return 0;
}

/*
// 2nd code TLE
 #include<stdio.h>

long dp[10010][10010],mx_m,mx_n,m,n,t,mx,mc,nc;

long max(long a,long b,long c)
{
	if(a>=b&&a>=c)
		return a;
	else if(b>=a&&b>=c)
		return b;
	else
		return c;
}

long rec(long mm,long nn)
{
	if(mm*m+nn*n>t||mm>mx_m||nn>mx_n)
		return 0;
	if(dp[mm][nn]!=-1)
		return dp[mm][nn];
	
	long p1,p2,p3;
	p1=rec(mm+1,nn);
	p2=rec(mm,nn+1);
	p3=mm*m+nn*n;
	dp[mm][nn]=max(p1,p2,p3);
	if(dp[mm][nn]>mx||(dp[mm][nn]==mx&&(mc+nc)<(mm+nn)))
	{
		mx=dp[mm][nn];
		mc=mm;
		nc=nn;
	}
	return dp[mm][nn];
}

int main()
{
	long i,re,j;
	while(~scanf("%ld%ld%ld",&m,&n,&t))
	{
	
		mx_m=t/m;
		mx_n=t/n;
		for(i=0;i<=mx_m;i++)
		{
			for(j=0;j<=mx_n;j++)
				dp[i][j]=-1;
		}
		mx=mc=nc=0;
		re=rec(0,0);
		printf("%ld",mc+nc);
		if(re!=t)
			printf(" %ld",t-re);
		printf("\n");
	}
	return 0;
}

  */

/*
//1st code TLE
  #include<stdio.h>

long m,n,t,mx_m,mx_n,dp[10010][10010],mc,nc,mx,taken;

long max(long a,long b,long c)
{
	if(a>=b&&a>=c)
		return a;
	else if(b>=a&&b>=c)
		return b;
	else
		return c;
}

long rec(long cnt_m,long cnt_n)
{
	if(cnt_m*m+cnt_n*n>t)
	{
		if(cnt_n==0)
			return mx_m*m;
		else if(cnt_m==0)
			return mx_n*n;
		return 0;
	}
	if(dp[cnt_m][cnt_n]!=-1)
		return dp[cnt_m][cnt_n];
	long p1,p2,p3;
	
	p1=rec(cnt_m+1,cnt_n);
	p2=rec(cnt_m,cnt_n+1);
	p3=rec(cnt_m+1,cnt_n+1);
	dp[cnt_m][cnt_n]=max(p1,p2,p3);
	if(dp[cnt_m][cnt_n]>mx)
	{
		mx=dp[cnt_m][cnt_n];
		mc=cnt_m;
		nc=cnt_n;
	}
	return cnt_m*+cnt_n*n;
}

int main()
{
	long i,j,ans;
	while(~scanf("%ld%ld%ld",&m,&n,&t))
	{
		mx_m=t/m;
		mx_n=t/n;
		mx=0;
		for(i=0;i<=mx_m;i++)
		{
			for(j=0;j<=mx_n;j++)
				dp[i][j]=-1;
		}
		ans=rec(0,0);
		printf("The result:\n");
		printf("%ld",mc+nc);
		if(ans!=t)
			printf(" %ld",t-ans);
		printf("\n");
	}
	return 0;
}

  */