#include<stdio.h>
#include<string.h>
#define si 10010

char ch[si][30];
long s[si],b[si],t,n,q,cnt,fg,ans,i,tk;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%s%ld%ld",ch[i],&s[i],&b[i]);
		scanf("%ld",&q);
		while(q--)
		{
			scanf("%ld",&tk);
			cnt=fg=0;
			for(i=1;i<=n;i++)
			{
				if(s[i]<=tk&&b[i]>=tk)
				{
					fg=1;
					ans=i;
					cnt++;
				}
				if(cnt==2)
					break;
			}
			if(fg&&cnt==1)
				printf("%s\n",ch[ans]);
			else
				printf("UNDETERMINED\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}