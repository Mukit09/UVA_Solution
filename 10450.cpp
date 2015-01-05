#include<stdio.h>
int main()
{
   double b,c=0;
	scanf("%lf",&b);
	while(1)
	{
		double a,q=2,r=3,p,i=0,d,j;
		c++;
		if(c>b)
			break;
		else
		{
	     scanf("%lf",&a);
	       while(1)
		   {
                  if(a==0)
							  {
		                      printf("Scenario #%.lf:\n1\n\n",c);
		                      break;
							  }
                             else if(a==1)
							  {
		                      printf("Scenario #%.lf:\n2\n\n",c);
		                      break;
							  }
	         else if(a==2)
			 {
	       	 printf("Scenario #%.lf:\n3\n\n",c);
		     break;
			 }
		                     else
							 {
		                      i++;
		                     if(i>(a-2))
							 {
							printf("Scenario #%.lf:\n%.lf\n\n",c,p);
		                   	break;
							 }
		                    else
							{
	                        p=q+r;
		                    q=r;
		                    r=p;
							}

							}
		   }
	}
	}
	getch();
	return 0;
}