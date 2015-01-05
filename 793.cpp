#include<stdio.h>
#include<string.h>
#define size 1200000

long r[size];
long p[size];
long a[size];

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
	long t,i,c1,c2,n,pu,pv,u,v;
	char st[50],ch[5];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		getchar();
		c1=c2=0;
		for(i=1;i<=n;i++)
		{
			r[i]=1;
			p[i]=i;
			a[i]=0;
		}
		while(gets(st))
		{
			if(strcmp(st,"")==0)
				break;
			sscanf(st,"%s%ld%ld",&ch,&u,&v);
			if(ch[0]=='c')
			{
				pu=find(u);
				pv=find(v);
				if(pu!=pv)
					parent(pu,pv);
			}
			else if(ch[0]=='q')
			{
				for(i=1;i<=n;i++)
					a[i]=find(i);
				if(a[u]==a[v])
					c1++;
				else c2++;
			}
		}
		printf("%ld,%ld\n",c1,c2);
		if(t)
			printf("\n");
	}
	return 0;
}

