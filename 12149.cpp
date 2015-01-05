#include<stdio.h>
int main()
{long n;
while(scanf("%ld",&n)&&(n!=0))
printf("%ld\n",(n*(n+1)*(2*n+1))/6);
return 0;
}