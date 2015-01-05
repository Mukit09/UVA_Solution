#include<stdio.h>
#include<string.h>
#include<math.h>
char ch[110];
long a1[]={1,4,7,6,5,6,3,6,9,0};
long a2[]={1,6,3,6,5,6,7,4,9,0};

int main()
{
	long i,l,sm,cnt,chk;
	while(~scanf("%s",ch))
	{
		if(strcmp(ch,"0")==0)
			break;
		l=strlen(ch);
		cnt=sm=0;
		for(i=0;i<l-1;i++)
			cnt=(cnt*10+ch[i]-48)%10;
		sm=((47%10)*(cnt%10))%10;
		chk=ch[l-1]-48;
		if(cnt%2==0)
		{
			for(i=0;i<chk;i++)
				sm+=(a1[i]%10);
		}
		else
		{
			for(i=0;i<chk;i++)
				sm+=(a2[i]%10);
		}
		sm%=10;
		printf("%ld\n",sm);
	}
	return 0;
}