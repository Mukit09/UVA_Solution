#include<stdio.h>
#include<string.h>

char ch[110],ch1[110],ch2[110];
long long bin[55][55];

int main()
{
	long long t,l,i,j,fg,n,a,b,c,r,x=1;
	 for(i=0;i<51;i++)
        bin[i][0]=bin[i][i]=1;

    for(i=2;i<51;i++)
	{
        for(j=0;j<=i;j++)
            bin[i][j]=bin[i-1][j-1]+bin[i-1][j];
	}

	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		fg=1;j=0;
		for(i=1;i<l;i++)
		{
			if(fg&&ch[i]>=97&&ch[i]<=122)
			{
				while(ch[i]>=97&&ch[i]<=122)
				{
					ch1[j]=ch[i];
					i++,j++;
				}
				ch1[j]=0;
				i--;
				fg=j=0;
			}
			else if(!fg&&ch[i]>=97&&ch[i]<=122)
			{
				while(ch[i]>=97&&ch[i]<=122)
				{
					ch2[j]=ch[i];
					i++,j++;
				}
				ch2[j]=0;
				i--;
				fg=j=0;
			}
			else if(ch[i]>=48&&ch[i]<=57)
			{
				n=0;
				while(ch[i]>=48&&ch[i]<=57)
				{
					n=n*10+ch[i]-48;
					i++;
				}
				i--;
			}
		}
		printf("Case %lld: ",x++);
		j=n,r=0;
		while(1)
		{
			if(j==n)
			{
				if(j>1)
					printf("%s^%lld",ch1,j);
				else
					printf("%s",ch1);
			}
			else if(r==n)
			{
				if(r>1)
					printf("+%s^%lld",ch2,r);
				else
					printf("+%s",ch2);
			}
			else if(j>1&&r>1)
				printf("+%lld*%s^%lld*%s^%lld",bin[n][r],ch1,j,ch2,r);
			else if(j>1&&r==1)
				printf("+%lld*%s^%lld*%s",bin[n][r],ch1,j,ch2);
			else if(j==1&&r>1)
				printf("+%lld*%s*%s^%lld",bin[n][r],ch1,ch2,r);
			else if(j==1&&r==1)
				printf("+%lld*%s*%s",bin[n][r],ch1,ch2);
			if(r==n)
				break;
			j--;
			r++;
		}
		puts("");
	}
	return 0;
}
