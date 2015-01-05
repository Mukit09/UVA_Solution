#include<stdio.h>
#include<string.h>

long Leap(long a)
{
	if(a%400==0||(a%4==0 && a%100!=0))
		return 1;
	else
		return 0;
}
int main()
{
	char ch[20],zod[15][20];
	long yer[]={0,31,28,31,30,31,30,31,31,30,31,30,31},t,k=1,i,y,m,d,a[]={0,21,20,21,21,22,22,23,22,24,24,23,23};

	strcpy(zod[1],"aquarius");
	strcpy(zod[2],"pisces");
	strcpy(zod[3],"aries");
	strcpy(zod[4],"taurus");
	strcpy(zod[5],"gemini");
	strcpy(zod[6],"cancer");
	strcpy(zod[7],"leo");
	strcpy(zod[8],"virgo");
	strcpy(zod[9],"libra");
	strcpy(zod[10],"scorpio");
	strcpy(zod[11],"sagittarius");
	strcpy(zod[12],"capricorn");

	scanf("%ld",&t);
	getchar();

	while(t--)
	{
		gets(ch);
		m=(ch[0]-48)*10+(ch[1]-48);
		d=(ch[2]-48)*10+(ch[3]-48);
		y=(ch[4]-48)*1000+(ch[5]-48)*100+(ch[6]-48)*10+(ch[7]-48);
		if(Leap(y))
			yer[2]=29;
		else
			yer[2]=28;
		for(i=0;i<280;i++)
		{
			if(d==yer[m])
			{
				m++;
				d=0;
			}
			if(m>12)
			{
				m=1;
				y++;
				if(Leap(y))
					yer[2]=29;
				else
					yer[2]=28;
			}
			d++;
		}
		printf("%ld %02ld/%02ld/%ld",k++,m,d,y);
		i=m;
		if(d<a[m])
			i=m-1;
		if(i==0)
			i=12;
		printf(" %s\n",zod[i]);
	}
	return 0;
}