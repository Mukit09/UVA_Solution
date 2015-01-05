#include<stdio.h>
#include<string.h>

int taken[15],n,fg,res[10],m,sm,res1[10],x,taken1[10];

int check(int d)
{
	int r=d,cnt=1,p;
	while(r)
	{
		p=r%10;
		taken1[p]++;
		if(taken[p]||taken1[p]>1)
			return 0;
		res1[cnt++]=p;
		r/=10;
	}
	return cnt;
}
void rec(int l)
{
	int i;
	if(l==6)
	{
		sm=0;
		for(i=1;i<=5;i++)
			sm=sm*10+res[i];
		m=sm*n;
		int cnt=0;
		if(m>sm)
		{
			int cnt1=0;
			cnt=check(m);
			for(i=0;i<=9;i++)
			{
				if(taken1[i]&&!taken[i])
					cnt1++;
				taken1[i]=0;
			}
			if(cnt1==4&&taken[0])
				return ;
			if(cnt==5||cnt==6)
			{
				if(cnt==5)
					printf("0");
				for(i=cnt-1;i>=1;i--)
					printf("%d",res1[i]);
				printf(" / ");
				for(i=1;i<=5;i++)
					printf("%d",res[i]);

				printf(" = %d\n",n);
				fg=0;
			}
		}
		
		return ;
	}
	for(i=0;i<=9;i++)
	{
		if(!taken[i])
		{
			taken[i]=1;
			res[x++]=i;
			rec(l+1);
			taken[i]=0;
			x--;
		}
	}
}

int main()
{
	int fg1=0;
	while(~scanf("%d",&n)&&n)
	{
		fg=1;
		x=1;
		if(fg1)
			printf("\n");
		fg1=1;
		rec(1);
		if(fg)
			printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
