#include<stdio.h>
#include<algorithm>
using namespace std;

long n,i,a[500010],b[500010],fg;

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%ld%ld",&a[i],&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		fg=0;
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				fg=1;
				break;
			}
		}
		if(!fg)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}