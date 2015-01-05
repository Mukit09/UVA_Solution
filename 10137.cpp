#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define si 1010
double sm,n,av,p[si],pos_df,neg_df,dif;
long i;
int main()
{
	while(scanf("%lf",&n)&&n)
	{
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
			sm+=p[i];
		}
		av=sm/n;
		pos_df=neg_df=0;
		for(i=1;i<=n;i++)
		{
			dif= (double)(long) ((p[i]-av)*100.0)/100.0;
			if(p[i]>av)
				pos_df+=dif;
			else
				neg_df+=-dif;
		}
		if(pos_df<neg_df)
			printf("$%.2lf\n",neg_df);
		else
			printf("$%.2lf\n",pos_df);
	}
	return 0;
}