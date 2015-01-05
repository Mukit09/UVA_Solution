/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 637 (696 - How Many Knights) */
/* SUBMISSION: 09657039 */
/* SUBMISSION TIME: 2012-01-18 12:51:48 */
/* LANGUAGE: 1 */

#include<stdio.h>

int main()
{
	long r,c,a;
	while(scanf("%ld%ld",&r,&c)&&r&&c)
	{
		if(r==1||c==1)
		{
			printf("%ld knights may be placed on a %ld row %ld column board.\n",r*c,r,c);
			continue;
		}
		if(r==2)
		{
			if(c%4==1)
			{
				a=r*c-(c/4)*4;
			}
			else if(c%4==2)
			{
				a=r*(c+2)/2;
			}
			else if(c%4==3)
			{
				a=r*(c+1)/2;
			}
			else
			{
				a=(r*c)/2;	
			}	
			printf("%ld knights may be placed on a %ld row %ld column board.\n",a,r,c);
			continue;
		}
		if(c==2)
		{
			if(r%4==1)
			{
				a=r*c-(r/4)*4;
			}
			else if(r%4==2)
			{
				a=c*(r+2)/2;
			}
			else if(r%4==3)
			{
				a=c*(r+1)/2;
			}
			else
			{
				a=(r*c)/2;	
			}	
			printf("%ld knights may be placed on a %ld row %ld column board.\n",a,r,c);
			continue;
		}
		if((r*c)%2==0)
		{
			printf("%ld knights may be placed on a %ld row %ld column board.\n",(r*c)/2,r,c);
			continue;
		}
		if((r*c)%2!=0)
		{
			printf("%ld knights may be placed on a %ld row %ld column board.\n",(r*c)/2+1,r,c);
			continue;
		}
	}
	return 0;
}