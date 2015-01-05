#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long p,q,r,s,i,j,k;
double ans,num[10010],numm[10010];
int main()
{
	while(~scanf("%ld%ld%ld%ld",&p,&q,&r,&s))
	{
		j=k=0;
		for(i=q+1;i<=p;i++)
			num[j++]=i;
		for(i=s+1;i<=r;i++)
			numm[k++]=i;
		if(p-q>r-s)
		{
			for(i=r-s+1;i<=p-q;i++)
				numm[k++]=i;
		}
		else
		{
			for(i=p-q+1;i<=r-s;i++)
				num[j++]=i;
		}
		sort(num,num+j);
		sort(numm,numm+k);
		ans=1;
		for(i=0;i<j||i<k;i++)
		{
			ans*=(num[i]/numm[i]);
		}
		printf("%.05lf\n",ans);
	}
	return 0;
}