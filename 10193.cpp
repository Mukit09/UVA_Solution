#include<stdio.h>
#include<string.h>
#include<math.h>

char a[40],b[40];

long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	long long i,k=1,t,la,lb,c,suma,sumb,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		la=strlen(a);
		lb=strlen(b);
		suma=sumb=0;
		for(i=0,j=la-1;i<la;i++,j--)
			suma=suma+(a[i]-48)*pow(2,j);
		
		for(i=0,j=lb-1;i<lb;i++,j--)
			sumb=sumb+(b[i]-48)*pow(2,j);

		c=gcd(suma,sumb);

		if(c==1)
			printf("Pair #%ld: Love is not all you need!\n",k++);
		else
			printf("Pair #%ld: All you need is love!\n",k++);
	}
	return 0;
}