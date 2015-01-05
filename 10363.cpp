#include<stdio.h>
#include<string.h>

int main()
{
	long i,j,t,flagx,flago,x,o,d;
	char ch[5][5];
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		for(i=0;i<3;i++)
			scanf("%s",ch[i]);
		flagx=flago=x=o=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(ch[i][j]=='X')
					x++;
				else if(ch[i][j]=='O')
					o++;
			}
		}

		if(ch[0][0]=='X'&&ch[0][1]=='X'&&ch[0][2]=='X')
			flagx=1;
		if(ch[0][0]=='O'&&ch[0][1]=='O'&&ch[0][2]=='O')
			flago=1;
		if(ch[0][0]=='X'&&ch[1][0]=='X'&&ch[2][0]=='X')
			flagx=1;
		if(ch[0][0]=='O'&&ch[1][0]=='O'&&ch[2][0]=='O')
			flago=1;
		if(ch[2][0]=='X'&&ch[2][1]=='X'&&ch[2][2]=='X')
			flagx=1;
		if(ch[2][0]=='O'&&ch[2][1]=='O'&&ch[2][2]=='O')
			flago=1;
		if(ch[0][2]=='X'&&ch[1][2]=='X'&&ch[2][2]=='X')
			flagx=1;
		if(ch[0][2]=='O'&&ch[1][2]=='O'&&ch[2][2]=='O')
			flago=1;
		if(ch[0][0]=='X'&&ch[1][1]=='X'&&ch[2][2]=='X')
			flagx=1;
		if(ch[0][0]=='O'&&ch[1][1]=='O'&&ch[2][2]=='O')
			flago=1;
		if(ch[0][2]=='X'&&ch[1][1]=='X'&&ch[2][0]=='X')
			flagx=1;
		if(ch[0][2]=='O'&&ch[1][1]=='O'&&ch[2][0]=='O')
			flago=1;
		if(ch[0][1]=='X'&&ch[1][1]=='X'&&ch[2][1]=='X')
			flagx=1;
		if(ch[0][1]=='O'&&ch[1][1]=='O'&&ch[2][1]=='O')
			flago=1;
		if(ch[1][0]=='X'&&ch[1][1]=='X'&&ch[1][2]=='X')
			flagx=1;
		if(ch[1][0]=='O'&&ch[1][1]=='O'&&ch[1][2]=='O')
			flago=1;	

		d=x-o;
		if(d<0)
			d=-d;
		if((flagx==1&&flago==1)||(flago==1&&flagx==0&&d>0)||(flago==0&&flagx==1&&d==0)||d>1||o>x)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}