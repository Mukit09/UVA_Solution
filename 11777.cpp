/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2877 (11777 - Automate the Grades) */
/* SUBMISSION: 08933194 */
/* SUBMISSION TIME: 2011-06-09 18:29:25 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
  long t1,t2,f,a,ct1,ct2,ct3,t,ct,sum,i;
  scanf("%ld",&t);
  for(i=1;i<=t;i++)
  {

   scanf("%ld%ld%ld%ld%ld%ld%ld",&t1,&t2,&f,&a,&ct1,&ct2,&ct3);
     if(ct1>=ct2&&ct3>=ct2)
	 ct=(ct1+ct3)/2;
	 else if(ct2>=ct1&&ct3>=ct1)
	 ct=(ct2+ct3)/2;
	 else
		 ct=(ct2+ct1)/2;
	 sum=ct+t1+t2+f+a;
	 if(sum>=90)
		 printf("Case %ld: A\n",i);
	 else if(sum>=80)
		 printf("Case %ld: B\n",i);
	 else if(sum>=70)
		 printf("Case %ld: C\n",i);
	 else if(sum>=60)
		 printf("Case %ld: D\n",i);
	 else if(sum<60)
		 printf("Case %ld: F\n",i);

  }
  return 0;
 
}