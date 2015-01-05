#include<stdio.h>
#include<string.h>

long x,y,z,e,m,i,fg,flag,t;
char ch[60];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		m=e=x=y=z=flag=fg=0;
		for(i=0;ch[i];i++)
		{
			if(fg==0&&ch[i]=='?')
				x++;
			else if(fg==1&&ch[i]=='?')
				y++;
			else if(fg==2&&ch[i]=='?')
				z++;
			if(ch[i]=='M'&&fg==0)
				fg=1;
			if(ch[i]=='M')
				m++;
			if(ch[i]=='E'&&fg==1)
				fg=2;
			if(ch[i]=='E')
				e++;
			if(ch[i]!='M'&&ch[i]!='E'&&ch[i]!='?')
			{
				flag=1;
				break;
			}
		}
		if(x==0||y==0||z==0)
			flag=1;
		else if((x+y)!=z)
			flag=1;
		else if(m>1||e>1)
			flag=1;
		if(flag)
			printf("no-theorem\n");
		else
			printf("theorem\n");
	}
	return 0;
}