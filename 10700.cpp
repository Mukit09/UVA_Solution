#include<stdio.h>
#include<string.h>

int main()
{
	char ch[40],c;
	long i,j,t,num[15];
	double num1[15],max,min;
	scanf("%ld",&t);
	while(t--)
	{
		max=1;
		min=i=0;
		while(scanf("%ld%c",&num[i],&c)&&c!='\n')
		{
			ch[i]=c;
			num1[i]=num[i];
			i++;
		}
		num1[i]=num[i];
		for(j=0;j<i;j++)
		{
			if(ch[j]=='+')
			{
				num[j+1]=num[j]+num[j+1];
				num[j]=1;
			}
		}
		for(j=0;j<=i;j++)
			max*=num[j];
		for(j=0;j<i;j++)
		{
			if(ch[j]=='*')
			{
				num1[j+1]=num1[j]*num1[j+1];
				num1[j]=0;
			}
		}
		for(j=0;j<=i;j++)
			min+=num1[j];
		printf("The maximum and minimum are %.0lf and %.0lf.\n",max,min);
	}
	return 0;
}