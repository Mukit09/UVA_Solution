#include<stdio.h>
#include<map>

using namespace std;
long a[100000];

map<long,long>mp;

int main()
{
	long n,k,i=0;
	while(scanf("%ld",&n)==1)
	{
		mp[n]++;
		a[i++]=n;
	}
	for(k=0;k<i;k++)
	{
		if(mp[a[k]])
		{
			printf("%ld %ld\n",a[k],mp[a[k]]);
			mp[a[k]]=0;
		}
	}
	return 0;
}

