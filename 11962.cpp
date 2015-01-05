#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	long i,j,l,t,k=1;
	long double re;
	char ch[40];
	long a[100];
	a['A']=0;
	a['C']=1;
	a['G']=2;
	a['T']=3;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		l=strlen(ch);
		re=0;
		j=l-1;
		for(i=0;i<l;i++)
		{
			re=re+a[ch[i]]*pow(4,j);
			j--;
		}
		printf("Case %ld: (%ld:%.0llf)\n",k++,l,re);
	}
	return 0;
}