#include<stdio.h>
#include<string.h>

char ch[110],s2[110],s3[110],s4[110],s5[110];
long i,j,l,n;

int main()
{
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		gets(ch);
		if(!strcmp(ch,""))
			gets(ch);
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			if(ch[i]!='<'&&ch[i]!='>')
				printf("%c",ch[i]);
		}
		printf("\n");
		j=i=0;
		while(ch[i]!='<')
		{
			i++;
			j++;
		}
		i++;
		j=0;
		while(ch[i]!='>')
			s2[j++]=ch[i++];
		i++;
		s2[j]=0;
		j=0;
		while(ch[i]!='<')
			s3[j++]=ch[i++];
		i++;
		s3[j]=0;
		j=0;
		while(ch[i]!='>')
			s4[j++]=ch[i++];
		i++;
		s4[j]=0;
		j=0;
		while(ch[i])
			s5[j++]=ch[i++];
		s5[j]=0;
		gets(ch);
		if(!strcmp(ch,""))
			gets(ch);
		l=strlen(ch);
		i=l-1;
		while(ch[i]=='.')
		{
			i--;
			l--;
		}
		for(i=0;i<l;i++)
			printf("%c",ch[i]);
		printf("%s%s%s%s\n",s4,s3,s2,s5);
	}
	return 0;
}