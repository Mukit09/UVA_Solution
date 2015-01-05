#include<stdio.h>
#include<string.h>
int main()
{
	char ch[70][70],in[70],side[]={'N','E','S','W'};
	long i,j,p,k,ln,t,r,c;
	long fg;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&r,&c);
		getchar();

		for(i=0;i<r;i++)
			gets(ch[i]);

		scanf("%ld%ld",&i,&j);
		getchar();
		i--; j--;
		fg=0;
		p=0;
		while(~scanf("%s",in))
		{
			ln=strlen(in);
			for(k=0;k<ln;k++)
			{
				if(in[k]=='Q')
				{
					fg=1;
					break;
				}
				if(in[k]=='R')
				{
					p++;
					p=p%4;
				}
				else if(in[k]=='L')
				{
					p--;
					if(p<0)
						p=4+p;
				}
				else if(in[k]=='F')
				{
					if(p==0)
					{
						if(i>0 && ch[i-1][j]!='*')
							i--;
					}
					else if(p==1)
					{
						if(j<c-1 && ch[i][j+1]!='*')
							j++;
					}
					else if(p==2)
					{
						if(i<r-1 && ch[i+1][j]!='*')
							i++;
					}
					else
					{
						if(j>0 && ch[i][j-1]!='*')
							j--;
					}
				}
			}
			if(fg)
				break;
		}
		printf("%ld %ld %c\n",i+1,j+1,side[p]);
	
		if(t)
			printf("\n");
	}
	return 0;
}