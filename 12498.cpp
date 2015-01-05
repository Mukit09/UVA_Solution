#include<stdio.h>
#include<string.h>
#define inf 999999
#define min(a,b) (a<b ?a:b)
#define si 60
long a[si][si],t,i,j,k,cnt,cnt1,cnt2,fg,r,c,x=1,sm,mn;
char ch[si][si];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&r,&c);
		fg=0;
		for(i=0;i<r;i++)
		{
			cnt=0;
			scanf("%s",ch[i]);
			for(j=0;j<c;j++)
			{
				if(ch[i][j]=='0')
					cnt++;
			}
			if(cnt==0)
				fg=1;
		}
		if(fg)
		{
			printf("Case %ld: -1\n",x++);
			continue;
		}
		mn=inf;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cnt1=cnt2=0;
				if(ch[i][j]=='1')
				{
					for(k=j-1;k>=0;k--)
					{
						if(ch[i][k]=='1')
							cnt1++;
						if(ch[i][k]=='0')
						{
							cnt1++;
							break;
						}
					}
					if(k<0||ch[i][k]!='0')
						cnt1=inf;
					for(k=j+1;k<c;k++)
					{
						if(ch[i][k]=='1')
							cnt2++;
						if(ch[i][k]=='0')
						{
							cnt2++;
							break;
						}
					}
					if(k>=c||ch[i][k]!='0')
						cnt2=inf;
				}
				a[i][j]=min(cnt1,cnt2);
			}
		}

		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(ch[i][j]=='0')
				{
					sm=0;
					for(k=0;k<r;k++)
						sm+=a[k][j];
					mn=min(sm,mn);
				}
			}
		}
		printf("Case %ld: %ld\n",x++,mn);
	}
	return 0;
}
