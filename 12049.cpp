#include<stdio.h>
#include<map>
#define min(a,b) (a<b ?a:b)
#define si 10010
using namespace std;
map<long,long>mp1,mp2,mp3;
long a1[si],a2[si],t,n,m,i,cnt;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a1[i]);
			mp1[a1[i]]++;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld",&a2[i]);
			mp2[a2[i]]++;
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(mp3[a1[i]]==0)
			{
				cnt+=2*(min(mp1[a1[i]],mp2[a1[i]]));
				mp3[a1[i]]=1;
			}
		}
		printf("%ld\n",n+m-cnt);
		mp1.clear();
		mp2.clear();
		mp3.clear();
	}
	return 0;
}