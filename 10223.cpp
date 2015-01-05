// My 1st code gave me WA because of comparing 2 double numbers in a wrong way,then brianfry713 made my code ok...
//this code is also accepted now... :)
#include<stdio.h>
#include<math.h>
#define si 30
double a[si];

double comb(double j,double k)
{
   double i,a=1;
   for(i=j;i<=k;i++)
      a*=i;
   return a;
}

int main()
{
   double n,d,b,c;
   long i;
   for(i=1;i<20;i++)
   {
      d=comb(1,i);
      b=comb(i+1,2*i);
      c=(b/d);
      c/=(i+1);
      a[i]=c;
   }

   while(~scanf("%lf",&n))
   {
      for(i=1;i<20;i++)
      {
         c=a[i];
         if(fabs(n-c)<0.1) // I have to use fabs() to compare 2 double numbers...<math.h> is enough for fabs()
         {
            printf("%ld\n",i);
            break;
         }
      }
   }
   return 0;
}

// After getting WA in previous code I generated these numbers & it's accepted
/*
#include<stdio.h>
#define si 30
double a[si];

int main()
{
	a[1]=1;
	a[2]=2;
	a[3]=5;
	a[4]=14;
	a[5]=42;
	a[6]=132;
	a[7]=429;
	a[8]=1430;
	a[9]=4862;
	a[10]=16796;
	a[11]=58786;
	a[12]=208012;
	a[13]=742900;
	a[14]=2674440;
	a[15]=9694845;
	a[16]=35357670;
	a[17]=129644790;
	a[18]=477638700;
	a[19]=1767263190;
	double n,c;
	long i;

	while(~scanf("%lf",&n))
	{
		for(i=1;i<20;i++)
		{
			c=a[i];
			if(c==n)
			{
				printf("%ld\n",i);
				break;
			}
		}
	}
	return 0;
}
*/