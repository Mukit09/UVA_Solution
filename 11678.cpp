#include<stdio.h>
#include<map>
#define si 10010
using namespace std;
map<long,long>mpn,mpm;

int main()
{
	long n,m,i,cnt,inn[si],inm[si],non,nom;
	while(~scanf("%ld%ld",&n,&m)&&(n||m))
	{
		non=nom=cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&inn[i]);
			if(mpn[inn[i]]==0)
				non++;
			mpn[inn[i]]=1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld",&inm[i]);
			if(mpm[inm[i]]==0)
				nom++;
			mpm[inm[i]]=1;
		}
		if(non<nom)
		{
			for(i=1;i<=n;i++)
			{
				if(mpm[inn[i]]==0)
				{
					mpm[inn[i]]=1;
					cnt++;
				}
			}
		}
		else
		{
			for(i=1;i<=m;i++)
			{
				if(mpn[inm[i]]==0)
				{
					mpn[inm[i]]=1;
					cnt++;
				}
			}
		}
		printf("%ld\n",cnt);
		mpn.clear();
		mpm.clear();
	}
	return 0;
}