#include<stdio.h>
#include<string.h>

long taken[15],u,v,fg,fg1,n;
char st[30],ch[15][50];

void rec(long ind,long l,long len)
{
	long i;
	if(l==len)
	{
		fg=1;
		for(i=1;i<ind;i++)
		{
			if(taken[i]==1&&fg)
			{
				printf("%s",ch[i]);
				fg=0;
			}
			else if(taken[i]==1&&!fg)
				printf(", %s",ch[i]);
		}
		puts("");
		return ;
	}
	for(i=ind;i<=n;i++)
	{
		if(taken[i]==0)
		{
			taken[i]=1;
			rec(i+1,l+1,len);
			taken[i]=0;
		}
	}
}

int main()
{
	long t,i;
	scanf("%ld",&t);
	while(getchar()!='\n');
	while(getchar()!='\n');
	while(t--)
	{
		gets(st);
		i=1;
		while(gets(ch[i]))
		{
			if(strcmp(ch[i],"")==0)
				break;
			i++;
		}
		n=i-1;
		fg1=1;
		fg=u=v=0;
		for(i=0;st[i];i++)
		{
			if(st[i]=='*')
			{
				fg=1;
				break;
			}
			else if(st[i]>=48&&st[i]<=57&&fg1==1)
			{
				while(st[i]>=48&&st[i]<=57&&st[i])
				{
					u=u*10+(st[i]-48);
					i++;
				}
				i--;
				fg1=0;
			}
			else if(st[i]>=48&&st[i]<=57&&fg1==0)
			{
				while(st[i]>=48&&st[i]<=57&&st[i])
				{
					v=v*10+(st[i]-48);
					i++;
				}
				i--;
			}
		}
		if(fg)
			u=1,v=n;
		else if(u&&v==0)
			u=u,v=u;
		for(i=u;i<=v;i++)
		{
			printf("Size %ld\n",i);
			rec(1,0,i);
			puts("");
		}
		if(t)
			printf("\n");
	}
	return 0;
}