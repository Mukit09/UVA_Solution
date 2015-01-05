#include <stdio.h>

long m,n,a[15],sm;
char word[110][270],rule[1005][270];

void rec(long m,long n,long cnt) 
{
	long i,j;
	if(cnt==sm) 
	{
	    for(j=0,i=0;rule[m][i];i++) 
		{
	        if (rule[m][i]=='0')
	            printf("%c",48+a[j++]);
	        else
	            printf("%s",word[n]);
	    }
	    puts("");
	} 
	else
	{
	    for(i=0;i<10;i++) 
		{
	        a[cnt]=i;
	        rec(m,n,cnt+1);
	    }
	}
}

int main()
{
	long i,j;
	while(~scanf("%ld",&n)) 
	{
	    for(i=0;i<n;i++)
	        scanf("%s",word[i]);
	    scanf("%ld",&m);
	    for(i=0;i<m;i++)
		{
	        scanf("%s",rule[i]);
	        sm=0;
	        for(j=0;rule[i][j];j++)
			{
				if(rule[i][j]==48)
					sm++;
			}
	        printf("--\n");
	        for(j=0;j<n;j++)
	            rec(i,j,0);
	    }
	}
	return 0;
}