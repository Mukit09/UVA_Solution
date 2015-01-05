#include<string.h>
#include<stdio.h>
#include<ctype.h>

char in[70];
char ch[1010][70];
long j=0,i,k,l,x,y,fg=0,a;

int main()
{
	while(gets(in))
	{
		if(!strcmp(in,"#"))
			break;
		l=strlen(in);
		a=0;
		if(fg)
		{
			for(a=0;in[a]!=32;a++)
			{
				if(isalpha(in[a])||in[a]==32)
					ch[j][k++]=in[a];
			}
			ch[j][k]=0;
			j++;
			k=fg=0;
		}
		
		if(in[l-1]=='-')
		{
			fg=1;
			y=k=l-2;
			while(in[k]!=32)
			{
				l--;
				k--;
			}
			k++;
			x=k;
			l--;
		}
		
		k=0;
		for(i=a;i<l;i++)
		{
			if(isalpha(in[i])||in[i]==32)
				ch[j][k++]=in[i];
		}
		ch[j][k]=0;
		j++;
		k=0;
		for(i=x;i<=y;i++)
		{
			if(isalpha(in[i])||in[i]==32)
				ch[j][k++]=in[i];
		}
	}
	for(i=0;i<j;i++)
		puts(ch[i]);
		
	return 0;
}
