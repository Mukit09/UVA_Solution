#include<stdio.h>
#include<string.h>

long a[130],n,i,cnt,fg,cnt_lo,cnt_w;
char c;

int main()
{
	while(~scanf("%ld",&n))
	{
		if(n==-1)
			break;
		for(i=97;i<=122;i++)
			a[i]=0;
		getchar();
		cnt=0;
		while(c=getchar())
		{
			if(c=='\n')
				break;
			if(a[c]==0)
				cnt++;
			a[c]=1;
		}
		fg=cnt_w=cnt_lo=0;
		while(c=getchar())
		{
			if(c=='\n')
				break;
			if(a[c]==1)
				cnt_w++;
			else if(a[c]==0)
				cnt_lo++;
			a[c]=2;
			if(cnt_w==cnt&&cnt_lo<7)
				fg=1;
		}
		printf("Round %ld\n",n);
		if(fg)
			printf("You win.\n");
		else if(cnt_lo>=7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	return 0;
}
