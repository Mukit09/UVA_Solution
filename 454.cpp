
// the code given below was my 1st code and I was given WA for STL structure sort functtion ,then brianfry713 sent me
// a modified code,from which i understood my error was in sort function... i compared 1stly ch2,then ch1...but i have to do
// it according to ch1

#include<iostream>                  
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,string>mp;
char ch[10010],st[1050],st1[1050];
string res;

struct ss
{
	string ch1,ch2;
}stru[1000100];

bool cmp(ss aa,ss bb)
{
	return aa.ch1<bb.ch1;
}

int main()
{
	long i,k,j,t,len;
	scanf("%ld",&t);
	while(getchar()!='\n');
	while(getchar()!='\n');
	while(t--)
	{
		len=0;
		while(gets(ch))
		{
			if(strcmp(ch,"")==0)
				break;
			j=k=0;
			for(i=0;ch[i];i++)
			{
				if(ch[i]!=32)
				{
					st[k++]=ch[i];
					st1[j++]=ch[i];
				}
				else if(ch[i]==32)
					st[k++]=ch[i];
			}
			st1[j]=st[k]=0;
			sort(st1,st1+j);
			stru[len].ch1=st;
			stru[len++].ch2=st1;
		}
		sort(stru,stru+len,cmp);
		for(i=0;i<len;i++)
		{
			for(k=i+1;k<len;k++)
			{
				if(stru[i].ch2==stru[k].ch2&&mp[stru[i].ch1]!=stru[k].ch1&&stru[i].ch1!=stru[k].ch1)
				{
					mp[stru[i].ch1]=stru[k].ch1;
					cout<<stru[i].ch1<<" = "<<stru[k].ch1<<endl;
				}
			}
		}
		if(t)
			printf("\n");
		mp.clear();
	}
	
	return 0;
}


/*

// code sent by brianfry713

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
char ch[10010],st[1050],st1[1050];
string res;

struct ss
{
   string ch1,ch2;
}stru[1000100];

bool cmp(ss aa,ss bb)
{
   return (aa.ch1<bb.ch1);
}

int main()
{
	long i,k,j=0,t,len;
	scanf("%ld",&t);
	while(getchar()!='\n');
	while(getchar()!='\n');
	while(t--)
	{
		len=0;
		while(gets(ch))
		{
			if(strcmp(ch,"")==0)
			   break;
			j=k=0;
			for(i=0;ch[i];i++)
			{
				if(ch[i]!=32)
				{
					st[k++]=ch[i];
					st1[j++]=ch[i];
				}
				else if(ch[i]==32)
					st[k++]=ch[i];
			}
			st1[j]=st[k]=0;
			sort(st1,st1+j);
			stru[len].ch1=st;
			stru[len++].ch2=st1;
		}
		sort(stru,stru+len,cmp);
		for(i=0;i<len;i++)
		{
			for(k=i+1;k<len;k++)
			{
				if(stru[i].ch2==stru[k].ch2)
				{
					cout<<stru[i].ch1<<" = "<<stru[k].ch1<<endl;
				}   
			}
		}
		if(t)
			printf("\n");
	}
	return 0;
}
*/