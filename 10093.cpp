#include<stdio.h>
#include<string.h>
char st[10000010];
long mx,i,l,sum,fg;
int main()
{
	while(gets(st))
	{
		sum=fg=0;
		mx=1;
		l=strlen(st);
		for(i=0;i<l;i++)
		{
			if(st[i]<=57&&st[i]>=48)
				st[i]-=48;
			else if(st[i]<=90&&st[i]>=65)
				st[i]-=55;
			else if(st[i]<=122&&st[i]>=97)
				st[i]-=61;
			else
				continue;
			if(mx<st[i])
				mx=st[i];
			sum+=st[i];
		}
		while(mx<62)
		{
			if(sum%mx==0)
			{
				printf("%ld\n",mx+1);
				fg=1;
				break;
			}
			mx++;
		}
		if(fg==0)
			printf("such number is impossible!\n");
	}
	return 0;
}