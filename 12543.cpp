#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char str[110],res[110];
char ch[10010];

int main()
{
	long i,l,j,mx=0,fg;
	while(~scanf("%s",ch))
	{
		l=strlen(ch);
		if(ch[0]=='E'&&ch[1]=='-'&&ch[2]=='N'&&ch[3]=='-'&&ch[4]=='D'&&l==5)
			break;
		j=0;
		fg=1;
		for(i=0;i<l;i++)
		{
			if((ch[i]>=65&&ch[i]<=90)||(ch[i]>=97&&ch[i]<=122)||ch[i]=='-')
			{
				while((ch[i]>=65&&ch[i]<=90)||(ch[i]>=97&&ch[i]<=122)||ch[i]=='-')
				{
					str[j]=ch[i];
					i++;
					j++;
					if(i==l)
						break;
				}
				i--;
			}
			str[j]=0;
			if(str[0]=='E'&&str[1]=='-'&&str[2]=='N'&&str[3]=='-'&&str[4]=='D'&&j==5)
				fg=0;
			else if(mx<j)
			{
				mx=j;
				strcpy(res,str);
			}
			j=0;
		}	
	}
	for(i=0;i<mx;i++)
	{
		if(res[i]>=65&&res[i]<=90)
			printf("%c",res[i]+32);
		else
			printf("%c",res[i]);
	}
	puts("");
	return 0;
}