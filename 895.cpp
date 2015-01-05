#include<stdio.h>
#include<string.h>
#include<ctype.h>

char ch[15];
long i,j,k,cnt,fg;
long a[1010][150],chk[150];

int main()
{
	for(i=1;i<=1010;i++)
	{
		for(j=96;j<=127;j++)
			a[i][j]=0;
	}

	j=1;
	while(gets(ch))
	{
		if(!strcmp(ch,"#"))
			break;
			

		for(i=0;ch[i];i++)
		{
			a[j][ch[i]]++;
		}
		j++;
	}
	while(gets(ch))
	{
		if(!strcmp(ch,"#"))
			break;
		cnt=0;
		for(i=96;i<=125;i++)
			chk[i]=0;
		for(i=0;ch[i];i++)
		{
			if(isalpha(ch[i]))
				chk[ch[i]]++;
		}
		for(k=1;k<j;k++)
		{
			fg=1;
			for(i=97;i<=122;i++)
			{
				if(a[k][i]&&a[k][i]>chk[i])
					fg=0;
			}
			if(fg)
				cnt++;
		}
		printf("%ld\n",cnt);
	}
	return 0;
}