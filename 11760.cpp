#include<stdio.h>

int main()
{
	long r[10010],c[10010],n,u,v,i,k=1,rr,cc,fg,max;
	while(~scanf("%ld%ld%ld",&rr,&cc,&n)&&(rr||cc||n))
	{
		if(r>c)
			max=rr;
		else
			max=cc;

		for(i=0;i<max;i++)
		{
			r[i]=0;
			c[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%ld%ld",&u,&v);
			r[u]++;
			c[v]++;
		}
		fg=0;
		scanf("%ld%ld",&u,&v);
		
		if(u-1>=0&&(r[u-1]==0&&c[v]==0))
			fg=1;
		else if(u+1<rr&&(r[u+1]==0&&c[v]==0))
			fg=1;
		else if(v-1>=0&&(r[u]==0&&c[v-1]==0))
			fg=1;
		else if(v+1<cc&&(r[u]==0&&c[v+1]==0))
			fg=1;
		else if(r[u]==0&&c[v]==0)
			fg=1;
		if(fg)
			printf("Case %ld: Escaped again! More 2D grid problems!\n",k++);
		else
			printf("Case %ld: Party time! Let's find a restaurant!\n",k++);	
	}
	return 0;
}