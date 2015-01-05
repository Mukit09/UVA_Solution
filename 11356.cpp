#include<stdio.h>
#include<string.h>

long check(long y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
		return 1;
	else return 0;
}

int main()
{
	long i,k=1,y,m,d,day,t,j;
	long a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char month[15][20];
	strcpy(month[1],"January");
	strcpy(month[2],"February");
	strcpy(month[3],"March");
	strcpy(month[4],"April");
	strcpy(month[5],"May");
	strcpy(month[6],"June");
	strcpy(month[7],"July");
	strcpy(month[8],"August");
	strcpy(month[9],"September");
	strcpy(month[10],"October");
	strcpy(month[11],"November");
	strcpy(month[12],"December");

	char ch[20],ch1[20];
	scanf("%ld",&t);
	while(t--)
	{
		y=0;d=0;
		scanf("%s",&ch1);
		scanf("%ld",&day);

		for(i=0;i<=3;i++)
			y=y*10+(ch1[i]-48);
		j=0;
		for(i=5;;i++)
		{
			if(ch1[i]=='-')
				break;
			ch[j++]=ch1[i];
		}
		ch[j]=0;

		for(j=i+1;ch1[j];j++)
			d=d*10+(ch1[j]-48);

		if(check(y))
			a[2]=29;
		else
			a[2]=28;

		for(i=1;i<=12;i++)
		{
			if(strcmp(month[i],ch)==0)
			{
				m=i;
				break;
			}
		}
		for(i=1;i<=day;i++)
		{
			if(d==a[m])
			{
				d=0;
				m++;
			}
			if(m>12)
			{
				y++;
				m=1;
				
			}
			if(check(y))
				a[2]=29;
			else a[2]=28;
			d++;
		}
		printf("Case %ld: %ld-%s-%02ld\n",k++,y,month[m],d);
	}
	return 0;
}
