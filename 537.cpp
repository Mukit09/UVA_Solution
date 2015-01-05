#include<stdio.h>
#include<string.h>

int main()
{
	long i,j,t,k=1;
	char ch[1000],ch1[50],c1,c2;
	double p,q;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch);
		i=0;
		while(ch[i]!='=')
		{
			i++;
		}
		j=0;
		c1=ch[i-1];
		i++;
		while((ch[i]<='9'&&ch[i]>='0')||ch[i]=='.')
		{
			ch1[j++]=ch[i++];
		}
		ch1[j]='\0';
		sscanf(ch1,"%lf",&p);
		if(ch[i]=='m')
		{
			p/=1000;
		}
		else if(ch[i]=='M')
		{
			p*=1000000;
		}
		else if(ch[i]=='k')
		{
			p*=1000;
		}

		while(ch[i]!='=')
		{
			i++;
		}
		j=0;
		c2=ch[i-1];
		i++;
		while((ch[i]<='9'&&ch[i]>='0')||ch[i]=='.')
		{
			ch1[j++]=ch[i++];
		}
		ch1[j]=0;
		sscanf(ch1,"%lf",&q);
		if(ch[i]=='m')
		{
			q/=1000;
		}
		else if(ch[i]=='M')
		{
			q*=1000000;
		}
		else if(ch[i]=='k')
		{
			q*=1000;
		}

		if(c1=='U'&&c2=='I')
		{
			printf("Problem #%ld\nP=%.2lfW\n\n",k++,p*q);
		}
		else if(c1=='I'&&c2=='U')
		{
			printf("Problem #%ld\nP=%.2lfW\n\n",k++,p*q);
		}
		else if(c1=='P'&&c2=='U')
		{
			printf("Problem #%ld\nI=%.2lfA\n\n",k++,p/q);
		}
		else if(c1=='U'&&c2=='P')
		{
			printf("Problem #%ld\nI=%.2lfA\n\n",k++,q/p);
		}
		else if(c1=='P'&&c2=='I')
		{
			printf("Problem #%ld\nU=%.2lfV\n\n",k++,p/q);
		}
		else if(c1=='I'&&c2=='P')
		{
			printf("Problem #%ld\nU=%.2lfV\n\n",k++,q/p);
		}
	}
	return 0;
}