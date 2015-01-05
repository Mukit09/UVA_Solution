#include<stdio.h>

long n,k,a,b,i,fg=0;
double l[110],w[110];
char st1[10],st2[10];

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		scanf("%ld",&k);
		for(i=1;i<=n;i++)
			l[i]=w[i]=0;
		k=k*n*(n-1)/2;
		for(i=1;i<=k;i++)
		{
			scanf("%ld%s%ld%s",&a,st1,&b,st2);
			if(st1[0]=='p'&&st2[0]=='r')
				w[a]++,l[b]++;
			else if(st1[0]=='r'&&st2[0]=='p')
				l[a]++,w[b]++;
			else if(st1[0]=='s'&&st2[0]=='p')
				w[a]++,l[b]++;
			else if(st1[0]=='p'&&st2[0]=='s')
				l[a]++,w[b]++;
			else if(st1[0]=='r'&&st2[0]=='s')
				w[a]++,l[b]++;
			else if(st1[0]=='s'&&st2[0]=='r')
				l[a]++,w[b]++;
		}
		if(fg)
			printf("\n");
		fg=1;
		for(i=1;i<=n;i++)
		{
			if(l[i]+w[i]==0)
				printf("-\n");
			else
				printf("%.3lf\n",w[i]/(w[i]+l[i]));
		}
	}
	return 0;
}