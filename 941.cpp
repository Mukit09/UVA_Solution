#include<stdio.h>

int main()
{
	return 0;
}
/*
Giving TLE

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	char ch[25];

	long l,n,count,t;
	scanf("%ld",&t);
	while(t--)
	{
		count=0;
		scanf("%s",ch);
		l=strlen(ch);
		sort(ch,ch+l);
		scanf("%ld",&n);
		while(1)
		{
			count++;
			if(next_permutation(ch,ch+l)==0)
				break;
			if(count==n)
				break;
		}
		puts(ch);
	}
	return 0;
}

*/