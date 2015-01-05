#include<stdio.h>
#include<string.h>

int main()
{
	char mon1[20],mon2[20],c;
	long count,k=1,d1,y1,d2,y2,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s%ld%c%ld",&mon1,&d1,&c,&y1);
		scanf("%s%ld%c%ld",&mon2,&d2,&c,&y2);
		if(strcmp(mon1,"January")==0)
			y1--;
		else if(strcmp(mon1,"February")==0)
			y1--;
		if(strcmp(mon2,"January")==0)
			y2--;
		else if(strcmp(mon2,"February")==0&&d2<29)
			y2--;
		count=0;
		count=y2/4-y1/4;
		count+=y2/400-y1/400;
		count-=y2/100-y1/100;
		printf("Case %ld: %ld\n",k++,count);
	}
	return 0;
}
