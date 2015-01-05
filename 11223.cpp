#include<stdio.h>
#include<string.h>

int main()
{
	char ch[100000],re[100000],c;
	long l,i,j,k=1,t,count;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch);
		l=strlen(ch);

		printf("Message #%ld\n",k++);
		for(i=0;i<l;i++)
		{
			j=0;
			count=0;
			while(ch[i]!=32)
			{
				re[j++]=ch[i++];
			}
			re[j]=0;
			if(strcmp(re,".-")==0)
				printf("A");
			else if(strcmp(re,"-...")==0)
				printf("B");
			else if(strcmp(re,"-.-.")==0)
				printf("C");
			else if(strcmp(re,"-..")==0)
				printf("D");
			else if(strcmp(re,".")==0)
				printf("E");
			else if(strcmp(re,"..-.")==0)
				printf("F");
			else if(strcmp(re,"--.")==0)
				printf("G");
			else if(strcmp(re,"....")==0)
				printf("H");
			else if(strcmp(re,"..")==0)
				printf("I");
			else if(strcmp(re,".---")==0)
				printf("J");
			else if(strcmp(re,"-.-")==0)
				printf("K");
			else if(strcmp(re,".-..")==0)
				printf("L");
			else if(strcmp(re,"--")==0)
				printf("M");
			else if(strcmp(re,"-.")==0)
				printf("N");
			else if(strcmp(re,"---")==0)
				printf("O");
			else if(strcmp(re,".--.")==0)
				printf("P");
			else if(strcmp(re,"--.-")==0)
				printf("Q");
			else if(strcmp(re,".-.")==0)
				printf("R");
			else if(strcmp(re,"...")==0)
				printf("S");
			else if(strcmp(re,"-")==0)
				printf("T");
			else if(strcmp(re,"..-")==0)
				printf("U");
			else if(strcmp(re,"...-")==0)
				printf("V");
			else if(strcmp(re,".--")==0)
				printf("W");
			else if(strcmp(re,"-..-")==0)
				printf("X");
			else if(strcmp(re,"-.--")==0)
				printf("Y");
			else if(strcmp(re,"--..")==0)
				printf("Z");
			else if(strcmp(re,"-----")==0)
				printf("0");
			else if(strcmp(re,".----")==0)
				printf("1");
			else if(strcmp(re,"..---")==0)
				printf("2");
			else if(strcmp(re,"...--")==0)
				printf("3");
			else if(strcmp(re,"....-")==0)
				printf("4");
			else if(strcmp(re,".....")==0)
				printf("5");
			else if(strcmp(re,"-....")==0)
				printf("6");
			else if(strcmp(re,"--...")==0)
				printf("7");
			else if(strcmp(re,"---..")==0)
				printf("8");
			else if(strcmp(re,"----.")==0)
				printf("9");
			else if(strcmp(re,".-.-.-")==0)
				printf(".");
			else if(strcmp(re,"--..--")==0)
				printf(",");
			else if(strcmp(re,"..--..")==0)
				printf("?");
			else if(strcmp(re,".----.")==0)
				printf("'");
			else if(strcmp(re,"-.-.--")==0)
				printf("!");
			else if(strcmp(re,"-..-.")==0)
				printf("/");
			else if(strcmp(re,"-.--.")==0)
				printf("(");
			else if(strcmp(re,"-.--.-")==0)
				printf(")");
			else if(strcmp(re,".-...")==0)
				printf("&");
			else if(strcmp(re,"---...")==0)
				printf(":");
			else if(strcmp(re,"-.-.-.")==0)
				printf(";");
			else if(strcmp(re,"-...-")==0)
				printf("=");
			else if(strcmp(re,".-.-.")==0)
				printf("+");
			else if(strcmp(re,"-....-")==0)
				printf("-");
			else if(strcmp(re,"..--.-")==0)
				printf("_");
			else if(strcmp(re,".-..-.")==0)
			{
				c='"';
				printf("%c",c);
			}
			else if(strcmp(re,".--.-.")==0)
				printf("@");

			while(ch[i]==' ')
			{
				count++;
				i++;
			}
			if(count==2)
			{
				printf(" ");
			}
			i--;
		}
		printf("\n");
		if(t)
			printf("\n");
	}
	return 0;
}