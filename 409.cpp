#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;
map<string,long>mp;

char ch[30][80],st[30];

int main()
{
	long i,k,j,a[30],e,max,l,t=1;
	while(~scanf("%ld%ld",&k,&e))
	{
		while(k--)
		{
			scanf("%s",st);
			mp[st]=1;
		}
		getchar();
		j=1;max=0;
		while(e--)
		{
			a[j]=0;
			gets(ch[j]);
			l=strlen(ch[j]);
			for(i=0;i<l;i++)
			{
				k=0;
				while(isalpha(ch[j][i]))
				{
					if(ch[j][i]<97)
						st[k++]=ch[j][i++]+32;
					else
						st[k++]=ch[j][i++];
				}
				st[k]=0;
				if(mp[st])
				{
					a[j]++;
					if(max<a[j])
						max=a[j];
				}
			}
			j++;
		}
		printf("Excuse Set #%ld\n",t++);
		for(i=1;i<j;i++)
		{
			if(a[i]==max)
				puts(ch[i]);
		}
		printf("\n");
		mp.clear();
	}
	return 0;
}