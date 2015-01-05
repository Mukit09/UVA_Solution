/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1275 (10334 - Ray Through Glasses) */
/* SUBMISSION: 09572386 */
/* SUBMISSION TIME: 2011-12-18 15:52:05 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<string.h>

int main()
{
	char *fibo[1005]={0};
	fibo[0]="1";
	fibo[1]="2";
	int l1=strlen(fibo[0]);
	int l2=strlen(fibo[1]);
	long i,l;
	for(i=2;i<=1005;i++)
	{
		char str[10000];
		if(l1>=l2)
		{
			l=l1;
		}
		else
		{
			l=l2;
		}
		int ca=0;
		long j,k,m,p;
		for(j=l1-1,k=l2-1,m=0,p=0;p<l;j--,k--,m++,p++)
		{
			int s1;
			if(j<0)
			{
				fibo[i-2][j]='0';
			}
			s1=fibo[i-2][j]-48;
			int s2;
			if(k<0)
			{
				fibo[i-1][k]='0';
			}
			s2=fibo[i-1][k]-48;
			int ans=0;
			ans+=s1+s2+ca;
			if(ans>9)
			{
				str[m]=(ans-10)+48;
				ca=1;
			}
			else
			{
				str[m]=ans+48;
				ca=0;
			}
		}
		if(ca>0)
		{
			str[m]=ca+48;
			m++;
		}
		str[m]='\0';
		fibo[i]=new char[m+1];
		long y=0,x;
		for(x=m-1;x>=0;x--,y++)
		{
			fibo[i][y]=str[x];
		}
		fibo[i][y]='\0';
		l1=strlen(fibo[i-1]);
		l2=strlen(fibo[i]);
	}
	long n;
	while(scanf("%ld",&n)!=EOF)
	{
		printf("%s\n",fibo[n]);
	}

	return 0;
}