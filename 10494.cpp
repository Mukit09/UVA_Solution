#include<stdio.h>

#define M 100000

int main()
{
    long n,d,i,k;
    char num[M],ch[10005],c[2];

    while(gets(ch))
    {
		sscanf(ch,"%s%s%ld",num,c,&d);
        n=0;
        if(c[0]=='/')
        {
            i=0;
           
            while(n<d&&num[i])
			{
                n=n*10+(num[i]-48);
				i++;
			}
            if(n<d)
			{
				printf("0\n");
				continue;
			}
            printf("%ld",n/d);
            n=n%d;

            for(k=i;num[k];k++)
            {
                n=n*10+(num[k]-48);
                printf("%ld",n/d);
                n=n%d;
            }
            printf("\n");
		}
		else if(c[0]=='%')
		{
            for(i=0;num[i];i++)
            {
                n=n*10+(num[i]-48);
                n=n%d;
            }
            printf("%ld\n",n,d);
        }
    }
    return 0;
}
