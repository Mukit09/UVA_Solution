#include<stdio.h>
#include<string.h>

int main()
{
	char ch[3000][1010],re[1010],cc[1010];
	long n,m,i,j,k;
	while(~scanf("%ld%ld",&n,&m))
	{
		scanf("%s",re);
		j=1;
		strcpy(ch[0],re);
		while(j<n)
		{
			k=0;
			scanf("%s",cc);
			for(i=0;i<m;i++)
			{
				if(re[i]!=cc[i])
					k++;
			}
			strcpy(ch[k],cc);
			j++;
		}
		for(i=0;i<n;i++)
		{
			puts(ch[i]);
		}
	}
	return 0;
}