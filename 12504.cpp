#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,string>mp1,mp2;

char ch1[110],ch2[110],st1[110],st2[110];
long len1,len2,l1,l2,i,j,fg,t,in,in1;

struct ss
{
	string ch;
}TT1[110],TT2[110];

bool cmp(ss aa,ss bb)
{
	return aa.ch<bb.ch;
}

int main()
{
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		in=in1=0;
		gets(ch1);
		gets(ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		len1=len2=0;
		for(i=0;i<l1;i++)
		{
			if(ch1[i]>=97&&ch1[i]<=122)
			{
				j=0;
				while(ch1[i]>=97&&ch1[i]<=122&&i<l1)
					st1[j++]=ch1[i++];
				st1[j]=0;
				TT1[len1++].ch=st1;
			}
			else if(ch1[i]>=48&&ch1[i]<=57)
			{
				j=0;
				while(ch1[i]>=48&&ch1[i]<=57&&i<l1)
					st2[j++]=ch1[i++];
				st2[j]=0;
				mp1[st1]=st2;
			}
		}
		sort(TT1,TT1+len1,cmp);

		for(i=0;i<l2;i++)
		{
			if(ch2[i]>=97&&ch2[i]<=122)
			{
				j=0;
				while(ch2[i]>=97&&ch2[i]<=122&&i<l2)
					st1[j++]=ch2[i++];
				st1[j]=0;
				TT2[len2++].ch=st1;
			}
			else if(ch2[i]>=48&&ch2[i]<=57)
			{
				j=0;
				while(ch2[i]>=48&&ch2[i]<=57&&i<l2)
					st2[j++]=ch2[i++];
				st2[j]=0;
				mp2[st1]=st2;
			}
		}
		sort(TT2,TT2+len2,cmp);
		fg=1;
		for(i=0;i<len2;i++)
		{
			if(mp2[TT2[i].ch]!=""&&mp1[TT2[i].ch]=="")
			{
				if(fg)
				{
					in1=in=1;
					fg=0;
					cout<<"+"<<TT2[i].ch;
				}
				else
					cout<<","<<TT2[i].ch;
			}
		}
		if(in1)
			puts("");
		in1=0;
		fg=1;
		for(i=0;i<len1;i++)
		{
			if(mp2[TT1[i].ch]==""&&mp1[TT1[i].ch]!="")
			{
				if(fg)
				{
					in1=in=1;
					fg=0;
					cout<<"-"<<TT1[i].ch;
				}
				else
					cout<<","<<TT1[i].ch;
			}
		}
		if(in1)
			puts("");
		in1=0;
		fg=1;
		for(i=0;i<len2;i++)
		{
			if(mp2[TT2[i].ch]!=mp1[TT2[i].ch]&&mp2[TT2[i].ch]!=""&&mp1[TT2[i].ch]!="")
			{
				if(fg)
				{
					in1=in=1;
					fg=0;
					cout<<"*"<<TT2[i].ch;
				}
				else
					cout<<","<<TT2[i].ch;
			}
		}
		if(in1)
			puts("");
		in1=0;
		if(in==0&&len1==len2)
			puts("No changes");
		puts("");
		mp1.clear();
		mp2.clear();
	}
	return 0;
}

