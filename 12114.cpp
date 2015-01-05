#include<stdio.h>
int main()
{
	double a,b,S,B,i;
	i=0;
	while(1)
	{	
		scanf("%lf%lf",&B,&S);
		if(B==0&&S==0)
			break;
			i++;
		if(B==1)
		{
			printf("Case %.0lf: :-\\",i);
			printf("\n");
			
		}
		else
		{
			a=S/B;
			if(a>=1)
			a=1;
			b=(S-1)/(B-1);
			if(b>=1)
			b=1;
			if(b>a)
				printf("Case %.0lf: :-)\n",i);
			else if(b<a)
				printf("Case %.0lf: :-(\n",i);
			else if(a==b)
				printf("Case %.0lf: :-|\n",i);

		}
	}
	return 0;
}
