#include<stdio.h>

int main()
{
	char ch1[5][10],ch2[5][10],st[5][10];
	long t,i,a[100],j,k,sum1,sum2,fg;
	for(i=65;i<=76;i++)
		a[i]=1;
	scanf("%ld",&t);
	while(t--)
	{
		for(i=1;i<=3;i++)
			scanf("%s%s%s",ch1[i],ch2[i],st[i]);
		for(i=65;i<=76;i++)
		{
			fg=1;
			a[i]=2;
			for(j=1;j<=3;j++)
			{
				sum1=sum2=0;
				for(k=0;ch1[j][k];k++)
					sum1+=a[ch1[j][k]];
				for(k=0;ch2[j][k];k++)
					sum2+=a[ch2[j][k]];
				if(st[j][0]=='e'&&sum1!=sum2)
				{
					fg=0;
					break;
				}
				else if(st[j][0]=='d'&&sum1>=sum2)
				{
					fg=0;
					break;
				}
				else if(st[j][0]=='u'&&sum1<=sum2)
				{
					fg=0;
					break;
				}
			}
			a[i]=1;
			if(fg)
			{
				printf("%c is the counterfeit coin and it is heavy.\n",i);
				break;
			}
			fg=1;
			a[i]=0;
			for(j=1;j<=3;j++)
			{
				sum1=sum2=0;
				for(k=0;ch1[j][k];k++)
					sum1+=a[ch1[j][k]];
				for(k=0;ch2[j][k];k++)
					sum2+=a[ch2[j][k]];
				if(st[j][0]=='e'&&sum1!=sum2)
				{
					fg=0;
					break;
				}
				else if(st[j][0]=='d'&&sum1>=sum2)
				{
					fg=0;
					break;
				}
				else if(st[j][0]=='u'&&sum1<=sum2)
				{
					fg=0;
					break;
				}
			}
			a[i]=1;
			if(fg)
			{
				printf("%c is the counterfeit coin and it is light.\n",i);
				break;
			}
		}
	}
	return 0;
}