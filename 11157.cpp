#include<stdio.h>
#define max(a,b) (a>b ?a:b)

long a[210],x=1,t,mx,sm,i,j,k,n,d,fg;
char ch[1010];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&d);
		a[0]=a[1]=0;
		j=2;
		for(i=0;i<n;i++)
		{
			scanf("%s",ch);
			sm=0;
			k=2;
			while(ch[k])
			{
				sm=sm*10+(ch[k]-48);
				k++;
			}
			if(ch[0]=='S')
				a[j++]=sm;
			else
			{
				a[j++]=sm;
				a[j++]=sm;
			}
		}
		a[j++]=d;
		a[j++]=d;
		i=2;
		k=3;
		mx=0;
		while(1)
		{
			if(i<j)
				mx=max(mx,a[i]-a[i-2]);
			if(k<j)
				mx=max(mx,a[k]-a[k-2]);
			if(a[i]==d)
				break;
			i+=2;
			k+=2;
		}
		printf("Case %ld: %ld\n",x++,mx);
	}
	return 0;
}