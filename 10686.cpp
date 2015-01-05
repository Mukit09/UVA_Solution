#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,long>mp;
char ch[50],ch1[110],str[110],ch2[50][20][50];
long w,t,c,i,j,k,first,l,ll,x;

struct ss
{
	char cat[40];
	long p,cnt;
}stru[30];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&c);
		for(i=1;i<=c;i++)
		{
			scanf("%s%ld%ld",stru[i].cat,&w,&stru[i].p);
			k=1;
			for(j=1;j<=w;j++)
			{
				scanf("%s",ch);
				strcpy(ch2[i][j],ch);
				mp[ch]=1;
			}
		}
		while(getchar()!='\n');
		while(gets(ch1))
		{
			if(strcmp(ch1,"")==0)
				break;
			l=strlen(ch1);
			for(i=0;i<l;i++)
			{
				if((ch1[i]>=65&&ch1[i]<=90)||(ch1[i]>=97&&ch1[i]<=122))
				{
					j=0;
					while(((ch1[i]>=65&&ch1[i]<=90)||(ch1[i]>=97&&ch1[i]<=122))&&i<l)
						str[j++]=ch1[i++];
					str[j]=0;
					i--;
					if(mp[str]==1)
					{
						for(k=1;k<=c;k++)
						{
							for(ll=1;ll<=w;ll++)
							{
								if(strcmp(str,ch2[k][ll])==0)
								{
									stru[k].cnt++;
									mp[str]++;
									break;
								}
							}
						}
					}
				}
			}
		}
		first=1;
		for(i=1;i<=c;i++)
		{
			if(first&&stru[i].p<=stru[i].cnt)
			{
				first=0;
				printf("%s",stru[i].cat);
			}
			else if(stru[i].p<=stru[i].cnt)
				printf(",%s",stru[i].cat);
			stru[i].p=stru[i].cnt=0;
		}
		if(first)
			printf("SQF Problem.");
		puts("");
		mp.clear();
	}
	return 0;
}