#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
char ch[50],st[50],st1[50];
string res;

struct ss
{
   string ch1,ch2;
}stru[1100];

int main()
{
	long i,k,j=0,t,len,l,n,fg,x;
	scanf("%ld",&t);
	while(t--)
	{
		len=0;
		scanf("%ld",&n);
		while(getchar()!='\n');
		while(n--)
		{
			gets(ch);
			k=0;
			for(i=0;ch[i];i++)
			{
				if(ch[i]!=32)
				{
					st[k]=ch[i];
					st1[k++]=ch[i];
				}
			}
			st1[k]=st[k]=0;
			sort(st1,st1+k);
			stru[len].ch1=st;
			stru[len++].ch2=st1;
		}
		while(gets(ch))
		{
			if(strcmp(ch,"END")==0)
				break;
			printf("Anagrams for: %s\n",ch);
			res=ch;
			l=strlen(ch);
			fg=0;
			x=1;
			sort(ch,ch+l);
			for(i=0;i<len;i++)
			{
				if(stru[i].ch2==ch)
				{
					for(k=i;k<len;k++)
					{
						if(ch!=stru[k].ch2)
							continue;
						printf("%3ld\) ",x++);
						cout<<stru[k].ch1<<endl;
						fg=1;
					}
				}
				if(fg)
					break;
			}
			if(!fg)
				cout<<"No anagrams for: "<<res<<endl;
		}
		if(t)
			printf("\n");
	}
	return 0;
}