#include<stdio.h>
#include<string.h>

int main()
{
	char a[101][110];
	int len[110],i=0,j,ln,mxlen=0;
	while(gets(a[i]))
	{
		len[i]=strlen(a[i]);
		if(mxlen<len[i])
			mxlen=len[i];
		i++;
	}
	ln=i-1;
	for(i=0;i<mxlen;i++)
	{
		for(j=ln;j>=0;j--)
		{
			if(len[j]<=i)
				printf(" ");
			else
				printf("%c",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}