#include<stdio.h>
int main()
{	
	long a;
	while(scanf("%ld",&a)&&(a!=-1))
	{
		long b=2,c,d=1,i=0;
	while(1)
	{
          if(a==0)
	{
		printf("0 1\n");
		break;
	} 
            
            
            
			else if(a==1)
	{
		printf("1 2\n");
		break;
	}
	else if(a==2)
	{
		printf("2 4\n");
		break;
	}
		i++;
		if(i>(a-2))
		{
			printf("%ld %ld\n",c+1,c+2+d);
			break;
		}
		else
		{
			c=d+b;
			d=b;
			b=c+1;
		}
		}
	}
	return 0;
}
