#include<stdio.h>
#include<algorithm>
using namespace std;

long n,m,i,j,k;
double fa[110],ra[110],mx,s,res[10010];

int main()
{
	while(~scanf("%ld",&m)&&m)
	{
		scanf("%ld",&n);
		for(i=0;i<m;i++)
			scanf("%ld",&fa[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&ra[i]);
		k=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				res[k++]=ra[j]/fa[i];
		}
		sort(res,res+k);
		mx=0;
		for(i=1;i<k;i++)
		{
			s=res[i]/res[i-1];
			if(s>mx)
				mx=s;
		}
		printf("%.2lf\n",mx);
	}
	return 0;
}