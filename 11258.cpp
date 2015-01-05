#include<stdio.h>
#include<string.h>

long long i,j,l,limit,max[210],num,t;
char ch[210];

int main()
{
	limit=2147483647;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0;i<=l;i++)
			max[i]=0;
		for(i=0;i<l;i++)
		{
			num=0;
			for(j=i;j<l;j++)
			{
				num=num*10+(ch[j]-48);
				if(num>limit)
					break;
				if(num+max[i]>max[j+1])
					max[j+1]=num+max[i];
				if(i==j&&ch[j]=='0')
					break;
			}
		}
		printf("%lld\n",max[l]);
	}
	return 0;
}