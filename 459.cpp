#include<stdio.h>
#include<string.h>

long r[30];
long p[30];
long a[30];
char ch[10];

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

void parent(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	long i,t,pu,pv,u,v,n,count;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		n=ch[0]-64;
		for(i=1;i<=n;i++)
		{
			r[i]=1;
			p[i]=i;
			a[i]=0;
		}
		getchar();
		while(gets(ch))
		{
			if(!strcmp(ch,""))
				break;
			u=ch[0]-64;
			v=ch[1]-64;
			pu=find(u);
			pv=find(v);
			if(pu!=pv)
				parent(pu,pv);
		}
		for(i=1;i<=n;i++)
		{
			u=find(i);
			a[u]++;
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0)
				count++;
		}
		printf("%ld\n",count);
		if(t)
			printf("\n");
	}
	return 0;
}