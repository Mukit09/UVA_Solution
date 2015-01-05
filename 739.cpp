#include<stdio.h>
#include<string.h>

int main()
{
	char ch[50],re[50];
	long i,j;
	long a[150];
	for(i=65;i<=90;i++)
		a[i]=i;
	
	a['A']=a['E']=a['I']=a['O']=a['U']=a['Y']=a['W']=a['H']=48;
	a['B']=a['P']=a['F']=a['V']=49;
	a['C']=a['S']=a['K']=a['G']=a['J']=a['Q']=a['X']=a['Z']=50;
	a['D']=a['T']=51;
	a['L']=52;
	a['M']=a['N']=53;
	a['R']=54;

	printf("         NAME                     SOUNDEX CODE\n");

	while(gets(ch))
	{
		j=1;
		re[0]=ch[0];
		for(i=1;ch[i];i++)
		{
			if(ch[i]=='A'||ch[i]=='E'||ch[i]=='I'||ch[i]=='O'||ch[i]=='U'||ch[i]=='Y'||ch[i]=='W'||ch[i]=='H')
			{
				;
			}	
			else if(a[ch[i-1]]!=a[ch[i]])
			{
				re[j++]=a[ch[i]];
			}
			if(j==4)
				break;
		}
		for(i=j;i<4;i++)
			re[i]=48;
		re[i]='\0';
		for(i=1;i<=9;i++)
			printf(" ");
		for(i=0;ch[i];i++)
			printf("%c",ch[i]);
		for(j=1;j<=34-(i+9);j++)
			printf(" ");
		puts(re);

	}
	printf("                   END OF OUTPUT\n");
	return 0;
}


