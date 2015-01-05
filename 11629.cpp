#include<stdio.h>
#include<map>
#include<string.h>
#include<string>

using namespace std;

map<string,double>mp;
char ch[30],st[10];

int main()
{
	long n,i,j,p,g,k=1,fg;
	double vo,sum,u;
	while(~scanf("%ld%ld",&p,&g))
	{
		for(i=1;i<=p;i++)
		{
			scanf("%s%lf",ch,&vo);
			mp[ch]=vo;
		}
		for(i=1;i<=g;i++)
		{
			fg=0;
			sum=0;
			while(1)
			{
				scanf("%s%s",ch,st);
				u=mp[ch]*10;
				sum+=u;
				if(strcmp("+",st)!=0)
				{
					scanf("%lf",&vo);
					vo=vo*10;
					if(strcmp("<",st)==0&&sum>=vo)
						fg=1;
					else if(strcmp(">",st)==0&&sum<=vo)
						fg=1;
					else if(strcmp(">=",st)==0&&sum<vo)
						fg=1;
					else if(strcmp("<=",st)==0&&sum>vo)
						fg=1;
					else if(strcmp("=",st)==0&&sum!=vo)
						fg=1;
					if(fg)
						printf("Guess #%ld was incorrect.\n",k++);
					else
						printf("Guess #%ld was correct.\n",k++);
					break;
				}
			}
		}
	}
	return 0;
}
