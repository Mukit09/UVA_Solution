#include<stdio.h>

long a1[300][300],a2[300][300];
char a[5],b[5],c1,c2;
long t,n,m,fg;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		for(m=1;m<=280;m++)
		{
			for(n=1;n<=280;n++)
				a1[m][n]=0;
		}
		fg=0;
		scanf("%ld",&n);
		while(n--)
		{
			scanf("%s%s",a,b);
			c1=a[0];
			c2=b[0];
			a1[c1][c2]=1;
		}
		scanf("%ld",&m);
		while(m--)
		{
			scanf("%s%s",a,b);
			c1=a[0];
			c2=b[0];
			if(a1[c1][c2]==1)
				fg=1;
		}
		if(!fg)
			printf("NO\n");
		else
			printf("YES\n");
		if(t)
			printf("\n");
	}
	return 0;
}
	

