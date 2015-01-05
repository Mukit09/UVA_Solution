#include<stdio.h>
#include<string.h>

char ch[100],st1[40],st2[40];
long l,fg=0;

int main()
{
	while(gets(ch))
	{
		sscanf(ch,"%s%s",st1,st2);
		if(fg)
			printf("\n");
		else fg=1;
		printf("%s (to %s)\n",st1,st2);
		l=strlen(st1);
		ch[0]=st1[l-2];
		ch[1]=st1[l-1];
		ch[2]=0;
		l=l-2;
		st1[l]=0;
		if(!strcmp(ch,"ar"))
		{
			printf("eu        %so\n",st1);
			printf("tu        %sas\n",st1);
			printf("ele/ela   %sa\n",st1);
			printf("n%cs       %samos\n",243,st1);
			printf("v%cs       %sais\n",243,st1);
			printf("eles/elas %sam\n",st1);
		}	
		else if(!strcmp(ch,"er"))
		{
			printf("eu        %so\n",st1);
			printf("tu        %ses\n",st1);
			printf("ele/ela   %se\n",st1);
			printf("n%cs       %semos\n",243,st1);
			printf("v%cs       %seis\n",243,st1);
			printf("eles/elas %sem\n",st1);
		}
		else if(!strcmp(ch,"ir"))
		{
			printf("eu        %so\n",st1);
			printf("tu        %ses\n",st1);
			printf("ele/ela   %se\n",st1);
			printf("n%cs       %simos\n",243,st1);
			printf("v%cs       %sis\n",243,st1);
			printf("eles/elas %sem\n",st1);
		}
		else
			printf("Unknown conjugation\n");
	}
	return 0;
}