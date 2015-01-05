/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 3402 (12250 - Language Detection) */
/* SUBMISSION: 09481942 */
/* SUBMISSION TIME: 2011-11-18 04:13:02 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

int main()
{
	char ch1[20]="HELLO",
	ch2[20]="HOLA",
	ch3[20]="HALLO",
	ch4[20]="BONJOUR",
	ch5[20]="CIAO",
	ch6[20]="ZDRAVSTVUJTE",
	ch[20];
	long i=0,a;
	while(gets(ch))
	{
		if(ch[0]=='#'&&ch[1]=='\0')
			break;
		i++;
		a=strcmp(ch,ch1);
		if(a==0)
		{
			printf("Case %ld: ENGLISH\n",i);
			continue;
		}
		a=strcmp(ch,ch2);
		if(a==0)
		{
			printf("Case %ld: SPANISH\n",i);
			continue;
		}
		a=strcmp(ch,ch3);
		if(a==0)
		{
			printf("Case %ld: GERMAN\n",i);
			continue;
		}
		a=strcmp(ch,ch4);
		if(a==0)
		{
			printf("Case %ld: FRENCH\n",i);
			continue;
		}
		a=strcmp(ch,ch5);
		if(a==0)
		{
			printf("Case %ld: ITALIAN\n",i);
			continue;
		}
		a=strcmp(ch,ch6);
		if(a==0)
		{
			printf("Case %ld: RUSSIAN\n",i);
			continue;
		}
		if(a!=0)
		{
			printf("Case %ld: UNKNOWN\n",i);
		}
	}
	return 0;
}